//
// Created by asus on 5/3/2022.
//

#ifndef BILET2_QUEUE_H
#define BILET2_QUEUE_H


class Queue {
public:
    virtual void push(int value) = 0;
    virtual int pop() = 0;
    virtual bool isEmpty() = 0;
};


#endif //BILET2_QUEUE_H
