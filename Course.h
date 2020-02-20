//
//  Course.h
//  A3
//
//  Created by Joe Smissen 
//

#ifndef Course_h
#define Course_h
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Course
{
protected:
    long CRN;
    int maxAvaliableSeats;
    string name;
    long departId;
    long assignedSeats;
    long isTaughtBy;
    static long nextCRN; // initialize it to 200
public:
    Course();
    Course(string cn, long depId, long taughtBy, int maxSeat);
    void print();
    long getTaughtId() {return isTaughtBy;}//istaughtby geter
    long getCRN() {return CRN;}//crn getter
    string getCourseName() {return name;}//name getter
    long getCourseDept() {return departId;}//deptid getter
    int getMaxSeats() {return maxAvaliableSeats;}//maxseats getter
    long getAssSeats() {return assignedSeats;}//assigned seats getter
    void incAssSeats();
    void setInstructor(long id);
};
#endif /* Course_hpp */
