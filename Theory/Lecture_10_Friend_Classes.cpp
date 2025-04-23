#include<iostream>
using namespace std;
class Square
{
    int length,width;
    friend class Rectangle;
};

class Rectangle
{
    int length, width;
    public:
    friend void setsquare(Square x);
    void setvalue(int x, int y);
    void result();    
};
int main()
{

}

void Rectangle::setvalue(int x, int y);
{
    length=x;
    width=y;
}

void Rectangle::setsquare(Square x)
{
    x.length=length;
    x.width=width;
}


void result()
{
    x.width*width;
    x.length*length;
}