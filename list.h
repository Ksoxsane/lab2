#pragma once
#include "Coordinates.h"
#include <iostream>
#include <iomanip>
#include <ctime>
typedef struct stack_node
{
    Coordinates data;
    stack_node* next;
    stack_node() 
    {
        next = NULL;
    }
} *stack_nd;
class Stack 
{
    private:
    int stack_size;
    stack_nd up_node;
    public:
    Stack();
    explicit Stack(int size);
    Stack(const Stack& obj);
    Coordinates popNode();
    void pushNode(Coordinates dt);
    Coordinates& getUpData();
    void displayStack();
    bool isEmpty();
    Coordinates& getLinkUp() 
    {
        return up_node->data;
    }
    Stack operator()(int skip_nodes, char& fl_err);
    Stack operator=(const Stack& second);
    char operator!=(const Stack& second);
    char operator==(const Stack& second);
    bool operator>(const Stack& second);
    bool operator<(const Stack& second);
    bool operator<=(const Stack& second);
    bool operator>=(const Stack& second);
    ~Stack();
};
