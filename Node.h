class Node
{
    public:
        int data ;
        Node* next;
        Node(int data)
        {
            next = nullptr;
            this->data = data;
        }
};