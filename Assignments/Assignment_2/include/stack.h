#ifndef _STACK_H_
#define _STACK_H_

#include <stdexcept>
#include <algorithm>

template<typename T>
class Stack {

    class Node
    {
    public:
        T data;
        Node *next;
    };

  private:
    Node *head;
    int capacity{1};
    int fullSize;
  public:
    Stack();
    ~Stack();
    bool empty() const;
    unsigned int size() const;
    T& pop();
    void push(const T& e);
};

template<typename T>
Stack<T>::Stack() {
  head = nullptr;
  fullSize = 0;
}

template<typename T>
Stack<T>::~Stack() {
  Node *tempNode = nullptr;
  while (size() != 0)
  {
    tempNode = head;
    delete head;
    head = tempNode->next;
  }

  delete tempNode;
}

template<typename T>
bool Stack<T>::empty() const {
  return size() == 0;
}

template<typename T>
unsigned int Stack<T>::size() const{
  return static_cast<unsigned int>(fullSize);
}

template<typename T>
T& Stack<T>::pop() {
  if (empty()) {
    throw std::range_error{"Can't pop empty stack"};
  }
  if (head != nullptr) {
    T value = head->data;
    Node * tempNode = head;
    delete head;
    head = tempNode->next;
    delete tempNode;
    return value;
  }
}

template<typename T>
void Stack<T>::push(const T& e) {
  Node * n = new Node;
  n->data = e;
  n->next = head;
  head = n;
  fullSize++;
}

#endif
