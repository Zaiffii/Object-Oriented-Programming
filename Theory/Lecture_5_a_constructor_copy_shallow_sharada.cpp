#include<iostream>
using namespace std;
class Student
{
    public:
    string name;
    double cgpa;

    Student(string name, double cgpa)//Constructor
    {
        this->name=name;
        this->cgpa=cgpa;
    }

    Student(Student& oldobj)//Shallow Copy Constructor
    /*Classname(Obj datatype &Objectname)

    Question:Why do we write &oldobj??
    Ans:If we will not write &oldobj then the complier will think that we are creating a new obj
    it will then do to the const again assign value then comeback then it will think that again 
    a new obj is being created then it will again go to const assign values and an infinite loop 
    will occur 
    Thats why we write address to tell the compiler that the oldobj stored at this memory address
    we have to copy its values to the new obj donot create a new oldobj*/
    {
        name=oldobj.name;
        //name(new object)=name(old object) i.e name.oldobj
        cgpa=oldobj.cgpa;
         //cgpa(new object)=cgpa(old object) i.e cgpa.oldobj

    /*yeh humain kah rha hai kah jo student class ka object hai us ka address diya hai 
    kah yeh wala object!
    Phir humain kaha kah jo naye obj ka name yah cgpa hai usko day day do purana 
    jo object (lets say oldobj) uskay name ki 
    name(new object)=name(old object) i.e name.oldobj*/
    }

    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Cpga: "<<cgpa<<endl;
    }
};

int main()
{
    Student s1("Huzaifa", 3.3);

    Student s2(s1); //can also write it like Student s2=s1;
    cout<<"\tBefore changing the cpga of s2\n";
    s1.display();
    s2.display();
    s2.cgpa=3.5;

    //It will not change the value of s1
    cout<<"\tAfter changing the cpga of s2\n";
    s1.display();
    s2.display();
}

/*s2=s1 this will not call a copy constructor this copy the value of s2 to s1
    This is the assignment operator
Why Do We Need a Copy Constructor If the Assignment Operator Copies Values?
Even though the assignment operator (=) copies values, the copy constructor is 
necessary because it handles object initialization, whereas the assignment operator 
is used only for assigning values to an already existing object.*/