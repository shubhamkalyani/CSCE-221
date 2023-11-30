#pragma once

#include <cstddef>
#include <iostream>

template <typename T> class Node {
    public:
        T data;
        Node<T>* next;
};

namespace CSCE221H {

template <typename T> class queue {
  public:
    using value_type = T;

    queue() {
        head = NULL;
        tail = NULL;
    }

    void push(const T& value) {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        newNode->next = NULL;
        if (empty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        sz++;
    }

    void pop() {
        if (empty()) {

        } else {
            T item = head->data;
            head = head->next;
            sz--;
        }
    }

    T& front() {
        return head->data;
    }

    T& back() {
        return tail->data;
    }

    void clear() {
        head->next = NULL;
        tail->next = NULL;
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    void swap(queue& x) {
        size_t temp_size = sz;
        Node<T>* temp_head = head;
        Node<T>* temp_tail = tail;

        sz = x.sz;
        head = x.head;
        tail = x.tail;

        x.sz = temp_size;
        x.head = temp_head;
        x.tail = temp_tail;
    }

    size_t size() {
        return sz;
    }

    bool empty() const {
        return head == NULL;
    }

    private:
      Node<T>* head;
      Node<T>* tail;
      size_t sz;
};



} // namespace CSCE221H