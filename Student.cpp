//
//  Student.cpp
//  A3
//
//  Created by Joe Smissen 
//

#include "Student.h"


long Student::nextStId = 500;  // initialize it to 500
//default constructor
Student::Student()
{
    StuId = nextStId;
    nextStId++;
    name = email = address = dateOfBirth = major = gender = " ";
    yearOfStudy = 0;
    advisorId = 0;
}
//-----------------
//multi-arg constructor
Student::Student(string n, string e, string a, string d, string g, int y, string m, long advId)
{
    StuId = nextStId;
    nextStId++;
    name = n;
    email = e;
    address = a;
    dateOfBirth = d;
    gender = g;
    yearOfStudy = y;
    major = m;
    advisorId = advId;
}
//-----------------
//print function
void Student::print()
{
    cout << "Name: " << name << endl;
    cout << "StuId: " << StuId << endl;
}
//student course print function
//prints out courses taken by certain student
void Student::printCourses()
{
    cout << "Student: " << StuId << " takes: " << endl;
    for(int i = 0; i < coursesTaken.size(); i++)
    {
        coursesTaken[i].print();
    }
}

//prints the coursed taken with a certain faculty
void Student::printCoursesFac(long facId)
{
    for(int i = 0; i < coursesTaken.size(); i++)
        if(coursesTaken[i].getTaughtId() == facId)
        {
            coursesTaken[i].print();
        }
}
//adds a course to the student course vector
void Student::addCourse(Course c)
{
    coursesTaken.push_back(c);
}






