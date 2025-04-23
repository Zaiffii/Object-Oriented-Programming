#include<iostream>
using namespace std;
class Rectangle
{
    int length,width;
    public:
    Rectangle(int length=0, int width=0);
    Rectangle& setvalue(int length, int width);
    void getvalue();
};

int main()
{
    Rectangle r1;
    Rectangle* ptr;
    ptr=&r1;
    cout<<"Before Modifying the values: \n";
    r1.setvalue(2,2).getvalue();

    cout<<"\tAfter modifying value: \n";
    ptr->setvalue(3,3).getvalue();
    /*(*ptr).setvalue(3,3);
 this means:                
    (valueofptr).setvalue(,3);      ptr=address r1
    r1.setvalue(3,3);
    */
   
 //ptr->getvalue();
    //(*ptr).getvalue(3.3);
    /*(*ptr).getvalue();
 this means:                
    (valueofptr).getvalue;      ptr=address r1
    r1.getvalue;
    */
}

Rectangle::Rectangle(int length, int width)
{
    this->length=length;
    this->width=width;
};

/*Rectangle& is the return type that the return *this i.e the object is of Rectangle
    data type that is it's class*/
Rectangle& Rectangle::setvalue(int length, int width)
{
    this->length=length;
    this->width=width;
    return *this;
}

void Rectangle::getvalue()
{
    cout<<"Answer: "<<length*width<<endl;
}
