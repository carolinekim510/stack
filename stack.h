/*********************
# Name: Caroline Kim
# Data Structure
# Coding Asg 04 - stack.h
# Purpose: Stacks ADT
# Creating a stack object that will work with a struct data type.
# Followed by the last assignment 3, this will allocate stack of pointers to Data structs.
**********************/

#ifndef STACK_H
#define STACK_H

/*
 * notice there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"
#define STACK_SIZE 10 // do not modify this define

class Stack {

public:

    Stack();
    ~Stack();

    bool push(int, const string*);
    bool pop(Data*);
    bool peek(Data*);
    bool isEmpty();

private:

    // these are the only attributes you need. do not modify them or add any
    int top; // this is your top index
    Data *stack[STACK_SIZE]; // this is your stack, it is an array of Data pointers
};

#endif //STACK_H