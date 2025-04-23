#include<iostream>
using namespace std;
class Rectangle
{
    int no;
    public:
    Rectangle(int a);
    ~Rectangle();
};
Rectangle::Rectangle(int a)
{
    no=a;
    cout<<"Hey there iam constructor"<<a<<endl;
}
Rectangle::~Rectangle()
{
    cout<<"Hey there iam destructor"<<no<<endl;
}
int main()
{
    Rectangle r1(1);
    Rectangle r2(2);
}