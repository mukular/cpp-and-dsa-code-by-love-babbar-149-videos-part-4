/*
Q.1. You are given a stack consisting of N integers. Your task is 
to sort this stack in descending order using recursion.

Constraints:-
1 <= T <= 100
1 <= N <= 100
1 <= |v| <= 10^9
where |v| denotes the absolute value of any stack element.

Sample Input 1:
1 // T
5 // N
5 -2 9 -7 3 // stack elements
Sample Output 1:
9 5 3 -2 -7
Explanation Of Sample Input 1:
9 is the largest element, hence it’s present at the top. Similarly 5>3, 3>-2 and -7 being the smallest element is present at the last. 
Sample Input 2:
1
5
-3 14 18 -5 30
Sample Output 2:
30 18 14 -3 -5
Explanation Of Sample Input 2:
30 is the largest element, hence it’s present at the top. Similarly, 18>14, 14>-3 and -5 being the smallest element is present at the last. 
*/

/*
// Time Complexity = O(n^2)

void sortedInsert(stack<int> &stack, int num)
{
    if(stack.empty() || (!stack.empty() && stack.top() < num))
    {
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();
    sortedInsert(stack, num);
    stack.push(n);
}

void sortStack(stack<int> &stack)
{
    if(stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();

    sortStack(stack);
    sortedInsert(stack, num);
}
*/

/*
Q.2. Given valid mathematical expressions in the form of a string.You are
supposed to return true if the given expression contains a pair of redundant
brackets, else return false. The given string only contains '(' ,')' ,'+','-',
'*','/' and lowercase English letters.
Note:
A pair of brackets is said to be redundant when a subexpression is
surrounded by needless/useless brackets.

Constraints:-
1 <= T <= 50
3 <= |s| <= 10^4

Sample Input 1 :
2 // T
(a+b) // string s
(a+c*b)+(c))
Sample Output 1 :
No
Yes
Explanation Of Sample Input 1 :
In the first test case, there are no redundant brackets. Hence, the output is “No”. 
In the second test case, the brackets around the alphabet ‘c’( index 8 and index 10) are redundant. Hence the output is “Yes”.
Sample Input 2 :
2
(a*b+(c/d))
((a/b))
Sample Output 2 :
No
Yes
Explanation Of Sample Input 2 :
In the first test case, there are no redundant brackets. Hence, the output is “No”. 
In the second test case, the brackets around the subexpression “(a/b)” ( index 0 and index 6) are redundant. Hence the output is “Yes”.
*/

/*
// time Complexity = O(n)

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            if(ch == ')')
            {
                bool isRedundant = true;
                while(st.top() != '(')
                {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }
            }
            if(isRedundant == true)
            {
                return true;
            }
            st.pop();
        }
    }

    return false;
}
*/

/*
Q.3. Ninja has been given a string STR containing either '{' or '}'.
STR is called valid if all the brackets are balanced. Formally for 
each opening bracket,there must be a closing bracket right to it.
Ninja wants to make STR valid by performing some operations on it.
In one operation,he can convert '{' into '}' or vice-versa,and the cost 
of one such operation is 1.
Your task is to help Ninja determine the minimum cost to make STR valid.
Return -1 if it is impossible to make STR valid.

Constraints:-
1 <= T <= 100
0 <= |STR| <= 10^5

Sample Input 1:
2        // T
{{{}       // string STR
{{}{}}
Sample Output 1:
1
0
Explanation For Sample Input 1:
For the first test case:
The two valid strings that can be obtained from  ‘STR’ using minimum operations “{{}}”   and “{}{}”. 
Ninja can transform ‘STR’ to “{{}}” by performing the following operations:
Convert ‘{’ at index 2 to ‘}’.

Ninja can transform ‘STR’ to “{}{}” by performing the following operations:
Convert ‘{‘ at index 1 to ‘}’.
The minimum number of operations in transforming ‘STR’ to either of the two valid strings is 1.So, the total cost is 1.

For the second test case:
Given ‘STR’ is already valid so the minimum number of operations required is 0.
So, the total cost is 0.
Sample Input 2:
3
{}}{}}
{{{{
{{{}}
Sample Output 2:
1
2
-1
*/

/*

int findMinimumCost(string str) {
    if(str.length()%2 == 1)
    {
        return -1;
    }

    stack<char> s;
    for(int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if(ch == '{')
        {
            s.push(ch);
        }
        else
        {
            if(!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }

    int a = 0, b = 0;
    while(!s.empty())
    {
        if(s.top() == '{')
        {
            b++;
        }
        else
        {
            a++;
        }
        s.pop();
    }

    int ans = (a+1)/2 + (b+1)/2;
    return ans;

}
*/