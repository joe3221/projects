//
//  Student.h
//  A3
//
//  Created by Joe Smissen 
//

#ifndef Student_h
#define Student_h
#include <iostream>
#include <fstream>
#include "Course.h"
#include <vector>


using namespace std;

class Student
{
protected:
    long StuId;
    string name;
    string email;
    string address;
    string dateOfBirth;
    string gender;
    int yearOfStudy;
    string major;
    long advisorId;
    vector<Course> coursesTaken;
    static long nextStId;  // initialize it to 500
public:
    Student();
    Student(string n, string e, string a, string d, string g, int y, string m, long adv_Id);
    void print();
    long getStuId() { return StuId;}//getter for student id
    int getYearOfStudy() { return yearOfStudy;}//getter for years of study
    string getMajor() { return major;}//getter for major
    long getAdvisiorId() { return advisorId;}//getter for advisor id
    void printCourses();
    void printCoursesFac(long facId);
    void addCourse(Course c);
};


#endif /* Student_hpp */
