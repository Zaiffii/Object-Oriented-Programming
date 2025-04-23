#include<iostream>
using namespace std;
class Rectangle
{
    int* length;
    int* width;
    public:
    Rectangle();
    ~Rectangle();
};
Rectangle::Rectangle()
{
    length=new int[10];
    width=new int[10];
    cout<<"Hey there iam constructor"<<endl;
}
Rectangle::~Rectangle()
{
    delete length;
    delete width;
    cout<<"Hey there iam destructor"<<endl;
}
int main()
{
    Rectangle r;
    return 0;
}