#pragma once
#include "Degree.h"
#include <iostream>
using std::string;

class Student
{
public:
    static const int kNumCourses{ 3 };
private:
    string student_id;
    string first_name;
    string last_name;
    string email_address;
    int age;
    int days_to_complete[kNumCourses];
    DegreeType degree;
public:
    Student();
    // Parameterized constructor
    Student(string student_id, string first_name, string last_name,
        string email_address, int age, int* days_to_complete, DegreeType degree);
    ~Student();
    // Getters
    string GetID();
    string GetFirstName();
    string GetLastName();
    string GetEmail();
    int GetAge();
    int* GetDaysToComplete();
    DegreeType GetDegreeProgram();
    int GetAvgDays();

    // Setters
    void SetID(string new_id);
    void SetFirstName(string new_first_name);
    void SetLastName(string new_last_name);
    void SetEmail(string new_email);
    void SetAge(int new_age);
    void SetDaystoComplete(int* new_course_days);
    void SetDegreeType(DegreeType new_degree_type);
    void SetDegreeType(int new_degree_type);

    void PrintAttributes();
};