#include<iostream>
using namespace std;
class teacher
{
    string name;
    int age;
    public:
    teacher(string n="Unknown", int a=0)
    {
        name=n;
        age=a;
    }
    void setvalue(string n, int a)
    {
        name=n;
        age=a;
    }
    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};
int main()
{
    teacher t1;
    teacher t2("kiran",10);
    string t1name;
    int t1age;
    cout<<"Enter your name: ";
    cin>>t1name;
    cout<<"Enter your age: ";
    cin>>t1age;
    t1.setvalue(t1name,t1age);
    t1.display();
}