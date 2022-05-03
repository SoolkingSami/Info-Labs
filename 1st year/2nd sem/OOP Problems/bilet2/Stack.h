//
// Created by asus on 5/3/2022.
//

#ifndef BILET2_STACK_H
#define BILET2_STACK_H


struct Node {
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
public:
    virtual void push(int value) = 0;
    virtual int pop() = 0;
    virtual bool isEmpty() = 0;
};


#endif //BILET2_STACK_H
