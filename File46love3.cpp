// constructor
#include<bits/stdc++.h>
using namespace std;

// creating class
class Hero{
    // properties
    private:
    int health;

    public: 
    char *name;
    char level;
    // static keyword se jo data member create karte h wo class se belong karta h
    // is data member ko access karne ke liye object banane ki need nhi hoti
    static int timeToComplete;

    Hero()
    {
        cout<<"Simple Constructor called"<<endl;
        name = new char[100];
    }

    // Parameterised constructor
    Hero(int health)
    {
        // when input parameter and data member name is same then we use this keyword
        // address of current object is stored in " this " so " this " is a pointer
        cout<<"this -> "<<this<<endl;
        this -> health = health;
    }

    Hero(int health, char level)
    {
        this->level = level;
        this->health = health;
    }

    // copy constructor
    // Hero(Hero& temp) // pass by value se infinite loop me fas jayenge copy constructor ke isliye pass by reference karna
    // {
    //     char *ch = new char[strlen(temp.name) + 1];
    //     strcpy(ch, temp.name);
    //     this->name = ch;
    //     cout<<"Copy constructor called"<<endl;
    //     this->health = temp.health;
    //     this->level = temp.level;
    // }

    void print()
    {
        cout<<endl;
        cout<<"[ Name: "<<this->name<<" ,";
        cout<<"health: "<<this->health<<" ,";
        cout<<"level: "<<this->level<<" ]";
        cout<<endl;
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

    void setName(char name[])
    {
        strcpy(this->name, name);
    }

    static int random()
    {
        return timeToComplete;
    }

    // Destructor
    ~Hero()
    {
        cout<<"Destructor bhai called"<<endl;
    }

};

int Hero::timeToComplete = 5; // initialise static data member

int main()
{
    // creating object
    // static allocation
    cout<<"Hi "<<endl;
    Hero ramesh;
    cout<<"hello "<<endl;
    cout<<ramesh.timeToComplete<<endl; // yeh tarika sahi nhi h
    cout<<Hero::timeToComplete<<endl; // yeh tarika sahi h
    cout<<Hero::random()<<endl;

    // dynamic allocation
    Hero *h = new Hero;
    Hero *h1 = new Hero(); // same as above line

    Hero ramu(10);
    cout<<"Address of ramu "<<&ramu<<endl;
    ramu.print();
    ramu.timeToComplete = 10;
    cout<<ramesh.timeToComplete<<endl;
    cout<<ramu.timeToComplete<<endl;

    // dynamic allocation
    Hero *h2 = new Hero(11);
    h2->print();

    Hero temp(22, 'B');
    temp.print();

    Hero S(70, 'C');
    S.print();
    Hero R(S); // Copy constructor is called // agar apan apna copy constructor nhi likhenge toh compiler ka copy constructor call ho jayega
    // apna copy constructor likh denge toh compiler ka copy constructor khatam ho jayega
    R.print();

    Hero hero1;
    hero1.setHealth(12);
    hero1.SetLevel('D');
    char name[7] = "Babbar";
    hero1.setName(name);
    hero1.print();

    // use default copy constructor 
    // class ke copy constructor ko comment kar dena shallow copy samajhne ke liye
    // class ke copy constructor ko uncomment kar dena deep copy samajhne ke liye
    // default constructor do shallow copy
    Hero hero2(hero1);
    // or
    // Hero hero2 = hero1;
    hero2.print();

    hero1.name[0] = 'G';
    hero1.print();
    hero2.print();

    hero1 = hero2; // copy assignment operator
    hero1.print();
    hero2.print();

    // khud destructor nhi likhenge toh compiler ka Destructor call hoga
    // jo object statically allocate hue h unke liye destructor automatically call hoga
    // jo object dynamically allocate hue h unke liye destructor manually call karna hoga
    delete h;
    delete h1;
    delete h2;
    
    return 0;
}