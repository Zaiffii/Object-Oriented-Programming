#include<iostream>
using namespace std;

class complex {
    double real, imag;

public:
    // Constructor
    complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Arithmetic Operator Overload
    complex operator +(const complex& other) const;
    complex operator -(const complex& other) const;
    complex operator *(const complex& other) const;
    complex operator /(const complex& other) const;

    // Comparison Operator Overload
    bool operator >(const complex& other) const;
    bool operator <(const complex& other) const;
    bool operator ==(const complex& other) const;

    //Uniary Operator Overload
    complex operator +();
    complex operator -() ;  
    complex operator ++();
    complex operator --();

    // Friend function
    friend void display(const complex& obj);
};

// Define arithmetic operations
complex complex::operator +(const complex& other) const 
{
    return complex(real + other.real, imag + other.imag);
}

complex complex::operator -(const complex& other) const 
{
    return complex(real - other.real, imag - other.imag);
}

complex complex::operator *(const complex& other) const 
{
    return complex(real * other.real - imag * other.imag,
                   real * other.imag + imag * other.real);
}

complex complex::operator /(const complex& other) const 
{
    double denominator = other.real * other.real + other.imag * other.imag;
    return complex((real * other.real + imag * other.imag) / denominator,
                   (imag * other.real - real * other.imag) / denominator);
}

// Define comparison operations
bool complex::operator >(const complex& other) const 
{
    return (real>other.real && imag>other.imag);
}

bool complex::operator <(const complex& other) const 
{
    return (real<other.real && imag<other.imag);
}

bool complex::operator ==(const complex& other) const 
{
    return (real == other.real && imag == other.imag);
}

// Define uniary operations
complex complex::operator -()
{
    return complex(-real,-imag);
}   

complex complex::operator ++()
{
    return complex(++real,++imag);
}

complex complex::operator --()
{
    return complex(--real,--imag);
}

// Display function
void display(const complex& obj) 
{
    cout << obj.real << " + " << obj.imag << "i" << endl;
}

// Main function
int main() {
    complex c1(3, 4);
    complex c2(1, 2);

    complex c3 = c1 + c2;
    cout << "Addition: ";
    display(c3);

    complex c4 = c1 * c2;
    cout << "Multiplication: ";
    display(c4);

    if(c1>c2)
        cout<<"Yes";
    else
        cout<<"No";

    cout << "Original c1: ";
    display(c1);

    cout << "Unary -c1: ";
    display(-c1);

    ++c1;
    cout << "After ++c1: ";
    display(c1);

    --c1;
    cout << "After --c1: ";
    display(c1);
    return 0;
}
