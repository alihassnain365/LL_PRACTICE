#include <iostream>
#include <string>
#include "Node.h"
using namespace std;
class LinkedList
{
    Node* head;
    public:
        LinkedList()
        {
            head = nullptr;
        }
        void insertAtHead(int data)
        {
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = head;
            head = newNode;
        }
        void insertAtTail(int data)
        {
            Node* newNode = new Node();
            Node* tempHead = head;
            newNode->data = data;
            if (head == nullptr)
            {
                head = newNode;
                return;    
            }
            else
            {
                while (tempHead->next !=nullptr)
                {
                    tempHead = tempHead->next;
                }
                tempHead->next = newNode;                
            }
        }
        void display()
        {
            Node* tempHead = head;
            while (tempHead !=nullptr)
            {
                cout<<tempHead->data<<" ";
                tempHead = tempHead->next;
            }
            
        }

        int middle()
        {
            Node* slow = head;
            Node* fast = head;
            while (fast != nullptr and fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow->data;
        }


        Node* reverseList()
        {
            Node* current;
            Node* prev;
            Node* next;
            current  = head;
            prev = next = nullptr;
            while(current != nullptr)
            {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            return prev;
        }

        bool isPalindrome()
        {
            // finding the middle
            Node* fast;
            Node* slow;
            slow = fast = head;
            while (fast!=nullptr and fast->next !=nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            // slow is the middle
            // now reversing starting from slow->next
            Node* prev = nullptr;
            Node* next = nullptr;
            Node* current = slow->next;
            while (current!=nullptr)
            {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            // now camparing the LL at the left of slow with the Right of the slow
            bool result = true;
            while (true)
            {
                Node* tempHead = head;
                Node* afterSlow = slow->next;
                while(tempHead != slow and afterSlow !=nullptr)
                {
                    if(tempHead->data != afterSlow->data) 
                    {
                        result = false;
                        break;
                    }
                }
            }
            
            return result;
        }
};