// inheritance
#include<iostream>
using namespace std;

class Human{ // parent class / super class
    public:
    int height;
    int weight;
    int age;

    public:
    int getAge()
    {
        return this->age;
    }
    void setWeight(int w)
    {
        this->weight = w;
    }
};

class Male: public Human{ // sub class / child class
    public:
    string color;

    void sleep()
    {
        cout<<"Male Sleeping"<<endl;
    }
    int getHeight()
    {
        return this->height;
    }
};

int main()
{
    Male object1;
    cout<<object1.age<<endl;
    cout<<object1.weight<<endl;
    cout<<object1.height<<endl;
    cout<<object1.color<<endl;
    object1.setWeight(84);
    cout<<object1.weight<<endl;
    object1.sleep();
    cout<<object1.getHeight()<<endl;
    return 0;
}