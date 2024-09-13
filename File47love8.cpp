// polymorphism
#include<iostream>
using namespace std;

class A{
    public:
    // function overloading
    // input argument number or type should differ
    void sayHello()
    {
        cout<<"Hello Love Babbar"<<endl;
    }

    int sayHello(string name, int n)
    {
        cout<<"Hello Love Babbar"<<endl;
        return n;
    }

    int sayHello(char name)
    {
        cout<<"Hello Love Babbar"<<endl;
        return 1;
    }

    void sayHello(string name)
    {
        cout<<"Hello "<<name<<endl;
    }
};

class B{
    public:
    int a;
    int b;

    public:
    int add()
    {
        return a+b;
    }

    // operator overloading
    void operator+ (B &obj)
    {
        int value1 = this->a;
        int value2 = obj.a;
        cout<<"output "<<value2 - value1<<endl;
        cout<<"Hello Babbar"<<endl;
    }

    void operator() ()
    {
        cout<<"main Bracket hu "<<this->a<<endl;
    }
};

// Run time polymorphism
// Ex. method overriding
// inheritance dependent
// function name same
// function argument same
class Animal{
    public:
    void speak()
    {
        cout<<"Speaking "<<endl;
    }
};

class Dog: public Animal{
    public:
    void speak()
    {
        cout<<"Barking "<<endl;
    }
};

int main()
{
    A obj;
    obj.sayHello();

    B obj1, obj2;
    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;
    obj1();

    Dog obj3;
    obj3.speak();
    return 0;
}

// google par search karna love babbar oops
// link khol lena oops ke bare me kai link diye hue h padh lena