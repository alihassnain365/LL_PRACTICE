#include <iostream>
#include <string>
#include "Stack.h"
#include "LinkedList.h"
using namespace std;
int main()
{
//     LinkedList l1;
//     l1.insertAtHead(10);
//     l1.insertAtHead(20);
//     l1.insertAtTail(30);
//     l1.insertAtTail(40);
//     l1.display();

//     cout<<endl;

//    cout<<"Reveresed linkedList is: "<<endl;
//     Node* newHead = l1.reverseList();
//     while (newHead != nullptr)
//     {
//         cout<<newHead->data<<" ";
//         newHead = newHead->next;
//     }
//     cout<<endl;

    // checking if the linked list is palindrome
    LinkedList l2;
    l2.insertAtTail(1);
    l2.insertAtTail(2);
    l2.insertAtTail(3);
    l2.insertAtTail(2);
    l2.insertAtTail(1);
    l2.display();
    cout<<endl;
    if (l2.isPalindrome())
    {
        cout<<"The linked list is palindrome"<<endl;
    }
    else
    {
        cout<<"The linked list is not palindrome"<<endl;
    }

    return 0;   
}