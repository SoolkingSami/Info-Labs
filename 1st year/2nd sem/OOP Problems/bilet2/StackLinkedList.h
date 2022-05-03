//
// Created by asus on 5/3/2022.
//

#ifndef BILET2_STACKLINKEDLIST_H
#define BILET2_STACKLINKEDLIST_H


#include "Stack.h"

class StackLinkedList: public Stack {
private:
    Node *top;

public:
    StackLinkedList();
    ~StackLinkedList();
    void push(int value) override;
    int pop() override;
    bool isEmpty() override;
};


#endif //BILET2_STACKLINKEDLIST_H
