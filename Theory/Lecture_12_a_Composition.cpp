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
    Car c;//Composition
    Mechanic m;//Composition
    string garage_name;
    string location;
    public:
    //Constructor for Garage
    Garage(string name="Unknown", string location="Unknown")
    {
        garage_name=name;
        this->location=location;
    }

    void setvalue(string name, string location)
    {
        garage_name=name;
        this->location=location;
    }

    //Now in order to set the values for car and mechanic
    void setcar(int year, string model, string company)
    {
        c.setvalue(year, model, company);
    }

    void setmechanic(string name, int age)
    {
        m.setvalue(name, age);
    }

    //Now in order to print the full details of the garage
    void print()
    {
        cout<<"\tGarage Details:\n";
        cout<<"Garage Name: "<<garage_name<<endl;
        cout<<"Location: "<<location<<endl;

        //Now here we cannot directly write this because it's data members are private we will use get set func and call it here
        cout<<"\tMechanic Details\n";
            m.display();//Printing details of mechanic m
        cout<<"\tCar Details\n";    
            c.display();//Printing details of car c
    }
};
int main()
{
    Garage g;
    string garage_name, garage_location, mechanic_name, car_model, car_company;
    int mechanic_age, car_year;

    //Setting values for Car
    cout<<"Enter your car year: ";
    cin>>car_year;
    cout<<"Enter your car model: ";
    cin>>car_model;
    cout<<"Enter your car compnay: ";
    cin>>car_company;
    g.setcar(car_year,car_model,car_company);
    
    //Setting values for Mechanic
    cout<<"Enter your Mechanic name: ";
    cin>>mechanic_name;
    cout<<"Enter your Mechanic age: ";
    cin>>mechanic_age;
    g.setmechanic(mechanic_name,mechanic_age);

    //Setting values for Garage
    cout<<"Enter your Garage name: ";
    cin>>garage_name;
    cout<<"Enter your Garage Location: ";
    cin>>garage_location;
    g.setvalue(garage_name,garage_location);

    //Printing the details
    g.print();
}
/*Question: Difference between Composition and Aggregation?
Answer: In composition the child class objects cannot exist without the parent class
because they are declared inside the parent class.
In aggregation the child class can exist without the parent class because they are 
not declared inside the parent class they are declared in the main function 
only a pointer is declared inside the parent class that points towards the child class.*/