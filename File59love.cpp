// stack

#include<iostream>
#include<stack>
using namespace std;

// stack using array
class Stack
{
    public:
        int *arr;
        int top;
        int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // time complexity = O(1)
    void push(int element)
    {
        if(size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout<<"Stack Overflow"<<endl;
        }
    }

    // time complexity = O(1)
    void pop()
    {
        if(top >= 0)
        {
            top--;
        }
        else
        {
            cout<<"Stack Underflow"<<endl;
        }
    }

    // gives top element in stack
    // time complexity = O(1)
    int peek()
    {
        if(top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
    }

    // time complexity = O(1)
    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    // stack using stl
    stack<int> s;

    // push elements in stack on top
    s.push(2);
    s.push(3);
    // pop element from top
    s.pop();
    cout<<"Printing top element "<<s.top()<<endl;
    if(s.empty())
    {
        cout<<"Stack is empty "<<endl;
    }
    else
    {
        cout<<"stack is not empty "<<endl;
    }

    cout<<"size of stack is "<<s.size()<<endl;

    Stack st(5);
    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    st.push(44);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    if(st.isEmpty())
    {
        cout<<"Stack is Empty mere dost "<<endl;
    }
    else
    {
        cout<<"Stack is not Empty mere dost "<<endl; 
    }
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    if(st.isEmpty())
    {
        cout<<"Stack is Empty mere dost "<<endl;
    }
    else
    {
        cout<<"Stack is not Empty mere dost "<<endl; 
    }

    return 0;
}

/*
Q.1. Design a data structure which represents two stacks using
only one array common for both stacks. The data structure 
should support the following operations:
push1(NUM) - push NUM into stack1.
push2(NUM) - push NUM into stack2.
pop1() - Pop out a top element from stack1 and return popped
element, in case of underflow return -1.
pop2() - Pop out a top element from stack2 and return popped
element, in case of underflow return -1.
*/

/*

class TwoStack{
    int *arr;
    int top1;
    int top2;
    int size;

public:

    TwoStack(int s)
    {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void push1(int num)
    {
        if(top2 - top1 > 1)
        {
            top1++;
            arr[top1] = num;
        }
    }
    void push2(int num)
    {
        if(top2 - top1 > 1)
        {
            top2--;
            arr[top2] = num;
        }
    }

    int pop1()
    {
        if(top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    int pop2()
    {
        if(top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }

};

*/


// stack implementation using linked list khud dekh lena