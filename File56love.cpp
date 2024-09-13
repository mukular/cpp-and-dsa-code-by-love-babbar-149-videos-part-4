/*
Q.1. Given two decimal numbers represented by two linked lists of size
N and M respectively. The task is to return a linked list that 
represents the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, 
similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will 
be represented by 2->1->5->null. You are required to return the head of the linked 
list 2->1->5->null.

Example 1:
Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked list (4 5) and (3 4 5), 
after adding the two linked list resultant linked list will be (3 9 0).

Example 2:
Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked list (6 3) and (7), 
after adding the two linked list resultant linked list will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference 
of both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M)) for the resultant list.

Constraints:
1 <= N, M <= 5000
*/

/*
struct Node{
    int data;
    struct Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/

/*
// Time complexity = O(N+M)
// Space complexity = O(max(N,M))

class Solution{
    private:
        Node* reverse(Node* head)
        {
            Node* curr = head;
            Node* prev = NULL;
            Node* next = NULL;
            while(curr != NULL)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }

        void insertAtTail(struct Node* &head, struct Node* &tail, int val)
        {
            Node* temp = new Node(val);
            if(head == NULL)
            {
                head = temp;
                tail = temp;
                return;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }

        struct Node* add(struct Node* first, struct Node* second)
        {
            int carry = 0;
            Node* ansHead = NULL;
            Node* ansTail = NULL;
            while(first != NULL && second != NULL)
            {
                int sum = carry + first->data + second->data;
                int digit = sum%10;
                insertAtTail(ansHead, ansTail, digit);
                carry = sum/10;
                first = first->next;
                second = second->next;
            }

            while(first != NULL)
            {
                int sum = carry + first->data;
                int digit = sum%10;
                insertAtTail(ansHead, ansTail, digit);
                carry = sum/10;
                first = first->next;
            }
            while(second != NULL)
            {
                int sum = carry + second->data;
                int digit = sum%10;
                insertAtTail(ansHead, ansTail, digit);
                carry = sum/10;
                second = second->next;
            }
            while(carry != 0)
            {
                int sum = carry;
                int digit = sum%10;
                insertAtTail(ansHead, ansTail, digit);
                carry = sum/10;
            }

            return ansHead;
        }
    public:
        struct Node* addTwoLists(struct Node* first, struct Node* second)
        {
            first = reverse(first);
            second = reverse(second);
            Node* ans = add(first, second);
            ans = reverse(ans);
            return ans;
        }
}
*/