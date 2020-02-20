//
//  Department.cpp
//  A3
//
//  Created by Joe Smissen 
//

#include "Department.h"

long Department::nextDepartId = 100;
//default constructor
Department::Department() {
    DepId = nextDepartId;
    nextDepartId++;
    name = " ";
    location = " ";
    chairId = 0;
}
//multi-arg constructor
Department::Department(string n, string l, long chair)
{
    DepId = nextDepartId;
    nextDepartId++;
    name = n;
    location = l;
    chairId = chair;
}
//print function
void Department::print()
{
    cout << "Department: " << name << endl
    << "Dept ID: " << DepId << endl;
}
