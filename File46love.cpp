// oops
// class and object
#include<iostream>
using namespace std;

// creating class
class Hero{
    // properties
    private:
    int health;

    public: 
    char level;

    void print()
    {
        cout<<level<<endl;
    }

    int getHealth()
    {
        return health;
    }

    char getLevel()
    {
        return level;
    }

    void setHealth(int h)
    {
            health = h;
    }

    void SetLevel(char ch)
    {
        level = ch;
    }

};

int main()
{
    // creating object
    // static allocation
    Hero ramesh;
    cout<<"size : "<<sizeof(ramesh)<<endl;
    // use getter
    cout<<"Ramesh health is "<<ramesh.getHealth()<<endl;
    cout<<"Level is: "<<ramesh.level<<endl;
    // use setter
    ramesh.setHealth(70);
    ramesh.level = 'A';
    cout<<"health is: "<<ramesh.getHealth()<<endl;
    cout<<"Level is: "<<ramesh.level<<endl;

    // dynamic allocation
    Hero *b = new Hero;
    cout<<"level is "<<(*b).level<<endl;
    cout<<" health is "<<(*b).getHealth()<<endl;
    cout<<"level is "<<b->level<<endl;
    cout<<"health is "<<b->getHealth()<<endl;
    b->SetLevel('B');
    b->setHealth(80);
    cout<<"level is "<<(*b).level<<endl;
    cout<<" health is "<<(*b).getHealth()<<endl;
    cout<<"level is "<<b->level<<endl;
    cout<<"health is "<<b->getHealth()<<endl;

    return 0;
}