/*********************
# Name: Caroline Kim
# Data Structure
# Coding Asg 04 - stack.cpp
# Purpose: Stacks ADT
# Creating a stack object that will work with a struct data type.
# Followed by the last assignment 3, this will allocate stack of pointers to Data structs.
**********************/

// each cpp includes ONLY it's header directly!
#include "stack.h"

Stack::Stack()
{
    top = -1;
}

Stack::~Stack() {
    for (int i = top; i >= 0; i--){
        delete stack[i];
    }
}

// Checking stack size, then checking variables int & string. After the checking, create new object of Data and inserts
bool Stack::push(int id, const string *information)
{
    bool result = false;
    if (top != STACK_SIZE - 1){
        if((id > 0) && (*information != ""))
        {
            Data *structData = new Data;
            structData->id = id;
            structData->information = *information;
            stack[++top] = structData;
            result = true;
        }
    } return result;
}



bool Stack::pop(Data *structData)
{
    bool result = false;
    if(!isEmpty()) {
        structData->id = stack[top]->id;
        structData->information = stack[top]->information;
        delete stack[top];
        top--;
        result = true;
    } else {
        structData->id = -1;
        structData->information= " ";
    }
    return result;
}



bool Stack::peek(Data *structData)
{
    bool result = false;
    if(!isEmpty()) {
        structData->id = stack[top]->id;
        structData->information = stack[top]->information;
        result = true;
    } else {
        structData->id = -1;
        structData->information= " ";
    }
    return result;
}

bool Stack::isEmpty() {return top == -1;}