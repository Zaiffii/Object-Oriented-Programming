#include<iostream>
using namespace std;
class rectangle
{
    const int length;
    const int width;
    public:
    rectangle(int length=0, int width=0):width(width),length(length)
    {

    }
    void getvalue()const;
};
int main()
{
    const rectangle r1(10,20);
    r1.getvalue();
}
void rectangle::getvalue()const
{
    cout<<"The area of rectangle is: "<<length*width<<endl;
}