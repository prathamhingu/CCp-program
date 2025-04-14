
/*
   Programmer : Pratham Hingu
   Aim        : Dynamically manage employee salaries with real-time computation and flexible bonuses
   Date       : 24 February, 2025
*/

#include <iostream>
#include <vector>  // For using dynamic array (vector)

using namespace std;

// Employee class to store and manage individual employee details
class employee
{
    string name;
    double salary, bonus, total_salary;

public:
    // Constructor with default values
    employee(string n = "Unknown", double s = 2000, double b = 1000)
        : name(n), salary(s), bonus(b)
    {
        calculate_salary(); // Calculate total salary upon object creation
    }

    // Function to calculate total salary by adding bonus
    void calculate_salary()
    {
        total_salary = salary + bonus;
    }

    // Function to display employee details
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total salary: " << total_salary << endl;
        cout << "----------------------------" << endl;
    }
};

int main()
{
    // Vector to store a dynamic list of employee objects
    vector<employee> emp;

    // Adding employees using parameterized constructor
    emp.push_back(employee("Pratham Hingu", 5000, 2000));
    emp.push_back(employee("Riddham Lakkad", 7000, 3000));

    // Display details of all employees
    for (auto &i : emp)
    {
        i.display();
    }

    cout << endl;
    cout << "Pratham Hingu :: 24CE039" << endl;

    return 0;
}
