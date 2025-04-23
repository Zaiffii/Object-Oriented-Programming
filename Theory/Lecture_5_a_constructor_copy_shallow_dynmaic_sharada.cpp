/*If we dont create a shallow copy const c++ will create it by default and it will
work just like shallow copy const*/
/*Shallow copy can work with dynamic memory allocation but then both of the objects 
will work at the same memory space, if we change the data of object 2 then the data 
of object 1 will also change because both of them are pointing towards the same memory 
space. e.d google docs*/
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

    Student(Student& oldobj)//Shallow Copy Constructor
    {
        name=oldobj.name;
        cgpaptr=oldobj.cgpaptr;
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