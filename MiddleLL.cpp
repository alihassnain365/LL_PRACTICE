#include <iostream>
#include <string>
#include "Stack.h"
#include "LinkedList.h"
using namespace std;
int main()
{
  LinkedList ll;
    ll.insertAtTail(1); 
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.display();
    cout<<endl;
    cout<<"Middle element is: "<<ll.middle()<<endl;
}