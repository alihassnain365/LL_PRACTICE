#include <iostream>
using namespace std;

class Stack
{
    private:
        int capacity;
        char* stack;
        int topStack;
    public:
        Stack(int cp)
        {
            capacity = cp;
            stack = new char[capacity];
            topStack = -1;
        }
        void push(char c)
        {
            if (capacity == topStack + 1)
            {
                cout<<endl<<"Stack is full";
            }
            else
            {
                topStack++; 
                stack[topStack] = c;
            }
        }

        char pop()
        {
            if (topStack == -1)
            {
                cout<<endl<<"Stack is empty";
                return '\0';
            }
            else
            {
                topStack--;
                return stack[topStack+1];
            }
        }
        char peek()
        {
            if (topStack == -1)
            {
                cout<<endl<<"Stack is empty";
                return '\0';
            }
            else
            {
                return stack[topStack];
            }
        }

        bool isEmpty()
        {
            if (topStack == -1) return true;
            else return false;
        }
};