//
//  Faculty.h
//  A3
//
//  Created by Joe Smissen on 
//

#ifndef Faculty_h
#define Faculty_h
#include <vector>
#include <iostream>

using namespace std;

class Faculty
{
protected:
    long FacId;
    string name;
    string email;
    string address;
    string dateOfBirth;
    string gender;
    float salary;
    int yearOfExp;
    long depId;
    static long nextFacultyId; // initialize it to 600
public:
    Faculty();
    Faculty(string n, string e, string a, string d, string g, float s, int y, long dId);
    void print();
    long getFacultyId() {return FacId;}//getter for faculty id
    long getFacultyDeptId() {return depId;}//getter for faculty dept id
};
#endif /* Faculty_hpp */
