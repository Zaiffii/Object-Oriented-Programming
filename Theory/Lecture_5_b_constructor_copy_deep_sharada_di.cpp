/*Compiler doesn't create a deep copy const by default we have
to create our own
It will make a deep copy of the objects both of the objects , they will work at the different
memory space, if we change the data of object 2 then the data 
of object 1 will not change because both of them are pointing towards two different memory space.*/
#include<iostream>
using namespace std;
class Student
{
    public:
    string name;
    double* cgpaptr;

    Student(string name, double cgpa)//Constructor
    {
        this->name=name;
        cgpaptr=new double;//the pointer points to a memory address
        *cgpaptr=cgpa;//storing the value of cgpa in that memory address
    }

    Student(Student& oldobj)//Deep Copy Constructor
    {
        name=oldobj.name;
        cgpaptr=new double;//We are creating another memory address
        *cgpaptr=*oldobj.cgpaptr;//We are copying the VALUE of oldobj to new
        //if we write *cgpaptr=oldobj.cgpaptr then it will store the address of old cgpaptr
    }

    ~Student()//Destructor
    {
        delete cgpaptr;
    }

    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Cpga: "<<*cgpaptr<<endl;//printing value of cgpa stored at that memory
    }

};

int main()
{
    Student s1("Huzaifa", 3.3);

    Student s2(s1);
    cout<<"\tBefore changing the cpga of s2\n";
    s1.display();
    s2.display();
    *(s2.cgpaptr)=3.5;

    //now it will also change the cpga of s1;
    cout<<"\tAfter changing the cpga of s2\n";
    s1.display();
    s2.display();
}