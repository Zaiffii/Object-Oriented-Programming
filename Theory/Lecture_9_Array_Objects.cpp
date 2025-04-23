#include<iostream>
using namespace std;
class Person
{
    string name;
    int age;
    static int count;
    public:
    Person(string name="Unknown", int age=0);
    void setvalue(string name, int age);
    void getvalue();
    static int totalcount();
};

void input(Person persons[], int size);
void output(Person persons[], int size);

int main()
{
    int size;
    cout<<"Enter the number of persons you want to make: ";
    cin>>size;
    Person persons[size];
    input(persons,size);
    output(persons,size);
    /*syntax of calling a static member function because it doesnot belong to a 
    particular class*/
    Person::totalcount();
    /*If the static count was not in the private section we could access it like this also
    cout<<"Total number of students: "<<Person::count<<endl;*/
}

int Person::count=0;//Intializing the static data member

Person::Person(string name, int age)//Constructor
{
    this->name=name;
    this->age=age;
    count++;
}

void Person::setvalue(string name, int age)//Setter function
{
    this->name=name;
    this->age=age;
}

void Person::getvalue()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
}

void input(Person persons[], int size)
{
    string name;
    int age;
    cout<<"\t\tInputting values\n";
    for(int i=0; i<size; i++)
    {
        cout<<"\tPerson "<<i+1<<": \n";
        cout<<"Enter your name: ";
        cin>>name;
        cout<<"Enter your age: ";
        cin>>age;
        persons[i].setvalue(name,age);
    }
}

void output(Person persons[], int size)
{
    cout<<"\t\tOutputing values\n";
    for(int i=0; i<size; i++)
    {
        cout<<"\tPerson "<<i+1<<": \n";
        persons[i].getvalue();
    }
}

//we dont need to write static over here it is alr written in the class definition
int Person::totalcount()//Static Fucntion
{
    cout<<"Total Number of students created: "<<count<<endl;
}