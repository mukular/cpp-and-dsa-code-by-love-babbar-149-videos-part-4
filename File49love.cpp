/*
Q.1. You are given a singly linked list of integers.
You need to reverse the Linked List by changing the links between nodes.

Input Format:
The first line of each test case contains the elements of the singly linked list separated by a single 
space and terminated by -1. Hence, -1 would never be a list element.

Output Format:
For each test case, print the reversed linked list.
The elements of the reversed list should be single-space separated, terminated by -1.
Print the output of each testcase in a separate line.

Note:
You do not need to print anything, just return the head of the reversed linked list.

Constraints:
1 <= N <= !0^4
0 <= data <= 10^9
where N is the number of nodes in the linked list.

Sample Input 1:
1 -2 3 -1
9 9 -1
4 -1

Sample output 1:
3 -2 1 -1
9 9 -1
4 -1
*/

/*
Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

1st Method:-
// time complexity = O(n) where n is number of nodes in linked list.
// space complexity = O(1).
Node *reverseLinkedList(Node *head) 
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

2nd Method:-
// time complexity = O(n) where n is number of nodes in linked list.
// space complexity = O(n).
void reverse(Node* &head, Node* curr, Node* prev)
{
    // base case
    if(curr == NULL)
    {
        head = prev;
        return ;
    }
    Node* forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

Node* reverseLinkedList(Node *head)
{
    Node* curr = head;
    Node* prev = NULL;
    reverse(head, curr, prev);
    return head;
}

3rd Method:-
// time complexity = O(n) where n is number of nodes in linked list.
// space complexity = O(n).
Node* reverse1(Node* head)
{
    // base case
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* chotaHead = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotaHead;
}

Node* reverseLinkedList(Node *head)
{
    return reverse1(head);
}
*/

/*
Q.2. Given the head node of the singly linked list, return a pointer pointing to the
middle of the linked list.
If there are an odd number of elements, return the middle element if there are even elements
return the one which is farther from the head node.
Constraints:-
1 <= N <= 10^4
0 <= data <= 10^3

Sample Input 1 :
1 2 3 4 5
Sample Output 1 :
3 4 5
Explanation Of Sample Input 1 :
We can clearly see that there are 5 elements in the linked list therefore the middle node is the node with value '3'.

Sample Input 2 :
1 2 3 4 5 6
Sample Output 2 :
4 5 6
Explanation Of Sample Input 2 :
We can clearly see that there are 6 elements in the linked list and the middle nodes are  
nodes with values 3 and 4 hence we return a second middle node having value '4'.
*/

/*
1st Method:-
Time complexity = O(n) where n is number of nodes.
int getLength(Node* head)
{
    int len = 0;
    while(head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

Node *findMiddle(Node *head)
{
    int len = getLength(head);
    int ans = (len/2);
    Node* temp = head;
    int cnt = 0;
    while(cnt < ans)
    {
        temp = temp->next;
        cnt++;
    }
    return temp;
}

2nd Method:-
Time complexity = O(n) where n is number of nodes.
Space complexity = O(1).
Node* getMiddle(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    // 2 nodes
    if(head->next->next == NULL)
    {
        return head->next;
    }
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

Node *findMiddle(Node *head)
{
    return getMiddle(head);
}
*/