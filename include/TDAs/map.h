#ifndef MAP_H
#define MAP_H

#include "TDAs/list.h"
#include <ctype.h>

template <typename T1, typename T2>
struct Pair
{
    Pair(T1 key, T2 value) : key(key), value(value) {}
    ~Pair() = default;

    T1 key;
    T2 value;
};

// Le añade un signifacado al operador '==' para Pair
template <typename T1, typename T2>
inline bool operator==(const Pair<T1, T2>& left, const Pair<T1, T2>& right)
{
    return (left.key == right.key) && (left.value == right.value);
}

// Mapa no-ordenado
template <typename T1, typename T2>
class Map
{
public:

    Map();
    ~Map();

    using _Pair = Pair<T1, T2*>;

    void insert(T1 key, T2* value);
    void insert(T1 key, T2 value) { insert(key, new T2(value)); }
    void erase(T1 key);

    T2* search(T1 key);
    T2* first();
    T2* next();

private:

    void enlarge();

    size_t size;
    size_t capacity;
    size_t current;
    List<_Pair>* buckets;

    size_t hash(T1 key)
    {
        size_t hash = 0;
        unsigned char* ptr;

        for (ptr = (unsigned char*)(&key); *ptr != '\0'; ptr++)
            hash += hash * 32 + tolower(*ptr);

        return hash % this->capacity;
    }
};

template <typename T1, typename T2>
Map<T1, T2>::Map()
    : size(0), capacity(2), current(-1)
{
    this->buckets = new List<_Pair>[this->capacity];
}

template <typename T1, typename T2>
Map<T1, T2>::~Map()
{
    for (size_t i = 0; i < this->capacity; i++)
    {
        List<_Pair>& list = this->buckets[i];

        while (!list.empty())
        {
            _Pair* pair = list.popFront();

            if (pair != nullptr)
                delete pair;
        }
    }

    delete[] this->buckets;
}


template <typename T1, typename T2>
void Map<T1, T2>::insert(T1 key, T2* value)
{
    size_t pos = hash(key);
    List<_Pair>& list = this->buckets[pos];

    _Pair* ptr = list.first();
    while (ptr != nullptr)
    {
        if (ptr->key == key)
        {
            ptr->value = value;
            return;
        }

        ptr = list.next();
    }

    // Nuevo 'Pair'
    _Pair* pair = new _Pair(key, value);
    list.pushBack(pair);

    this->size++;

    // Agranda el mapa, si es nesecesario
    float cap70 = this->capacity * 0.7;
    if (this->size >= cap70)
        enlarge();

    return;
}

template <typename T1, typename T2>
void Map<T1, T2>::erase(T1 key)
{
    size_t pos = hash(key);
    List<_Pair>& list = this->buckets[pos];

    _Pair* ptr = list.first();
    while (ptr != nullptr)
    {
        if (ptr->key == key)
        {
            list.popCurrent();
            delete ptr;

            this->size--;
            return;
        }

        ptr = list.next();
    }
}

template <typename T1, typename T2>
T2* Map<T1, T2>::search(T1 key)
{
    size_t pos = hash(key);
    List<_Pair>& list = this->buckets[pos];

    _Pair* ptr = list.first();
    while (ptr != nullptr)
    {
        if (ptr->key == key)
            return ptr->value;

        ptr = list.next();
    }

    return nullptr;
}

template <typename T1, typename T2>
T2* Map<T1, T2>::first()
{
    this->current = 0;
    while (this->current < this->capacity && buckets[current].empty())
        current++;

    if (this->current < this->capacity)
        return buckets[current].first()->value;

    return nullptr;
}


template <typename T1, typename T2>
T2* Map<T1, T2>::next()
{
    if (this->current == this->capacity - 1)
        return nullptr;

    current++;
    while (this->current < this->capacity && buckets[current].empty())
        current++;

    if (this->current < this->capacity)
        return buckets[current].first()->value;

    return nullptr;
}

template <typename T1, typename T2>
void Map<T1, T2>::enlarge()
{
    List<_Pair>* oldBuckets = this->buckets;
    size_t oldCapacity = this->capacity;

    this->size = 0;
    this->capacity *= 2;

    this->buckets = new List<_Pair>[this->capacity];

    for (size_t i = 0; i < oldCapacity; i++)
    {
        List<_Pair>& list = oldBuckets[i];

        while (!list.empty())
        {
            _Pair* pair = list.popFront();

            if (pair != nullptr)
            {
                insert(pair->key, pair->value);
                delete pair;
            }
        }
        
    }

    delete[] oldBuckets;
}

#endif //MAP_H