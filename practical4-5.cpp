/* Programmer : Hingu Pratham
   Aim : To compute student grades using polymorphism based on academic level
   Date : 14 April, 2025
*/

#include<iostream>
#include<vector>

using namespace std;

// Base class Student
class Student
{
protected:
    float mark; // To store student's mark
public:
    // Setter for marks
    void setMarks(float m)
    {
        mark = m;
    }

    // Pure virtual function to compute grade
    virtual string computeGrade() = 0;
};

// Derived class for Undergraduate students
class underGraduate : public Student
{
public:
    // Grade computation for UG
    string computeGrade() override
    {
        if(mark >= 90) return "Grade: A";
        else if(mark >= 80) return "Grade: B";
        else if(mark >= 70) return "Grade: C";
        else return "Fail";
    }
};

// Derived class for Postgraduate students
class postGraduate : public Student
{
public:
    // Grade computation for PG
    string computeGrade() override
    {
        if(mark >= 85) return "Grade: A";
        else if(mark >= 75) return "Grade: B";
        else if(mark >= 65) return "Grade: C";
        else return "Fail";
    }
};

int main()
{
    vector<Student*> students; // Vector to store pointers to Student objects

    int type, num; // To store type of student and number of students
    float mark;    // To store individual student mark

    // Input: number of students
    cout << "Enter the number of the students: ";
    cin >> num;

    // Loop to input and create student objects
    for(int i = 0; i < num; i++)
    {
        Student* s = nullptr; // Pointer to base class
        cout << "Enter type of Graduation (1 for UG OR 2 for PG): ";
        cin >> type;
        cout << "Enter the marks: ";
        cin >> mark;

        // Create appropriate object based on type
        if(type == 1)
        {
            s = new underGraduate();
        }
        else if(type == 2)
        {
            s = new postGraduate();
        }
        else
        {
            cout << "Invalid Input.. Skipping..." << endl;
            continue;
        }

        // Set marks and add to vector
        s->setMarks(mark);
        students.push_back(s);
    }

    // Display computed grades
    for(size_t i = 0; i < students.size(); i++)
    {
        cout << "Student(" << i + 1 << ") Grade: " << students[i]->computeGrade() << endl;
    }

    // Clean up dynamically allocated memory
    for(size_t i = 0; i < students.size(); i++)
        delete students[i];

    cout << endl;
    cout << "Pratham Hingu : 24CE039" << endl;

    return 0;
}
