/*
Q.1. You are given a special linked list with N nodes where each node 
has a next pointer pointing to its next node. You are also given M random 
pointers, where you will be given M number of pairs denoting two nodes a 
and b  i.e. a->arb = b (arb is pointer to random node).

Construct a copy of the given list. The copy should consist of exactly N 
new nodes, where each new node has its value set to the value of its 
corresponding original node. Both the next and random pointer of the new nodes 
should point to new nodes in the copied list such that the pointers in the 
original list and copied list represent the same list state. None of the 
pointers in the new list should point to nodes in the original list.
For example, if there are two nodes X and Y in the original list, where X.arb --> Y, 
then for the corresponding two nodes x and y in the copied list, x.arb --> y.

Return the head of the copied linked list.
Example 1:

Input:
N = 4, M = 2
value = {1,2,3,4}
pairs = {{1,2},{2,4}}
Output: 1
Explanation: In this test case, there are 4 nodes in linked list.  Among these
4 nodes,  2 nodes have arbitrary pointer set, rest two nodes have arbitrary pointer
as NULL. Second line tells us the value of four nodes. The third line gives the
information about arbitrary pointers. The first node arbitrary pointer is set to
node 2.  The second node arbitrary pointer is set to node 4.

Example 2:

Input:
N = 4, M = 2
value[] = {1,3,5,9}
pairs[] = {{1,1},{3,4}}
Output: 1
Explanation: In the given testcase , applying the method as stated in the
above example, the output will be 1.

Your Task:
The task is to complete the function copyList() which takes one argument 
the head of the linked list to be cloned and should return the head of the cloned linked list.

NOTE : 
1. If there is any node whose arbitrary pointer is not given then it's by default NULL. 
2. Your solution return an output 1 if your clone linked list is correct, else it returns 0.
3. Don't make any changes to the original linked list.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 100
1 <= M <= N
1 <= a, b <= 100
*/

/*
Method 1:-
Time Complexity = O(n)
Space Complexity = O(n)

class Solution{
    private:
        void insertAtTail(Node* &head, Node* &tail, int d)
        {
            Node* newNode = new Node(d);
            if(head == NULL)
            {
                head = newNode;
                tail = newNode;
                return;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
    public:
        Node *copyList(Node *head)
        {
            Node* cloneHead = NULL;
            Node* cloneTail = NULL;
            Node* temp = head;

            while(temp != NULL)
            {
                insertAtTail(cloneHead, cloneTail, temp->data);
                temp = temp->next;
            }

            unordered_map<Node*, Node*> oldToNewNode;
            Node* originalNode = head;
            Node* cloneNode = cloneHead;
            while(originalNode != NULL)
            {
                oldToNewNode[originalNode] = cloneNode;
                originalNode = originalNode->next;
                cloneNode = cloneNode->next;
            }

            originalNode = head;
            cloneNode = cloneHead;

            while(originalNode != NULL)
            {
                cloneNode->arb = oldToNewNode[originalNode->arb];
                originalNode = originalNode->next;
                cloneNode = cloneNode->next;
            }

            return cloneHead;

        }
}
*/

/*
Method 2:-
Time Complexity = O(n)
Space Complexity = O(1) // yeh shayad O(n) aayegi kyoki linked list bhi toh create ki h

class Solution{
    private:
    void insertAtTail(Node* &head, Node* &tail, int d)
        {
            Node* newNode = new Node(d);
            if(head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
    public:
        Node *copyList(Node *head)
        {
            Node* cloneHead = NULL;
            Node* cloneTail = NULL;
            Node* temp = head;
            while(temp != NULL)
            {
                insertAtTail(cloneHead, cloneTail, temp->data);
                temp = temp->next;
            }

            Node* originalNode = head;
            Node* cloneNode = cloneHead;

            while(originalNode != NULL && cloneNode != NULL)
            {
                Node* next = originalNode->next;
                originalNode->next = cloneNode;
                originalNode = next;

                next = cloneNode->next;
                cloneNode->next = originalNode;
                cloneNode = next;
            }

            temp = head;
            while(temp != NULL)
            {
                if(temp->next != NULL)
                {
                    temp->next->arb = temp->arb ? temp->arb->next : temp->arb;
                }
                temp = temp->next->next;
            }

            originalNode = head;
            cloneNode = cloneHead;
            while(originalNode != NULL && cloneNode != NULL)
            {
                originalNode->next = cloneNode->next;
                originalNode = originalNode->next;

                if(originalNode != NULL)
                {
                    cloneNode->next = originalNode->next;
                }
                cloneNode = cloneNode->next;
            }

            return cloneHead;

        }
    
}
*/