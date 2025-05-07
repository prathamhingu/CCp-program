/* Programmer : Pratham Hingu
   Date : 04 April, 2025
   Aim : To manage and display employee and manager details using inheritance and a map for lookup by ID
*/

#include <iostream>
#include <map>
using namespace std;

class Person
{
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    void putP()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employees : public Person
{
protected:
    int ID;
public:
    Employees(string n, int a, int id) : Person(n, a), ID(id) {}
    void putE()
    {
        cout << "Id: " << ID << endl;
    }
};

class Manager : public Employees
{
    string department;
public:
    Manager(string n, int a, int id, string dept) : Employees(n, a, id), department(dept) {}
    void putM()
    {
        cout << "The department is: " << department << endl;
    }
};

int main()
{
    int empID;
    map<int, Manager*> managers;

    managers[101] = new Manager("Pratham Hingu", 18, 101, "Computer Engineering");
    managers[102] = new Manager("Riddham Lakkad", 18, 102, "Computer Engineering");

    for (const auto &pair : managers)
    {
        pair.second->putP();
        pair.second->putE();
        pair.second->putM();
        cout << endl;
    }

    cout << "Enter the Employee id to find details: ";
    cin >> empID;

    if (managers.find(empID) != managers.end())
    {
        cout << "\nEmployee Details::" << endl;
        managers[empID]->putP();
        managers[empID]->putE();
        managers[empID]->putM();
    }
    else
    {
        cout << "No employee found with " << empID << " ID.." << endl;
    }

    cout<<endl;
    cout<<"Pratham Hingu : 24CE039"<<endl;

    return 0;
}
