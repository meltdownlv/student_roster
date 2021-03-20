#include <iostream>
#include "Student.h"
using std::cout;
using std::endl;

Student::Student()
{
    student_id = "";
    first_name = "";
    last_name = "";
    email_address = "";
    age = 0;
    for (int i = 0; i < kNumCourses; ++i)
    {
        days_to_complete[i] = 0;
    }
    degree = DegreeType::BASKETWEAVING;
}

Student::Student(string student_id, string first_name, string last_name,
    string email_address, int age, int* days_to_complete, DegreeType degree)
{
    this->student_id = student_id;
    this->first_name = first_name;
    this->last_name = last_name;
    this->email_address = email_address;
    this->age = age;
    for (int i = 0; i < kNumCourses; ++i)
    {
        this->days_to_complete[i] = (days_to_complete[i]);
    }
    this->degree = degree;
}

// Getters
string Student::GetID()
{
    return student_id;
}

string Student::GetFirstName()
{
    return first_name;
}

string Student::GetLastName()
{
    return last_name;
}

string Student::GetEmail()
{
    return email_address;
}

int Student::GetAge()
{
    return age;
}

int* Student::GetDaysToComplete()
{
    return days_to_complete;
}

DegreeType Student::GetDegreeProgram()
{
    return degree;
}

// Setters
void Student::SetID(string new_id)
{
    student_id = new_id;
    return;
}

void Student::SetFirstName(string new_first_name)
{
    first_name = new_first_name;
    return;
}

void Student::SetLastName(string new_last_name)
{
    last_name = new_last_name;
    return;
}

void Student::SetEmail(string new_email)
{
    email_address = new_email;
    return;
}

void Student::SetAge(int new_age)
{
    age = new_age;
    return;
}

void Student::SetDaystoComplete(int* new_course_days)
{
    for (int i = 0; i < kNumCourses; ++i)
    {
        days_to_complete[i] = new_course_days[i];
    }

    return;
}

void Student::SetDegreeType(DegreeType new_degree_type)
{
    degree = new_degree_type;
    return;
}

void Student::SetDegreeType(int new_degree_type)
{
    switch (new_degree_type)
    {
    case 0:
        degree = DegreeType::SECURITY;
        break;
    case 1:
        degree = DegreeType::NETWORK;
        break;
    case 2:
        degree = DegreeType::SOFTWARE;
        break;
    default:
        degree = DegreeType::BASKETWEAVING;
    }

    return;
}

void Student::PrintAttributes()
{
    int* days_list = nullptr;

    cout << "ID: " << GetID() << "\tFirst: " << GetFirstName() << "\tLast: "
        << GetLastName() << "\tAge: " << GetAge();
    cout << "\t\tDays in Course: { ";
    days_list = GetDaysToComplete();

    for (int i = 0; i < kNumCourses; ++i)
    {
        if (i == kNumCourses - 1) cout << days_list[i] << " }";
        else cout << days_list[i] << ", ";
    }
    cout << "\tDegree: " << DegreeNames[(int)GetDegreeProgram()] << endl;
    return;
}

int Student::GetAvgDays()
{
    int avg{ 0 }, total_days{ 0 };

    for (int i = 0; i < kNumCourses; ++i)
    {
        total_days += days_to_complete[i];
    }
    avg = total_days / kNumCourses;
    return avg;
}

Student::~Student(){}