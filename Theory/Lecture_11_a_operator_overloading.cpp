#include<iostream>
using namespace std;

class Complex
{
    double real, imag;
    public:
    Complex(double r=0.0, double i=0.0):real(r),imag(i){} //constructor
    Complex operator + (const Complex& other) const
    /*Complex operation+(const Complex& b) const
    return type function name(parameters)*/
    {
        /*can also do it like this
        Complex result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
        this is more optimized*/
        return Complex(real+other.real, imag+other.imag);
    }
    friend void display(const Complex& c);
};
void display(const Complex &c)
{
    cout<<c.real<<"+"<<c.imag<<endl;
}
int main()
{
    Complex a(1,1);
    Complex b(2,3);
    Complex c;
    //c=a.operation(b)
    c=a+b;
    display(c);
    return 0;
}