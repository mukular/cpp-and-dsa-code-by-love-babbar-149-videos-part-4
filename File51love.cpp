/*
Q.1. You are given a linked list of 'N' nodes and an integer 'K'.
You have to reverse the given linked list in groups of size K
i.e.if the list contains x nodes numbered from 1 to x, then you 
need to reverse each of the groups (1,K),(K+1,2*K),and so on.
For example, if the list is [1,2,3,4,5,6] and K = 2, then the new 
list will be [2,1,4,3,6,5].
Note:-
In case the number of elements in the last cannot be evenly divided into
groups of size K, then just reverse the last group(with any size),
For example, if the list is 1 2 3 4 5 and K = 3, then the answer 
would be 3 2 1 5 4.
All the node values will be distinct.

Constraints:-
1 <= T <= 100
1 <= N <= 10^4
1 <= K <= 10^4

Input format:-
The first line of input contains an integer T representing the number of test
cases. Then T test cases follow.
The first line of each test case contains a linked list whose elements are
separated by space and the linked list is terminated by -1.
The second line of each test case contains an integer K.

Sample Input 1:-
2
1 2 3 4 5 6 -1
2
5 4 3 7 9 2 -1
4

Sample Output 1:-
2 1 4 3 6 5
7 3 4 5 2 9
*/

/*
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };


// Time Complexity = O(n) // space complexity = O(n)
Node* kReverse(Node* head, int k) {
    if(head == NULL)
    {
        return NULL;
    }

    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;
    while(curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL)
    {
        head->next = kReverse(next,k);
    }

    return prev;
}
*/

/*
Q.2. You are given the head of a linked list containing integers.
You need to find out whether the given linked list is circular or not.
Note:
1. A linked list is said to be circular if it has no node having
its next pointer equal to NULL and all the nodes form a circle i.e.
the next pointer of last node points to the first node.
2. An empty linked will also be considered as circular.
3. All the integers in the linked list are unique.
4. In the input, the next pointer of a node with i'th integer is linked
to the node with data (i+1)'th integer (If (i+1)'th node exists). If there is 
no such (i+1)'th integer then the next pointer of such node is set to NULL.

Input Format:-
The first Line of input contains an integer T, denoting the number 
of test cases.
The first line of each test case consists of an integer N, denoting 
the number of links in the linked list.
The second line of each test case consists of N space-separated integers 
denoting the data of the linked list and linking between nodes of the linked 
list as described in the notes above.

Output Format:-
For each test case, print 'True' or 'False' depending on whether
the linked list is circular or not, in a separate line.

Constraints:-
1 <= T <= 10^2
1 <= D <= 10^6 here D is data stored in node
0 <= N <= 10^4

Sample Input 1:-
1
5
1 2 3 4 1
Sample Output 1:-
True

Sample Input 2:-
1
7
1 2 3 4 5 6 7
False
*/

/*
 Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }

bool isCircular(Node* head){
    // Write your code here.
    // pichli files me yeh code likh diya h maine
}
*/