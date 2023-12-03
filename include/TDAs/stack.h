#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept> 


// Estructura Nodo para la Pila
template <typename T>
class StackNode {
public:
    int key;
    T value;
    StackNode* next;

    StackNode(int k, T val) : key(k), value(val), next(nullptr) {}
};

// Stack class
template <typename T>
class Stack {
private:
    StackNode<T>* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int key, T val) {
        StackNode<T>* newNode = new StackNode<T>(key, val);
        if (top == nullptr) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }

    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("The stack is empty");
        }

        StackNode<T>* temp = top;
        T poppedObject = temp->value;
        top = top->next;
        delete temp;

        return poppedObject;
    }

    T getTop() const {
        if (!isEmpty()) {
            return top->value;
        } else {
            std::cerr << "The stack is empty." << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};

#endif // STACK_H
