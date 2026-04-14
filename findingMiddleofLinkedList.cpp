#include <iostream>
#include <string>
#include "Stack.h"
#include "LinkedList.h"
using namespace std;
int main()
{
    LinkedList l1;
    l1.insertAtHead(10);
    l1.insertAtHead(20);
    l1.insertAtTail(30);
    l1.insertAtTail(40);
    l1.display();

    cout<<endl;

   cout<<"Reveresed linkedList is: "<<endl;
    Node* newHead = l1.reverseList();
    while (newHead != nullptr)
    {
        cout<<newHead->data<<" ";
        newHead = newHead->next;
    }
    cout<<endl;

    return 0;   
}