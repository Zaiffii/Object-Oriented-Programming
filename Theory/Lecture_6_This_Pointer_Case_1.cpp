/*Case 1 When the local variable and member variable have the same name

When both the class datamembers and the functions have the same name so inorder to tell
the compiler that which variable is of class and which is the function paramemeter we use 
this pointer*/
#include<iostream>
using namespace std;
class Teacher
{
    string name;
    int age;
    public:
    Teacher(string name="Unknown", int age=0)//Constructor
    {
/*The left ones are     The right ones are
the data members of     the parameters of the
the class               functions*/
        this->name=name;
        this->age=age;
    }
    void setvalues(string name, int age)
    {
        this->name=name;
        this->age=age;
    }
    void getvalue()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};
int main()
{
    Teacher t1("Huzaifa", 18);
    t1.getvalue();
}
