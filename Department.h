//
//  Department.h
//  A3
//
//  Created by Joe Smissen 
//

#ifndef Department_h
#define Department_h

#include <iostream>

using namespace std;

class Department
{
protected:
    long DepId;
    string name;
    string location;
    long chairId;
    static long nextDepartId;  // Should be Initialize to 100
public:
    Department();
    Department(string n, string l, long chair);
    void setChair(long id) { chairId = id; };
    void print();
    string getDeptName() {return name;}//name getter
    long getDeptId() { return DepId;}//deptid getter
};
#endif /* Department_h */
