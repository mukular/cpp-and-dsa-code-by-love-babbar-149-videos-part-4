// singly linked list
#include<iostream>
#include<map>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free;
        if((this->next) != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<" memory is free for node with data "<<value<<endl;
    }
};

void insertAtHead(Node* &head, int d)
{
    // new node create
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d)
{
    // new node create
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void print(Node* &head)
{
    if(head == NULL)
    {
        cout<<"List is empty "<<endl;
        return ;
    }
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d)
{
    // insert at start
    if(position == 1)
    {
        insertAtHead(head, d);
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
        insertAtTail(tail, d);
        return ;
    }
    // creating a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node* &head)
{
    // deleting first or start node
    if(position == 1)
    {
        Node* temp = head;
        head = head->next;
        // memory free start node
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
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

// check if linked list is circular or not
// Lecture 51
bool isCircularList(Node* head)
{
    // empty list
    if(head == NULL)
    {
        return true;
    }
    Node* temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if(temp == head)
    {
        return true;
    }
    return false;
}

// check if linked list has a loop in it
// Lecture 52
// Method 1:-
bool detectLoop(Node* head)
{
    if(head == NULL)
    {
        return false;
    }
    map<Node*, bool> visited;
    Node* temp = head;
    while(temp != NULL)
    {
        // cycle is present
        if(visited[temp] == true)
        {
            cout<<"Present on element "<<temp->data<<endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// Method 2:-
// using Floyd's cycle detection algorithm
Node* floydDetectLoop(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast)
        {
            cout<<"present at "<< slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}

int main()
{
    Node* myhead = NULL;
    print(myhead);
    if(isCircularList(myhead))
    {
        cout<<" Linked List is Circular in nature"<<endl;
    }
    else
    {
        cout<<"Linked List is not Circular "<<endl;
    }

    // create a new node
    Node* node1 = new Node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

    // head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);

    if(isCircularList(head))
    {
        cout<<" Linked List is Circular in nature"<<endl;
    }
    else
    {
        cout<<"Linked List is not Circular "<<endl;
    }

    insertAtHead(head, 12);
    print(head);

    insertAtHead(head, 15);
    print(head);

    insertAtTail(tail, 14);
    print(head);

    insertAtTail(tail, 5);
    print(head);

    insertAtPosition(tail, head, 2, 22);
    print(head);

    insertAtPosition(tail, head, 5, 100);
    print(head);

    insertAtPosition(tail, head, 1, 69);
    print(head);

    insertAtPosition(tail, head, 9, 39);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    if(detectLoop(head))
    {
        cout<<"Cycle is present "<<endl;
    }
    else
    {
        cout<<"No Cycle"<<endl;
    }

    if(floydDetectLoop(head) != NULL)
    {
        cout<<"Cycle is present "<<endl;
    }
    else
    {
        cout<<"No Cycle"<<endl;
    }

    deleteNode(3, head);
    print(head);

    deleteNode(1, head);
    print(head);

    // love babbar ne deleteNode code me tail ko update nhi kiya h khud kar lena
    deleteNode(7, head);
    print(head);

    if(isCircularList(head))
    {
        cout<<" Linked List is Circular in nature"<<endl;
    }
    else
    {
        cout<<"Linked List is not Circular "<<endl;
    }


    return 0;
}