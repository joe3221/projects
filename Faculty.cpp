//
//  Faculty.cpp
//  A3
//
//  Created by Joe Smissen 
//

#include "Faculty.h"

long Faculty::nextFacultyId = 600;
//default constructor
Faculty::Faculty()
{
    FacId = nextFacultyId;
    nextFacultyId++;
    name = email = address = dateOfBirth = gender = " ";
    salary = 0;
    yearOfExp = 0;
    depId = 0;
}
//multi arg constructor
Faculty::Faculty(string n, string e, string a, string d, string g, float s, int y, long dId)
{
    FacId = nextFacultyId;
    nextFacultyId++;
    name = n;
    email = e;
    address = a;
    dateOfBirth = d;
    gender = g;
    salary = s;
    yearOfExp = y;
    depId = dId;
    
}
//print function
void Faculty::print()
{
    cout << "Faculty Name: " << name << endl
    << "Faculty ID: " << FacId << endl;
}
