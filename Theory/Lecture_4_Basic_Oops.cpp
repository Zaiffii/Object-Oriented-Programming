#include<iostream>
using namespace std;
class teacher
{
    string name;
    int age;
    public:
    void setvalue(string n, int a)//setting values
    {
        name=n;
        age=a;
    }
    void display()//displaying those values
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};
int main()

{
    teacher t1;
    string t1name;
    int t1age;
    cout<<"Enter your name: ";
    cin>>t1name;
    cout<<"Enter your age: ";
    cin>>t1age;
    t1.setvalue(t1name,t1age);
    t1.display();
}