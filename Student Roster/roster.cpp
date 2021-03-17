#include "roster.h"
#include <iostream>
#include "Roster.h"
#include "Student.h"
using std::cout;
using std::endl;

// Default roster constructor establishes 5 nullptr for kNumStudents
Roster::Roster()
{
    for (int i = 0; i < kNumStudents; ++i)
    {
        class_roster_array[i] = nullptr;
    }
}

int Roster::ParseAddStudent(std::string student_info)
{ /* Parse each student's info and dynamically allocate new object
   * idx_end will serve as index for end of field
   * idx_begin will serve as index for beginning char of field
   */
    size_t idx_end = student_info.find(",");
    string student_id = student_info.substr(0, idx_end);
    // Parse first name and assign to temp variable
    size_t idx_begin = idx_end + 1;
    idx_end = student_info.find(",", idx_begin);
    string first_name = student_info.substr(idx_begin, idx_end - idx_begin);
    // Parse last name and assign to temp variable
    idx_begin = idx_end + 1;
    idx_end = student_info.find(",", idx_begin);
    string last_name = student_info.substr(idx_begin, idx_end - idx_begin);
    // Parse last name and assign to temp variable
    idx_begin = idx_end + 1;
    idx_end = student_info.find(",", idx_begin);
    string email_address = student_info.substr(idx_begin, idx_end - idx_begin);
    // Parse age and cast to int value
    idx_begin = idx_end + 1;
    idx_end = student_info.find(",", idx_begin);
    int age = std::stoi(student_info.substr(idx_begin, idx_end - idx_begin));
    // Declare temp array outside loop and iterate to add days
    int days_to_complete[Student::kNumCourses];
    int DEGREE_ERROR{ 99 };
    for (size_t i = 0; i < Student::kNumCourses; ++i)
    {
        idx_begin = idx_end + 1;
        idx_end = student_info.find(",", idx_begin);
        days_to_complete[i] = std::stoi(student_info.substr(idx_begin, idx_end - idx_begin));
    }
    // Move index and check for DegreeType
    idx_begin = idx_end + 1;
    DegreeType degree_type;
    try
    {
        string degree_name = student_info.substr(idx_begin,
            student_info.length() - idx_begin);
        if (degree_name == "SECURITY") { degree_type = DegreeType::SECURITY; }
        else if (degree_name == "NETWORK") { degree_type = DegreeType::NETWORK; }
        else if (degree_name == "SOFTWARE") { degree_type = DegreeType::SOFTWARE; }
        else if (degree_name == "BASKETWEAVING") { degree_type = DegreeType::BASKETWEAVING; }
        else throw DEGREE_ERROR;
    }
    catch (int e)
    {
        cout << "Student doesn't have valid degree type.\n";
        cout << "Error: " << e << endl;
        return e;
    }

    // Dynamic allocation of student to our roster class
    class_roster_array[++current_student_idx] = new Student(student_id, first_name, last_name,
        email_address, age, days_to_complete, degree_type);
    return 0;
}

void Roster::PrintAll()
{
    for (int i = 0; i < kNumStudents; ++i)
    {
        if (i == 0)
        {
            cout << "\nDisplaying all current students" << endl;
        }
        if (class_roster_array[i])
        {
            class_roster_array[i]->PrintAttributes();
        }
    }
    return;
}

void Roster::Remove(std::string student_id)
{
    // if student not in roster -> Print The student with ID XX was not found
    // else we delete the student and set pointer to nullptr
    for (int i = 0; i < kNumStudents; ++i)
        if (class_roster_array[i])
        {
            if (class_roster_array[i]->GetID() == student_id)
            {
                cout << "\nRemoving student " << student_id << endl;
                delete class_roster_array[i];
                class_roster_array[i] = nullptr;
            }
        }
        else
        {
            cout << "\nRemoving " << student_id << " again" << endl;
            cout << "\nThe student with ID " << student_id
                << " was not found." << endl;
        }
    return;
}

void Roster::PrintAvgDays(std::string student_id)
{
    for (int i = 0; i < kNumStudents; ++i)
    {
        if (class_roster_array[i] && class_roster_array[i]->GetID() == student_id)
        {
            cout << "Student ID " << student_id << ", averages "
                << class_roster_array[i]->GetAvgDays() << " days in a course." << endl;

        }
        else if (!class_roster_array[i])
        {
            cout << "The student with ID " << student_id
                << " was not found." << endl;
        }
    }
    return;
}

void Roster::PrintInvalidEmails()
{// Valid email must include '@' and '.' but not ' '
    size_t found_at{ 0 }, found_dot{ 0 }, found_sp{ 0 };

    for (int i = 0; i < kNumStudents; ++i)
    {
        found_at = class_roster_array[i]->GetEmail().find("@", 0);
        found_dot = class_roster_array[i]->GetEmail().find(".", 0);
        found_sp = class_roster_array[i]->GetEmail().find(" ", 0);
        if (i == 0)
        {
            cout << "\nDisplaying invalid emails: " << endl << endl;
        }
        // If we have a valid email address skip the last 3 checks
        if ((found_at != string::npos) && (found_dot != string::npos) &&
            (found_sp == string::npos))
        {
            continue;
        }
        // Check if we didn't find '@'
        else if (found_at == string::npos)
        {
            cout << class_roster_array[i]->GetEmail() << " - missing an @ symbol." << endl;
        }
        // Check if we didn't find '.'
        else if (found_dot == string::npos)
        {
            cout << class_roster_array[i]->GetEmail() << " - missing a period." << endl;
        }
        // Check if we found a space
        else if (found_sp != string::npos)
        {
            cout << class_roster_array[i]->GetEmail() << " - no spaces allowed." << endl;
        }

    }
    return;
}

void Roster::PrintByDegree(DegreeType degree_type)
{
    for (int i = 0; i < kNumStudents; ++i)
    {
        if (i == 0)
        {
            cout << "\nShowing students in degree program: "
                << DegreeNames[(int)degree_type] << endl << endl;
        }
        if (class_roster_array[i]->GetDegreeProgram() == degree_type)
        {
            class_roster_array[i]->PrintAttributes();
        }
    }

    return;
}

Roster::~Roster()
{
    for (int i = 0; i < kNumStudents; ++i)
    {
        if (class_roster_array[i] == nullptr) { continue; }
        else
        {
            delete class_roster_array[i];
            class_roster_array[i] = nullptr;
        }
    }
}