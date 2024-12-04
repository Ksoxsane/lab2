#include <string>
#include <limits>
#include "Stack.h"
using namespace std;
int main()
{
    string command;
    Coordinates tmp;
    float tmp_x = 0.0;
    float tmp_y = 0.0;
    float tmp_z = 0.0;
    int stack_size;
    char stack_fl = 0x01;
    char fl;
    while (true)
    {
        cout << "Enter size of stack = ";
        if (cin >> stack_size)
            if (stack_size > 0)
                break;
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }
    srand(time(0));
    Stack main_stack = Stack(stack_size);
    Stack tmp_stack = Stack(stack_size);
    Stack *stack = &main_stack;
    while (true)
    {
        cout 
        <<"show - Show stack" << endl
        <<"pop  - Popnode from stack"<< endl
        <<"push - Push node to stack"<< endl
        <<"up   - Show item of up node"<< endl
        <<"obj++ - + 1.5 to all coordinates" << endl
        <<"obj-- - + 5.9 from all coordinates" << endl
        <<"++obj - Sum all coordinates" << endl
        <<"--obj - Subtractscoordinates from each other" << endl
        <<"stack_== - ==" << endl
        <<"stack_!= - !=" << endl
        <<"stack_>  - >" << endl
        <<"stack_<  - <" << endl
        <<"stack_>= - >=" << endl
        <<"stack_<= - <=" << endl
        <<"stack_() - <=" << endl
        <<"exit - Correct exit from program" << endl
        <<"change_st - Change main stack" << endl
        << "\n";
        cout << "Enter: ";
        cin >> command;
        if (command == "show")
        {
            stack->displayStack();
            continue;
        }
        if (command == "pop")
        {
            stack->popNode();
            continue;
        }
        if (command == "push")
        {
            while (true)
            {
                cout << "Enter coordinates in form x y z: ";
                if (cin >> tmp_x >> tmp_y >> tmp_z)
                {
                    tmp.setCoord(tmp_x, tmp_y, tmp_z);
                    stack->pushNode(tmp);
                    break;
                }
                else 
                {
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                }
                continue;
            }
        }
        if (command == "up")
        {
            Coordinates &tmp_link = stack->getLinkUp();
            cout << "Coordinates in form x y z: "
                    << tmp_link.getX() << "\t"
                    << tmp_link.getY() << "\t"
                    << tmp_link.getZ() << endl;
            continue;
        }
        if (command == "obj++") 
        {
            stack->getLinkUp()++;
            continue;
        }
        if (command == "obj--") 
        {
            stack->getLinkUp()--;
            continue;
        }
        if (command == "++obj")
        {
            cout << "result = " << ++stack->getLinkUp() << endl;
            continue;
        }
        if (command == "--obj") 
        {
            --stack->getLinkUp();
            continue;
        }
        if (command == "stack_==") 
        {
            fl = (main_stack == tmp_stack);
            if (fl == 2)
                cout << "\tFULL_EQUAL" << endl;
            else if (fl == 1)
                cout << "\tSIZE_EQUAL" << endl;
            else if (fl == 0)
                cout << "\tNOT_EQUAL" << endl;
            continue;
        }
        if (command == "stack_!=") 
        {
            fl = (main_stack != tmp_stack);
            if (fl == 2)
                cout << "\tFULL_NOT_EQUAL" << endl;
            else if (fl == 1)
                cout << "\tDATA_NOT_EQUAL but SIZE_EQUAL" << endl;
            else if (fl == 0)
                cout << "\tFULL_EQUAL" << endl;
            continue;
        }
        if (command == "stack_>") 
        {
            fl = (main_stack > tmp_stack);
            if (fl == 1)
                cout << "\tMAIN larger than TMP" << endl;
            else
                cout << "\tMAIN not larger than TMP" << endl;
            continue;
        }
        if (command == "stack_<") 
        {
            fl = (main_stack < tmp_stack);
            if (fl == 1)
                cout << "\tMAIN lower than TMP_STACK" << endl;
            else
                cout << "\tMAIN not lower than TMP_STACK" << endl;
            continue;
        }
        if (command == "stack_>=") 
        {
            fl = (main_stack >= tmp_stack);
            if (fl == 1)
            {
                cout << "\tMAIN larger or equal than TMP " << endl;
            }
            else
                cout << "\tMAIN lower than TMP" << endl;
            continue;
        }
        if (command == "stack_<=") 
        {
            fl = (main_stack <= tmp_stack);
            if (fl == 1)
            {
                cout << "\tMAIN lower or equal than TMP"
                        << endl;
            }
            else
                cout << "\tMAIN larger than TMP" << endl;
            continue;
        }
        if (command == "stack_()") 
        {
            int skip_size = 0;
            char fl_err;
            while (true)
            {
                cout << "Enter num of skip_nodes = ";
                if (cin >> skip_size)
                    break;
                else
                {
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            Stack sub_stack = (*stack)(skip_size, fl_err);
            if (fl_err == true)
                sub_stack.displayStack();
            continue;
        }
        if (command == "exit")
        {
            break;
        }
        if (command == "change_st")
        {
            if (stack_fl == 0x01)
            {
                stack_fl = 0x02;
                stack = &tmp_stack;
            }
            else
            {
                stack_fl = 0x01;
                stack = &main_stack;
            }
            continue;
        }
    }
    return 0;
}