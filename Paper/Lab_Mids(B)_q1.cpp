#include <iostream>
using namespace std;

// Composition Passenger Class
class Passenger 
{
    int passengerID;
    string name;
    int age;

    public:
    Passenger(int id=0, string n="Unknown", int a=0) // Constructor
    {
        passengerID = id;
        name = n;
        age = a;
    }

    int getPassengerID() const 
    { 
        return passengerID; 
    }

    string getName() const 
    {
        return name; 
    }

    int getAge() const 
    { 
        return age; 
    }
};

// Aggregated Train Class
class Train 
{
    int trainNumber;
    string destination;
    int availableSeats;

    public:
    Train(int number, string dest, int seats)
    {
        trainNumber = number;
        destination = dest;
        availableSeats = seats;
    }

    int getTrainNumber() const 
    { 
        return trainNumber; 
    }

    string getDestination() const 
    { 
        return destination; 
    }

    int getAvailableSeats() const 
    {
        return availableSeats; 
    }

    void operator-(int seatsBooked) 
    {
        if (availableSeats >= seatsBooked) 
            availableSeats -= seatsBooked;
        else 
            cout << "Not enough seats available!" << endl;
    }
};

class Ticket 
{
    Passenger passenger;   
    Train* train;
    float ticketPrice;

    public:
    Ticket(Passenger p, Train* t, float price)
    {
        passenger = p;
        train = t;
        ticketPrice = price;
    }

    void operator+=(float discount) 
    {
        ticketPrice -= discount;
        if (ticketPrice < 0) 
            ticketPrice = 0;
    }

    void getTicketDetails() const 
    {
        cout << "\tTicket Details\n" << endl;
        cout << "Passenger ID: " << passenger.getPassengerID() << endl;
        cout << "Name: " << passenger.getName() << endl;
        cout << "Age: " << passenger.getAge() << endl;
        cout << "Train Number: " << train->getTrainNumber() << endl;
        cout << "Destination: " << train->getDestination() << endl;
        cout << "Ticket Price: $" << ticketPrice << endl;
        cout << "Seats Remaining: " << train->getAvailableSeats() << endl;
    }
};
int main() 
{
    Train t1(101, "Islamabad", 50);
    Train t2(202, "Lahore", 40);

    Passenger p1(1, "Obaid", 25);
    Passenger p2(2, "Maha", 30);

    t1 - 1;
    t2 - 1;

    Ticket ticket1(p1, &t1, 1000.0f);
    Ticket ticket2(p2, &t2, 1500.0f);

    ticket1 += 200.0f;  
    ticket2 += 300.0f;

    ticket1.getTicketDetails();
    ticket2.getTicketDetails();

    return 0;
}
