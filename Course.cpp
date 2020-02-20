//
//  Course.cpp
//  A3
//
//  Created by Joe Smissen 
//

#include "Course.h"

long Course::nextCRN = 200;
//default constructor
Course::Course()
{
    CRN = nextCRN;
    nextCRN++;
    maxAvaliableSeats = 0;
    name = " ";
    departId = 0;
    assignedSeats = 0;
    isTaughtBy = 0;
}
//multi-arg constructor
Course::Course(string cn, long depId, long taughtBy, int maxSeat)
{
    CRN = nextCRN;
    nextCRN++;
    maxAvaliableSeats = maxSeat;
    name = cn;
    departId = depId;
    assignedSeats = 0;
    isTaughtBy = taughtBy;
}
//print function
void Course::print()
{
    cout << "Course: " << name << endl
    << "Course ID: " << CRN << endl;
}
//seat increment function
void Course::incAssSeats()
{
    assignedSeats++;
}
//instructor setter
void Course::setInstructor(long id)
{
    isTaughtBy = id;
}


