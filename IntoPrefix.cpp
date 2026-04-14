#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

bool isOperator(char ch)
{
    if (ch == '+' or ch == '-' or ch == '*' or ch == '/' or ch == '^')
        return true;
    else
        return false;
}

bool isChar(char ch)
{
    if ((ch>='A' and ch<='Z') or (ch>='a' and ch <='z')) return true;
    else return false;
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' or ch == '/')
        return 2;
    else if (ch == '+' or ch == '-')
        return 1;
    else return 0;
}

bool isLeft(char ch)
{
    if (ch == '^')
        return false;
    else
        return true;
}

string inToPost(string eq)
{
    string output="";
    Stack s(100);
    for (int i = 0; i<eq.length(); i++)
    {
    
        // if it is '('
        if (eq[i] == '(')
        {
            s.push(eq[i]);
        }
        // if it is alphabet
        else if (isChar(eq[i]))
        {
            output += eq[i];
        }

        // if it is ')'
        else if (eq[i] == ')')
        {
            while(s.peek()!='(')
            {
                output+=s.pop();
            }
            // discarding the (
            s.pop();
        }
        // if it is not operator
        else
        {
            while(!s.isEmpty() and (precedence(s.peek()) > precedence(eq[i])))
            {
                output += s.pop();
            }
            s.push(eq[i]);
        }

        
    }

    // returning 
    while(!s.isEmpty())
    {
        output += s.pop();
    }
    return output;
}

string infixToPrefix(string eq)
{
  string output = "";
    Stack st(100);

    // reversing the string
    int j = eq.length() -1;
    string temp="";
    for (int i = 0; i<eq.length(); i++)
    {
        temp[i] = eq[j];
        j--;
    }
    
    for (int i = 0; i<temp.length(); i++)
    {
        if(temp[i] == '(') temp[i] = ')';
        else if (temp[i] == ')') temp[i] ='(';
    }

    for (int i = 0; i<eq.length(); i++)
    {
        if (temp[i] == '(')
        {
            st.pop();
        }
        else if (isChar(temp[i]))
        {
            output += temp[i];
        }
        else if(temp[i] ==')')
        {
            while (!st.isEmpty() and st.peek() != '(')
            {
                output += st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.isEmpty() and (precedence(st.peek()) >= precedence(temp[i])))
            {
                output += st.pop();
            }
        }
    }
    while (!st.isEmpty()) output += st.pop();
    return output;
}

int main()
{
    string eq;
    cout << endl
         << "Enter the equation : ";
    cin >> eq;
    
    cout<<endl<<"Postfix is this : "<<infixToPrefix(eq);
    
    return 0;
}
