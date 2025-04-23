#include<iostream>
using namespace std;
class Car
{
    int year;
    string model;
    string company;
    public:
    Car(int year=0, string model="Unknown", string company="Unknown")//Constructor for Car
    {
        this->year=year;
        this->model=model;
        this->company=company;
    }

    void setvalue(int year, string model, string company)
    {
        this->year=year;
        this->model=model;
        this->company=company;
    }

    void display()
    {
        cout<<"Year: "<<year<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Company: "<<company<<endl;
    }
};

class Mechanic
{
    string mechanic_name;
    int age;
    public:
   
    Mechanic(string name="Unknown", int age=18) //Constructor for Mechanic
    {
        mechanic_name=name;
        this->age=age;
    }

    void setvalue(string name, int age)
    {
        mechanic_name=name;
        this->age=age;
    }

    void display()
    {
        cout<<"Mechanic Name: "<<mechanic_name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

/*has a - relationship
Garage has a car 
Garage has a mechanic*/
class Garage
{
    Car* c;//Aggregation
    Mechanic* m;//Aggregation
    /*Objects are not being created here as compared to compostion but instead pointers are 
    created that point to the objects created in main*/

    string garage_name;
    string location;
    public:
    //Constructor for Garage
    Garage(string name="Unknown", string location="Unknown", Car* car=nullptr, Mechanic* mech=nullptr)
    {
        garage_name=name;
        this->location=location;
        c=car;
        m=mech;
    }

    void setvalue(string name, string location, Car* car, Mechanic* mech)
    {
        garage_name=name;
        this->location=location;
        c=car;
        m=mech;
    }


    //Now in order to print the full details of the garage
    void print()
    {
        cout<<"\tGarage Details:\n";
        cout<<"Garage Name: "<<garage_name<<endl;
        cout<<"Location: "<<location<<endl;

        //now we can print the values here because we have a pointer pointing at them
        cout<<"\tMechanic Details\n";
            (*m).display();//Printing details of mechanic m
            //m->display() can also write like this pointer to obj
        cout<<"\tCar Details\n";    
            (*c).display();//Printing details of car c
            //c->display() can also write like this pointer to obj
    }
};
int main()
{
    Garage g;
    Car c;
    Mechanic m;
    string garage_name, garage_location, mechanic_name, car_model, car_company;
    int mechanic_age, car_year;

    //Setting values for Car like normal
    cout<<"Enter your car year: ";
    cin>>car_year;
    cout<<"Enter your car model: ";
    cin>>car_model;
    cout<<"Enter your car compnay: ";
    cin>>car_company;
    c.setvalue(car_year,car_model,car_company);
    
    //Setting values for Mechanic like normal
    cout<<"Enter your Mechanic name: ";
    cin>>mechanic_name;
    cout<<"Enter your Mechanic age: ";
    cin>>mechanic_age;
    m.setvalue(mechanic_name,mechanic_age);

    //Setting values for Garage like normal
    cout<<"Enter your Garage name: ";
    cin>>garage_name;
    cout<<"Enter your Garage Location: ";
    cin>>garage_location;
    g.setvalue(garage_name,garage_location, &c, &m);
    //we gave the address of c(Car Obj) to *c and the address of m(Mechanic Obj) to *m

    /*The only difference will be that we can print the whole garage at the same time because
    we have pointers in garage class pointing towards Car & Mechanic Objects*/
    g.print();
}
/*Question: Difference between Composition and Aggregation?
Answer: In composition the child class objects cannot exist without the parent class
because they are declared inside the parent class.
In aggregation the child class can exist without the parent class because they are 
not declared inside the parent class they are declared in the main function 
only a pointer is declared inside the parent class that points towards the child class.*/