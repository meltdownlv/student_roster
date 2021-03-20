#include <iostream>
#include "Roster.h"
using std::cout;
using std::endl;

void MyProjectInfo();

int main()
{

	const int num_students{ 5 };
	int i{ 0 };
	const string student_data[num_students] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	 "A5,Sakae,Watanabe,swatan3@wgu.edu,36,10,18,28,SOFTWARE" };

	MyProjectInfo();


	Roster class_roster;
	for (i = 0; i < num_students; ++i)
	{
		class_roster.ParseAddStudent(student_data[i]);
		if (i == num_students - 1) { cout << "\nDone parsing students." << endl; }
	}

	class_roster.PrintAll();
	class_roster.PrintInvalidEmails();

	string current_id{ "" };
	for (i = 0; i < num_students; ++i)
	{
		if (i == 0) { cout << endl; }
		current_id = "A" + std::to_string(i + 1);
		class_roster.PrintAvgDays(current_id);
	}

	class_roster.PrintByDegree(DegreeType::SOFTWARE);
	class_roster.Remove("A3");
	class_roster.PrintAll();
	class_roster.Remove("A3");

	cout << "\nDone!" << endl;
	return 0;
}

void MyProjectInfo()
{
	cout << "Student Roster Application" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 123456789" << endl;
	cout << "Name: Sakae Watanabe" << endl << endl;

	return;
}