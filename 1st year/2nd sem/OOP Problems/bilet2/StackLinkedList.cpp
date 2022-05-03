//
// Created by asus on 5/3/2022.
//

#include "StackLinkedList.h"

StackLinkedList::StackLinkedList(): top(nullptr) {}

StackLinkedList::~StackLinkedList() {
    while (top != nullptr) {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

void StackLinkedList::push(int value) {
    Node *temp = new Node(value);
    temp->next = top;
    top = temp;
}

int StackLinkedList::pop() {
    if (top == nullptr) {
        throw "Stack is empty";
    }
    int value = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    return value;
}

bool StackLinkedList::isEmpty() {
    return top == nullptr;
}
