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
            Node* slow = head;
            Node* fast = head;
            while (fast != nullptr and fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            Node* tempHead = head;
            Node* middleNode = slow;
            // reversing the second half of the linked list
            Node* curr = middleNode->next;
            Node* prev = nullptr;
            Node* next = nullptr;
            while (curr != nullptr)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            middleNode = prev;
            while (tempHead->data != middleNode->data)
            {
                if (tempHead->data != middleNode->data)
                {
                    return false;
                }
                tempHead = tempHead->next;
                middleNode = middleNode->next;
            }
            return true;
        }
};