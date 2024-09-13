// circular linked list
#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if(this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<" memory is free for node with data "<<value<<endl;
    }
};

void insertNode(Node* &tail, int element , int d)
{
    // assuming that the element is present in the list

    // empty list
    if(tail == NULL)
    {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non-empty list
        // assuming that the element is present in the list

        Node* curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        
        // element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* tail)
{
    Node* temp = tail;

    //empty list
    if(tail == NULL)
    {
        cout<<"List is Empty "<<endl;
        return ;
    }

    do
    {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while (tail != temp);
    cout<<endl;
}

void deleteNode(Node* &tail, int value)
{
    // empty list
    if(tail == NULL)
    {
        cout<<" List is empty, please check again"<<endl;
        return;
    }
    else
    {
        // non-empty
        // assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        // 1 Node Linked List
        if(curr == prev)
        {
            tail = NULL;
        }

        // >= 2 Node Linked List
        else if(tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

// check if linked list is circular or not
// Lecture 51
bool isCircularList(Node* head) // time complexity = O(n) // space complexity = O(1)
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
// space complexity = O(n)
// time complexity = O(n) // shayad yeh O(nlog(n)) hogi kyoki map me koi element access karne ki time complexity O(log(n)) hoti h shayad
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
// space complexity = O(1)
// time complexity = O(n)
Node* floydDetectLoop(Node* head)
{
    // ek baar keval ek node ho uske liye check karna kuch gadbad h shayad uske liye
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
            cout<<"present at "<< slow->data<<endl; // yeh ek node h loop me jaroori nhi ki beginning node ho
            return slow;
        }
    }
    return NULL;
}

// find beginning node of loop
Node* getStartingNode(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    Node* intersection = floydDetectLoop(head);
    if(intersection == NULL)
    {
        return NULL;
    }
    Node* slow = head;

    while(slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

// remove loop in linked list
void removeLoop(Node* head)
{
    if(head == NULL)
    {
        return;
    }
    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;
    while(temp->next != startOfLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
    Node* tail = NULL;

    // empty list me insert krre hai
    insertNode(tail, 5, 3);
    print(tail);

    if(isCircularList(tail))
    {
        cout<<" Linked List is Circular in nature"<<endl;
    }
    else
    {
        cout<<"Linked List is not Circular "<<endl;
    }

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    deleteNode(tail, 3);
    print(tail);
    
    deleteNode(tail, 5);
    print(tail);

    deleteNode(tail, 9);
    print(tail);

    deleteNode(tail, 4);
    print(tail);

    deleteNode(tail, 10);
    print(tail);

    deleteNode(tail, 6);
    print(tail);

    deleteNode(tail, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);

    if(isCircularList(tail))
    {
        cout<<" Linked List is Circular in nature"<<endl;
    }
    else
    {
        cout<<"Linked List is not Circular "<<endl;
    }

    return 0;
}