#include<iostream>
#include<stack>
using namespace std;

int main()
{
    // reversing a string using stack
    // Time Complexity = O(n)
    // Space Complexity = O(n)
    string str = "babbar";
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        s.push(ch);
    }
    
    string ans = "";
    while (!s.empty())
    {
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }
    cout<<"answer is: "<<ans<<endl;
    return 0;
}

/*
Q.1. You are having a stack ARR of size N+1, your task is to
delete the middlemost element so that size of resulting stack is N.

Constraints:-
1 <= T <= 100
1 <= N+1 <= 3000
0 <= data <= 10^9
where T is the number of test cases, N+1 is the number of elements
in the input stack, data is the value of each element in the stack.
Examples:-
Input:- ARR[] = [1,2,3,4,5] , N = 4
Output:- ARR[] = [1,2,4,5] 

Input:- ARR[] = [5,6,7,8] , N = 3
Output:- ARR[] = [5,7,8] 

*/

/*
void solve(stack<int>&inputStack, int count, int size)
{
    if(count == size/2)
    {
        inputStack.pop();
        return;
    }
    int num = inputStack.top();
    inputStack.pop();
    solve(inputStack, count+1, size);
    inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N)
{
    int count = 0;
    solve(inputStack, count, N); // shayad yaha N ki jagah N+1 aana chahiye
}
*/

/*
Q.2. You are given string consisting solely of "{", "}", "(", ")", "[", "]".
Determine whether the parentheses are balanced.

Input Format:-
The first line contains an Integer T which denotes the number of test cases
or queries to be run. Then the test cases follow.
The first and only line of input of each test case contains a string, as described 
in the task.

Output Format:-
For each test case, the first and the only line of output prints
whether the string or expression is balanced or not.

Constraints:-
1 <= T <= 10
1 <= N <= 10^5
where N is the length of the input string or expression.

Sample Input 1:-
2
[()]{}{[()()]()}
[(])

Sample output 1:-
Balanced
Not Balanced

Sample Input 2 :
[[}[

Sample Output 2 :
Not Balanced
*/

/*
// Time Complexity = O(n)
// Space Complexity = O(n)
bool isValidParenthesis(string expression)
{
    stack<char> s;
    for(int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];
        if(ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            if(!s.empty())
            {
                char top = s.top();
                if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if(s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
*/

/*
Q.3. You are given a stack/deque of integers MY-STACK and an integer
x. Your task is to insert x to the bottom of MY-STACK and return
the updated stack/deque.

1 <= T <= 100
1 <= N <= 10^4
0 <= x and MY_STACK[i] <= 10^5

Sample Input 1 :
2 // test case
3 8 // N and x
4 3 2 // stack
4 5
6 2 4 9
Sample Output 1 :
8 4 3 2
5 6 2 4 9

Sample Input 2 :
2
1 0
4 
2 5
1 9
Sample Output 2 :
0 4
5 1 9
*/

/*
// Time Complexity = O(n)

void solve(stack<int>& s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();
    solve(s, x);
    s.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(mystack, x);
    return mystack;
}
*/

/*
Q.4. Reverse a given stack of integers using recursion.
Note:-
You are not allowed to use any extra space other than the internal
stack space used due to recursion.
You are not allowed to use the loop constructs of any sort available
as handy. For example: for, for-each, while, etc.
Sample Input 1 :
3 // N
2 1 3 // stack
Sample Output 1 :
3 1 2
                   
Sample Input 2 :
2
3 2
Sample Output 2 :
2 3

Constraints :
0 <= N <= 10^3
Where 'N' is the number of elements in the given stack.
*/

/*
// Time Complexity = O(n^2)

void insertAtBottom(stack<int> &s, int element)
{
    if(s.empty())
    {
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();
    insertAtBottom(s, element);
    s.push(num);
}

void reverseStack(stack<int> &stack)
{
    if(stack.empty())
    {
        return;
    }
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, num);
}
*/