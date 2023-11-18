#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {

public:

    Queue() = default;
    ~Queue();

    void top();
    void push(T& element);
    void pop();

    bool empty() { return this->back == nullptr; }

private:

    struct Node {
        Node(const T& data) : data(data), next(nullptr) {}

        T data;
        Node* next;
    };

    Node* front = nullptr;
    Node* back = nullptr;
};

template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
void Queue<T>::top() {
    return this->front->data;
}

template <typename T>
void Queue<T>::push(T& element) {
    Node* node = new Node(element);

    if (this->back == nullptr) {
        this->back = node;
        this->front = node;
    } else {
        this->back->next = node;
        this->back = node;
    }
}

template <typename T>
void Queue<T>::pop() {
    Node* temp = this->front;
    this->front = this->front->next;
    
    if (this->front == NULL) {
        this->back = NULL;
    }

    delete temp;
}

#endif //QUEUE_H