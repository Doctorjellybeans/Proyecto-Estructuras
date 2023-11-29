#ifndef LIST_H
#define LIST_H

#include <ctype.h>

template <typename T>
class List
{
public:

    List();
    ~List();

    T* first();
    T* last();

    T* next();
    T* prev(); 
    T* current();

    T* search(T data);

    void pushFront(T* data);
    void pushBack(T* data);
    void pushCurrent(T* data);

    T* popFront();
    T* popBack();
    T* popCurrent();

    bool empty() { return this->_head == nullptr; }

    void clean();
    size_t size() { return this->_size; }

private:

    template <typename K>
    struct Node
    {
        Node(K value) : _data(value), _next(nullptr), _prev(nullptr) {}

        K _data;
        Node<K>* _next;
        Node<K>* _prev;
    };

    Node<T*>* _current;
    Node<T*>* _head;
    Node<T*>* _tail;

    size_t _size = 0;
};

template <typename T>
List<T>::List()
    : _current(nullptr), _head(nullptr), _tail(nullptr)
{

}

template <typename T>
List<T>::~List()
{
    clean();
}

template <typename T>
T* List<T>::first()
{
    if (this->_head == nullptr)
        return nullptr;

    this->_current = this->_head;
    return this->_current->_data;
}

template <typename T>
T* List<T>::last()
{
    if (this->_tail == nullptr)
        return nullptr;

    this->_current = this->_tail;
    return this->_current->_data;
}

template <typename T>
T* List<T>::next()
{
    if (this->_current == nullptr)
        return nullptr;

    this->_current = this->_current->_next;
    if (this->_current == nullptr)
      return nullptr;

    return this->_current->_data;
}

template <typename T>
T* List<T>::prev()
{
    if (this->_current == nullptr)
        return nullptr;

    this->_current = this->_current->_prev;
    if (this->_current == nullptr)
      return nullptr;

    return this->_current->_data;
}

template <typename T>
T* List<T>::current()
{
    if (this->_current == nullptr)
        return nullptr;

    return this->_current->_data;
}

template <typename T>
void List<T>::pushFront(T* data)
{
    Node<T*>* node = new Node<T*>(data);

    if (empty())
    {
        this->_head = node;
        this->_tail = node;

        return;
    }

    this->_head->_prev = node;
    node->_next = this->_head;

    this->_head = node;

    this->_size++;
}

template <typename T>
void List<T>::pushBack(T* data)
{
    Node<T*>* node = new Node<T*>(data);

    if (empty())
    {
        this->_head = node;
        this->_tail = node;

        return;
    }

    this->_tail->_next = node;
    node->_prev = this->_tail;

    this->_tail = node;

    this->_size++;
}

template <typename T>
void List<T>::pushCurrent(T* data)
{
    if (data == nullptr || this->_current == nullptr)
      return;

    Node<T*>* node = new Node<T*>(data);

    if (empty())
    {
        this->_head = node;
        this->_tail = node;

        return;
    }

    node->_prev = this->_current;

    if (this->_current->_next != nullptr)
    {
        node->_next = this->_current->_next;
        this->_current->_next->_prev = node;
    }
    else
    {
        this->_tail = node;
    }

    this->_current->_next = node;
    this->_size++;
}

template <typename T>
T* List<T>::popFront()
{
    if (this->_head == nullptr)
        return nullptr;

    Node<T*>* node = this->_head;

    this->_head = this->_head->_next;

    if (this->_head != nullptr)
        this->_head->_prev = nullptr;

    this->_current = this->_head;

    T* data = node->_data;
    delete node;

    this->_size--;

    return data;
}

template <typename T>
T* List<T>::popBack()
{
    if (this->_head == nullptr)
        return nullptr;

    Node<T*>* node = this->_tail;

    this->_tail = this->_tail->_prev;

    if (this->_tail != nullptr)
        this->_tail->_next = nullptr;

    this->_current = this->_tail;

    T* data = node->_data;
    delete node;

    this->_size--;

    return data;
}

template <typename T>
T* List<T>::popCurrent()
{
    if (this->_current == nullptr)
        return nullptr;

    if (this->_current->_next == nullptr)
        return popBack();

    if (this->_current->_prev == nullptr)
        return popFront();

    Node<T*>* node = this->_current;
  
    node->_prev->_next = node->_next;
    node->_next->_prev = node->_prev;

    this->_current = node->_next;

    T* data = node->_data;
    delete node;

    this->_size--;

    return data;
}

template <typename T>
T* List<T>::search(T data)
{
    T* ptr = first();
    while (ptr != nullptr)
    {
        if (*ptr == data)
            return ptr;

        ptr = next();
    }
    
    return nullptr;
}

template <typename T>
void List<T>::clean()
{
    while (!empty())
    {
        Node<T*>* node = this->_head;
        this->_head = this->_head->_next;
        delete node;
        this->_size--;
    }

    this->_current = nullptr;
    this->_tail = nullptr;
}

#endif //LIST_H