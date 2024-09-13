/*
Q.1. Given a singly linked list of size N of integers. 
The task is to check if the given linked list is palindrome or not.

Example 1:
Input:
N = 3
value[] = {1,2,1}

Output: 1
Explanation: The given linked list is 1 2 1 , which is a 
palindrome and Hence, the output is 1.

Example 2:
Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list is 1 2 3 4 , which is 
not a palindrome and Hence, the output is 0.

Your Task:
The task is to complete the function isPalindrome() which 
takes head as reference as the only parameter and returns 
true or false if linked list is palindrome or not respectively.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

Constraints:
1 <= N <= 10^5

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
Method 1:-
Space complexity = O(n)
time complexity = O(n)

class Solution
{
    private:
        bool checkPalindrome(vector<int> arr)
        {
            int n = arr.size();
            int s = 0;
            int e = n-1;
            while(s <= e)
            {
                if(arr[s] != arr[e])
                {
                    return 0;
                }
                s++;
                e--;
            }
            return 1;
        }
    public:
        bool isPalindrome(Node* head)
        {
            vector<int> arr;
            Node* temp = head;
            while(temp != NULL)
            {
                arr.push_back(temp->data);
                temp = temp->next;
            }
            return checkPalindrome(arr);
        }
}
*/

/*
Method 2:-
Space complexity = O(1)
Time Complexity = O(n)

class Solution
{
    private:
        Node* getMid(Node* head)
        {
            Node* slow = head;
            Node* fast = head->next;
            while(fast != NULL && fast->next != NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow;
        }

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
    public:
        bool isPalindrome(Node* head)
        {
            if(head->next == NULL)
            {
                return true;
            }
            Node* middle = getMid(head);
            Node* temp = middle->next;
            middle->next = reverse(temp);

            Node* head1 = head;
            Node* head2 = middle->next;
            while(head2 != NULL)
            {
                if(head1->data != head2->data)
                {
                    return false;
                }
                head1 = head1->next;
                head2 = head2->next;
            }

            // below two steps are optional
            temp = middle->next;
            middle->next = reverse(temp);
            return true;
        }
}
*/