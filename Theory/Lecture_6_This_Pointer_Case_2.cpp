//Case 2 To return the reference to the calling object

#include<iostream>
using namespace std;
class Teacher
{
    string name;
    int age;
    public:
    /*The constructor will remain the same because constructor doesnt have a return
    type*/
    Teacher(string name="Unknown", int age=0)
    {
/*The left ones are     The right ones are
the properties of      the parameters of the
the objects            functions*/
        this->name=name;
        this->age=age;
    }

    /*Teacher& is the return type that the return *this i.e the object is of teacher
    data type that is it's class*/
    Teacher& setvalues(string name, int age)
    {
        this->name=name;
        this->age=age;
        return *this;
    }
    void getvalue()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};
int main()
{
    Teacher t1;
    t1.setvalues("Huzaifa",0).getvalue();//Chain function calls on a single object
    
    /*When a reference to a local object is returned, the returned reference 
    can be used to chain function calls on a single object.*/
}