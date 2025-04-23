#include<iostream>
using namespace std;
class Person
{
    string name;
    int age;
    static int count;//static variables only declared inside the class but defined outside
    public:
    Person(string name="Unknown",int age=0);
    void setvalue(string name,int age);
    void getvalue();
    static void value();
};
int main()
{
    Person p1; 
    Person p2;
    Person p3;
    string p1_name, p2_name, p3_name;
    int p1_age, p2_age, p3_age;
    cout<<"Enter your name for your first person: ";
    cin>>p1_name;
    cout<<"Enter your age for your first person: ";
    cin>>p1_age;
    cout<<"Enter your name for your second person: ";
    cin>>p2_name;
    cout<<"Enter your age for your second person: ";
    cin>>p2_age;
    cout<<"Enter your name for your third person: ";
    cin>>p3_name;
    cout<<"Enter your age for your third person: ";
    cin>>p3_age;
    p1.setvalue(p1_name,p1_age);
    p2.setvalue(p2_name,p2_age);
    p3.setvalue(p3_name,p3_age);

    cout<<"Displaying Person 1: ";
    p1.getvalue();
    cout<<"Displaying Person 2: ";
    p2.getvalue();
    cout<<"Displaying Person 3: ";
    p3.getvalue();

    
 /*syntax of calling a static member function because it doesnot belong to a 
 particular class*/
    Person::value();
 /*If the static count was not in the private section we could access it like this also
    cout<<"Total number of students: "<<Person::count<<endl;*/
}

//static varibales must be declared outside the class
int Person::count=0;

//No need to write unknown and 0 here because it is alr wirtten in the class
Person::Person(string name,int age)//Constructor
{
    this->name=name;
    this->age=age;
    count++;
}

void Person::setvalue(string name, int age)//setting values
{
    this->name=name;
    this->age=age;
}

void Person::getvalue()//getting values
{
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
}

//we dont need to write static over here it is alr written in the class definition
void Person::value()//getting static variable
{
    cout<<"Total number of students: "<<count<<endl;
}