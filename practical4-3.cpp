/* Programmer : Pratham Hingu
   Date : 07 April, 2025
   Aim : To manage car details using OOP with inheritance and simulate processing via a service queue
*/

#include<iostream>
#include<queue>
#include<string>
using namespace std;

// Base class representing fuel type
class Fuel
{
protected:
    string fuelName;
public:
    Fuel(string fuel) : fuelName(fuel) {};  // Constructor to initialize fuel name

    void displayFuel()
    {
        cout << "Fuel Name: " << fuelName << endl;
    }
};

// Base class representing brand name
class Brand
{
protected:
    string brandName;
public:
    Brand(string brand) : brandName(brand) {};  // Constructor to initialize brand name

    void displayBrand()
    {
        cout << "Brand Name: " << brandName << endl;
    }
};

// Derived class representing a car, inheriting from Fuel and Brand
class Car : public Fuel, public Brand
{
    string Model;  // Model of the car
public:
    // Constructor to initialize all attributes
    Car(string fuel, string brand, string model) : Fuel(fuel), Brand(brand), Model(model) {};

    // Display full car details
    void displayCar()
    {
        displayFuel();
        displayBrand();
        cout << "Model: " << Model << endl;
    }
};

int main()
{
    cout << "Using manual method::\n" << endl;

    // Creating and displaying car objects manually
    Car car1("Petrol", "Toyota", "Camry");
    Car car2("Diesel", "Ford", "F-150");
    Car car3("Electric", "Nissan", "Leaf");

    car1.displayCar();
    cout <<"---------------------------"<< endl;
    car2.displayCar();
    cout <<"---------------------------"<< endl;
    car3.displayCar();
    cout <<"---------------------------"<< endl;

    cout << "Using Queue::\n" << endl;

    // Using a queue to simulate car service processing
    queue<Car> carQueue;

    // Pushing cars into the queue
    carQueue.push(Car("Petrol", "Toyota", "Camry"));
    carQueue.push(Car("Diesel", "Ford", "F-150"));
    carQueue.push(Car("Electric", "Nissan", "Leaf"));

    // Display front car (first in queue)
    cout << "Front Car:\n";
    carQueue.front().displayCar();
    cout <<"---------------------------"<< endl;

    // Display back car (last in queue)
    cout << "\nBack Car:\n";
    carQueue.back().displayCar();
    cout <<"---------------------------"<< endl;

    // Display queue size
    cout << "\nSize: " << carQueue.size() << endl;

    // Remove the front car from queue (simulate service)
    carQueue.pop();
    cout << "\nAfter pop, Front Car:\n";
    carQueue.front().displayCar();
    cout <<"---------------------------"<< endl;

    // Display new queue size
    cout << "\nSize: " << carQueue.size() << endl;

    // Check if queue is empty
    if (carQueue.empty())
    {
        cout << "\nQueue of cars is empty.." << endl;
    }
    else
    {
        cout << "\nQueue of cars is not empty.." << endl;
    }

    cout<<endl;
    cout<<"Pratham Hingu : 24CE039"<<endl;

    return 0;
}
