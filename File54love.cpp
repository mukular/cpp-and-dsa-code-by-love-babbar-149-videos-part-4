/*
Q.1. You are given a linked list having N number of nodes and each node will
have an integer which can be 0, 1, 2.You have to sort the given linked list 
in ascending order.
For example:
Let the linked list be 1->0->2->1->2
The sorted linked list for the given linked list will be 0->1->1->2->2

Constraints:-
1 <= N <= 10^3
0 <= data <= 2
where N is the length of the linked list
*/

/*
Method 1:-
// Time complexity = O(n)
// Space complexity = O(1)
Node* sortList(Node *head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == 0)
        {
            zeroCount++;   
        }
        else if(temp->data == 1)
        {
            oneCount++;   
        }
        else if(temp->data == 2)
        {
            twoCount++;   
        }
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL)
    {
        if(zeroCount != 0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0)
        {
            temp->data = 1;
            oneCount--;
        }
        else if(twoCount != 0)
        {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }

    return head;
}
*/

/*
Method 2:-
When Interviewer say data replacement is not allowed.
// Time complexity = O(n)
// Space complexity = O(1)

void insertAtTail(Node* &tail, Node* curr)
{
    tail->next = curr;
    tail = curr;
}

Node* sortList(Node *head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    Node* curr = head;
    while(curr != NULL)
    {
        int value = curr->data;
        if(value == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2)
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    if(oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next; 
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}
*/

/*
Q.2. You are given two sorted linked lists.You have to merge them
to produce a combined sorted linked list.You need to return the head 
of the final linked list.
Note:
The given linked lists may or may not be null. 
For example:
If the first list is: 1->4->5->NULL and the second list is: 2->3->5->NULL
The final list would be: 1->2->3->4->5->5->NULL

Constraints:-
1 <= T <= 10
1 <= L <= 10^5
1 <= data <= 10^6 and data != -1
where L is the number of nodes in either of the two linked lists.
*/
/*
 Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };
*/
/*
// Time Complexity = O(n)
// Space Complexity = O(1)

Node<int>*solve(Node<int>* first, Node<int>* second)
{
    if(first->next == NULL)
    {
        first->next = second;
        return first;
    }
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1->next;
    Node<int>* curr2 = second;
    Node<int>* next2 = curr2->next;
    while(next1 != NULL && curr2 != NULL)
    {
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;
            if(next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int> *second)
{
    if(first == NULL)
    {
        return second;
    }
    if(second == NULL)
    {
        return first;
    }
    if(first->data <= second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}
*/