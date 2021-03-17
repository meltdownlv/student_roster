#pragma once
#include "Student.h"

class Roster
{
private:
    static const int kNumStudents{ 5 };
    Student* class_roster_array[kNumStudents];
    int current_student_idx = -1;
public:
    Roster();
    int ParseAddStudent(std::string student_info);
    void PrintAll();
    void Remove(std::string student_id);
    void PrintAvgDays(std::string student_id);
    void PrintInvalidEmails();
    void PrintByDegree(DegreeType degree_type);
    ~Roster();
};