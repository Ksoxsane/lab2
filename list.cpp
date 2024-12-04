#include "Stack.h"
Stack::Stack()
{
    stack_size = 1;
    up_node = (stack_nd) new stack_node;
    up_node->next = 0;
}
Stack::Stack(int size)
{
    stack_size = size;
    up_node = 0;
    stack_nd tmp_dt;
    for (int i = 0; i < stack_size; ++i)
    {
        tmp_dt = up_node;
        up_node = (stack_nd) new stack_node;
        up_node->data = Coordinates(static_cast<float>(rand() % 301 - 101) + 0.5, static_cast<float>(rand() % 301 - 101) + 0.3, static_cast<float>(rand() % 301 - 101) + 0.1);
        up_node->next = tmp_dt;
    }
}
Stack::Stack(const Stack &obj)
{
    this->stack_size = obj.stack_size;
    stack_nd this_up = (stack_nd) new stack_node;
    stack_nd obj_up = obj.up_node;
    this->up_node = this_up;
    for (int i = 0; i < stack_size; ++i)
    {
        this_up->data = obj_up->data;
        if (stack_size != stack_size - 1)
        {
            this_up->next = (stack_nd) new stack_node;
            this_up = this_up->next;
            obj_up = obj_up->next;
        }
    }
}
Coordinates Stack::popNode()
{
    if (up_node == NULL || stack_size == 0)
    {
        std::cout << "EMPTY_STACK;" << std::endl;
        return Coordinates();
    }
    Coordinates tmp = up_node->data;
    stack_nd dl_nd = up_node;
    stack_size--;
    up_node = up_node->next;
    delete dl_nd;
    return tmp;
}
void Stack::pushNode(Coordinates dt)
{
    stack_nd tmp = new stack_node;
    stack_size++;
    tmp->data = dt;
    tmp->next = up_node;
    up_node = tmp;
}
Coordinates &Stack::getUpData()
{
    return (this->up_node->data);
}
void Stack::displayStack()
{
    if (this->isEmpty())
    {
        std::cout << "EMPTY_STACK" << std::endl;
        return;
    }
    Coordinates tmp_data;
    int number = 1;
    std::cout << std::setiosflags(std::ios::left) << std::setfill('=') << std::setw(52) << "=" << std::endl;
    std::cout << std::setfill(' ') << std::setw(14) << "| NUMBER    |" << std::setw(14)<< " " << std::setw(22) << "DATA IN NODE" << "| " << std::endl;
    std::cout << std::setfill('=') << std::setw(52) << "=" << std::endl;
    Stack tmp(*this);
    while (!tmp.isEmpty())
    {
        tmp_data = tmp.popNode();
        std::cout << std::setiosflags(std::ios::right) << std::setfill(' ') << "| " << std::setw(9) << number << " |" << std::setiosflags(std::ios::left) << std::setw(4) << " x:" << std::setprecision(4) << std::setw(8) << tmp_data.getX() << std::setw(4) << "|y: " << std::setprecision(4) << std::setw(8) << tmp_data.getY() << std::setw(4) << "|z: " << std::setprecision(4) << std::setw(8) << tmp_data.getZ() << " |" << std::endl;
        std::cout << std::setfill('=') << std::setw(52) << "=" << std::endl;
        number++;
    }
    std::cout.unsetf(std::ios::right);
}
bool Stack::isEmpty()
{
    return (stack_size == 0) ? 1 : 0;
}
Stack::~Stack()
{
    while (!isEmpty())
        popNode();
}
Stack Stack::operator()(int skip_nodes, char &fl_err)
{
    Stack tmp(*this);
    int i = 0;
    fl_err = true;
    if (skip_nodes >= 0 && skip_nodes < stack_size)
    {
        while (i != skip_nodes && !tmp.isEmpty())
        {
            tmp.popNode();
            i++;
        }
    }
    else
    {
        std::cout << "BAD_NUMBER;\n";
        fl_err = false;
        return Stack();
    }
    return tmp;
}
Stack Stack::operator=(const Stack &second)
{
    this->~Stack();
    this->stack_size = second.stack_size;
    stack_nd this_up = (stack_nd) new stack_node;
    stack_nd obj_up = second.up_node;
    this->up_node = this_up;
    for (int i = 0; i < stack_size; ++i)
    {
        this_up->data = obj_up->data;
        if (stack_size != stack_size - 1)
        {
            this_up->next = (stack_nd) new stack_node;
            this_up = this_up->next;
            obj_up = obj_up->next;
        }
    }
    return *this;
}
char Stack::operator==(const Stack &second)
{
    Stack first(*this), second_tmp(second);
    char res_fl = 0;
    Coordinates tmp_1, tmp_2;
    if (stack_size == second.stack_size)
    {
        res_fl = 2;
        while (!first.isEmpty() && !second_tmp.isEmpty())
        {
            tmp_1 = first.popNode();
            tmp_2 = second_tmp.popNode();
            if (tmp_1 != tmp_2)
            {
                res_fl = 1;
                break;
            }
        }
    }
    return res_fl;
}
char Stack::operator!=(const Stack &second)
{
    char tmp_res = (*this == second);
    switch (tmp_res)
    {
    case 1:
        return tmp_res;
    case 2:
        return false;
    default:
        return 2;
    }
}
bool Stack::operator>(const Stack &second)
{
    if (this->stack_size > second.stack_size)
        return true;
    return false;
}
bool Stack::operator<(const Stack &second)
{
    if (this->stack_size < second.stack_size)
        return true;
    return false;
}
bool Stack::operator<=(const Stack &second)
{
    if (this->stack_size <= second.stack_size)
        return true;
    return false;
}
bool Stack::operator>=(const Stack &second)
{
    if (this->stack_size >= second.stack_size)
        return true;
    return false;
}