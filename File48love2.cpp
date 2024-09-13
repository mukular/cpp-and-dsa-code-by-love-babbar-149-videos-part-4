// doubly linked list
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if(next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"memory free for node with data "<<val<<endl;
    }
};

// traversing a linked list
void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// function to get length of linked list
int getLength(Node* head)
{
    int len = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* & tail, Node* &head, int d)
{
    // empty list
    if(head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {  
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail,Node* &head, int d)
{
    if(tail== NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtposition(Node* & tail, Node* &head, int position, int d)
{
    // insert at start
    if(position == 1)
    {
        insertAtHead(tail, head, d);
        return ;
    }
    Node* temp = head;
    int cnt = 1;
    while (cnt < position-1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at last position
    if(temp->next == NULL)
    {
        insertAtTail(tail,head, d);
        return ;
    }
    // creating a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(int position, Node* &head)
{
    // deleting first or start node
    if(position == 1)
    {
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        // shayad there is a Mistake in Doubly Linked List.. While deleting any element in middle .....  you  have to update the ....curr->next->prev  
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    print(head);
    cout<<getLength(head)<<endl;

    insertAtHead(tail,head, 11);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    insertAtTail(tail, head,13);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    insertAtHead(tail,head, 69);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    insertAtposition(tail, head,2, 30);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    insertAtposition(tail, head,5 , 99);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    insertAtposition(tail, head, 1, 7);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    deleteNode(2, head);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    deleteNode(1, head);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    // love babbar ne deleteNode code me tail ko update nhi kiya h khud kar lena
    deleteNode(4, head);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    return 0;
}