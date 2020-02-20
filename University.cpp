//
//  University.cpp
//  A3
//
//  Created by Joe Smissen
//

#include "University.h"

bool University::failure = false;
bool University::success = true;

//**********************************************************************************************
//----------------------------------------------------------------------------
//the constructor is purposely left empty since class university has noting
//to instantiate
University::University()
{
    
}
//----------------------------------------------------------------------------
//the destructor is purposely left empty since class university has noting
//to instantiate
University::~University()
{
    
}
//----------------------------------------------------------------------------
//this metod creates a new department object and inserts it into the department vector
//parameters: depName-name of dept, depLoc-location of department, depChair-id of chair of dept
bool University::CreateNewDepartment(string depName, string depLoc, long depChairId)
{
    if(depChairId == 0)//if dept chair is 0 make it zero
    {
        Department d(depName, depLoc, depChairId);
        Departments.push_back(d);
        return success;
    }
    else // if its anything else check to make sure that faculty member exists
    {
        for(int i = 0; i < Faculties.size(); i++)
        {
            if(Faculties[i].getFacultyId() == depChairId)
            {
                Department d(depName, depLoc, depChairId);
                Departments.push_back(d);
                return success;
            }
        }
        cout << "Faculty Chair ID does not exist" << endl;
        return failure;
    }
    
}

//----------------------------------------------------------------------------
// this method creades a student object and inserts it into student vector
//parameters: sname-student name, semail, student email, saddress, student address, sdateofbirth-student dob,
//sgender- student gender, syearofstudy-how many years student has been at uni, sadvisorid-student's advsor id
bool University::CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender,
                                  int sYearOfStudy, string sMajor, long sAdvisorId)
{
    if(sMajor == "0" && sAdvisorId == 0)// if the major and advisor are 0 make it that
    {
        Student s(sName, sEmail, sAddress, sDateOfBirth, sGender, sYearOfStudy, sMajor, sAdvisorId);
        Students.push_back(s);
        return success;
    }
    
    if(sMajor == "0" && sAdvisorId != 0)//if major is 0 and advisor is not check if advisor exists
    {
        for(int i = 0; i < Faculties.size(); i++)
        {
            if(Faculties[i].getFacultyId() == sAdvisorId)
            {
                Student s(sName, sEmail, sAddress, sDateOfBirth, sGender, sYearOfStudy, sMajor, sAdvisorId);
                Students.push_back(s);
                return success;
            }
        }
        cout << "Student cannot be added since their faculty advisior does not exist!" << endl;
        return failure;
    }
    
    if(sMajor != "0" && sAdvisorId == 0)//if major is not zero check if major exists
    {
        for(int i = 0; i < Departments.size(); i++)
        {
            if(Departments[i].getDeptName() == sMajor)
            {
                Student s(sName, sEmail, sAddress, sDateOfBirth, sGender, sYearOfStudy, sMajor, sAdvisorId);
                Students.push_back(s);
                return success;
            }
        }
        cout << "Student cannot be added since their major does not exist!" << endl;
        return failure;
    }
    
    if(sMajor != "0" && sAdvisorId != 0)//if major and advisor are not zero check if both exist
    {
        for(int i = 0; i < Faculties.size(); i++)
        {
            if(Faculties[i].getFacultyId() == sAdvisorId)
            {
                for(int j = 0; j < Departments.size(); j++)
                {
                    if(Departments[j].getDeptName() == sMajor)
                    {
                        Student s(sName, sEmail, sAddress, sDateOfBirth, sGender, sYearOfStudy, sMajor, sAdvisorId);
                        Students.push_back(s);
                        return success;
                    }
                }
                
            }
        }
        cout << "Student could not be added since their faculty advisor or major does not exist!" << endl;
        return failure;
    }
    
    else//if its none of the above cases print error return fail
        cout << "Student Could Not be added!" << endl;
        return failure;
    
}

//----------------------------------------------------------------------------
//this method creates a new course object and inserts it into the course vector
//params: cname- course name, cdepid- course dept id, ctaughtby- course teacher's id, cmaxseat-maxseats in class
bool University::CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{
    if(cTaughtBy == 0)//if teacher is not decided (0) then input it that way
    {
        for(int i = 0; i < Departments.size(); i++)
        {
            if(Departments[i].getDeptId() == cDepId)//check to make sure dept exists
            {                                       //and print error if it doesn't
                Course c(cName, cDepId, cTaughtBy, cMaxSeat);
                Courses.push_back(c);
                return success;
            }
        }
        cout << "Course cannot be added since course dept does not exist!" << endl;
        return failure;
    }
    else//if course has assigned faculty then make sure faculty exists
    {   //and make sure department also exists
        for(int i = 0; i < Faculties.size(); i++)
        {
            if(Faculties[i].getFacultyId() == cTaughtBy)
            {
                for(int j = 0; j < Departments.size(); j++)
                {
                    if(Departments[j].getDeptId() == cDepId)
                    {
                        Course c(cName, cDepId, cTaughtBy, cMaxSeat);
                        Courses.push_back(c);
                        return success;
                    }
                }
            }
        }
    }
    
    cout << "Course cannot be added since faculty member or course dept does not exist!" << endl;
    return failure;
}

//----------------------------------------------------------------------------
//this method creates a new faculty object and inserts it into the faculty vector
//fname-faculty name, femail, faculty email, faddress,faculty address, fdateofbirth-faculty dob,
//fgender- faculty gender, fsalary- faculty salary, fyearofexp- faculty year of exp, fdepid- id of dept faculty is in
bool University::CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender,
                                  float fSalary, int fYearOfExp, long fDepId)
{
    for(int i = 0; i < Departments.size(); i++)//check to see if dept exists
    {
        if(Departments[i].getDeptId() == fDepId)
        {
            Faculty f(fName, fEmail, fAddress, fDateOfBirth, fGender, fSalary, fYearOfExp, fDepId);
            Faculties.push_back(f);
            return success;
        }
    }//if not fail and print error
    cout << "Faculty cannot be added since their dept does not exist!" << endl;
    return failure;;
}

//----------------------------------------------------------------------------
//this method prints the courses taught by a specific faculty
//param: facultyid- faculty's id
bool University::ListCoursesTaughtByFaculty(long facultyId)
{
    for(int i = 0; i < Faculties.size(); i++)//check to see if faculty exists
    {
        if(Faculties[i].getFacultyId() == facultyId)
        {
            cout << facultyId << ": teaches: " << endl;
            for(int j = 0; j < Courses.size(); j++)//search for the courses taught by the faculty member
            {
                if(Courses[j].getTaughtId() == facultyId)
                {
                    Courses[j].print();
                    return success;
                }
            }
            
        }
    }
    //or fail if the faculty does not exist
    cout << "Cannot print courses taught by: " << facultyId << " since they do not exist!" << endl;
    return failure;
    
}
//----------------------------------------------------------------------------
//This method lists all the courses (courseId and CourseName)
//that currently taken by a particular student
//param: studentid- students id
bool University::ListCoursesTakenByStudent(long studentId)
{
    for(int i = 0; i < Students.size(); i++)//check if student exists
    {
        if(Students[i].getStuId() == studentId)
        {
            Students[i].printCourses();
            return success;
        }
    }
    //if student does not exist print error and fail
    cout << "Cannot print courses taken by: " << studentId << " since they do not exist!" << endl;
    return failure;
}
//----------------------------------------------------------------------------
//this method lists all the faculties (facultyId, facultyName) in a particular
//department
//param: departid - department's id
bool University::ListFacultiesInDepartment(long departId)
{
    for(int i = 0; i < Departments.size(); i++)//check if dept exists
    {
        if(Departments[i].getDeptId() == departId)
        {
            cout << "Department: " << Departments[i].getDeptName() << " has these faculty: " << endl;
            
            for(int j = 0; j < Faculties.size(); j++)//search for the faculy in that depy
            {
                if(Faculties[j].getFacultyDeptId() == departId)
                {
                    Faculties[j].print();
                }
            }
            return success;
        }
    }//if dept does not exist print error and fail
    cout << "Department faculty cannot be printed since department does not exist!" << endl;
    return failure;
}
//----------------------------------------------------------------------------
//lists all the students (studentId and studentName) of a particular
//faculty
//param: facultyid - id of faculty
bool University::ListStudentsOfAFaculty(long facultyId)
{
    
    for(int i = 0; i < Faculties.size(); i++)//check if faculty member exists
    {
        if(Faculties[i].getFacultyId() == facultyId)
        {
            cout << "Faculty: " << facultyId << " has these students: " << endl;
            
            for(int j = 0; j < Students.size(); j++)//search for students with faculty as advisior
            {                                       //or professor
                if(Students[j].getAdvisiorId() == facultyId)
                {
                    cout << "This student has the faculty as an advisor:" << endl;
                    Students[j].print();
                }
                cout << "These students have the faculty as a professor: " << endl;
                Students[j].printCoursesFac(facultyId);
            }
            return success;
        }
    }//if faculty member does not exist print error and fail
    cout << "Students of faculty cannot be printed since faculty member does not exist!" << endl;
    return failure;
}
//----------------------------------------------------------------------------
//this method lists all the courses offered by a particular department
//param: departid- departments id
bool University::ListCoursesOfADepartment(long departId)
{
    for(int i = 0; i < Departments.size(); i++)//check if dept exists
    {
        if(Departments[i].getDeptId() == departId)
        {
            cout << Departments[i].getDeptName() << " department has these courses:" << endl;
            for(int j = 0; j < Courses.size(); j++)//search for the courses offered by the dept
            {
                if(Courses[j].getCourseDept() == departId)
                {
                    Courses[j].print();
                }
            }
        }
    }//if dept does not exist then print error and fail
    cout << " The courses of the department could not be printed since the department does not exist!" << endl;
    return failure;
}
//----------------------------------------------------------------------------
//this method adds a course for a student
//param: courseid-course to be added, stid-students recieving the course
bool University::AddACourseForAStudent(long courseId, long stId)
{
    for(int i = 0; i < Courses.size(); i++)//check to see if course exists
    {
        if((Courses[i].getCRN() == courseId) && (Courses[i].getAssSeats() < Courses[i].getMaxSeats()))
        {
            for(int j = 0; j < Students.size(); j++)
            {
                if(Students[j].getStuId() == stId)//see if student exists and add the course to their course vector
                {
                    Courses[i].incAssSeats();
                    Students[j].addCourse(Courses[i]);
                    return success;
                }
            }
        }
    }//if course or student do not exist then print error and fail
    cout << "Course could not be added to student since course or student does not exist!" << endl;
    return failure;
}
//----------------------------------------------------------------------------
//this method adds a chair to a dept
//param; facultyid- if of faculty, departid-id of department
bool University::AssignDepartmentChair(long facultyId, long departId)
{
    
    for(int i = 0; i < Faculties.size(); i++)//check if faculty member exists
    {
        if(Faculties[i].getFacultyId() == facultyId)
        {
            for(int j = 0; j < Departments.size(); j++)
            {
                if(Departments[i].getDeptId() == departId)//check if dept exits set chair
                {
                    Departments[i].setChair(facultyId);
                    return success;
                }
            }
        }
    }//if dept or faculty do not exist print error and fail
    cout << "Faculty to be set to chair does not exist!";
    return failure;
}
//----------------------------------------------------------------------------
//this mehtod assigns a course to an instructor
//param: facultyid-faculty to get course, courseid- course faculty gets
bool University::AssignInstructorToCourse(long facultyId, long courseId)
{
    for(int i = 0; i < Faculties.size(); i++)//check to see if faculty member exists
    {
        if(Faculties[i].getFacultyId() == facultyId)
        {
            for(int j = 0; j < Courses.size(); j++)//check if course exists and set course
                if(Courses[i].getCRN() == courseId)//teacher to one specified
                {
                    Courses[i].setInstructor(courseId);
                    return success;
                }
        }
    }//if faculty or course do not exist print error and fail
    cout << "Faculty could not be assigned to course since they or course does not exist" << endl;
    return failure;
}
//----------------------------------------------------------------------------
//this method lists the departments names and ids
bool University::ListDepartments()
{
    cout << "Departments: " << endl;
    for(int i = 0; i < Departments.size(); i++)
    {
        Departments[i].print();
    }
    return success;
}
//----------------------------------------------------------------------------
//this method lists the students names and ids
bool University::ListStudents()
{
    cout << "Students: " << endl;
    for(int i = 0; i < Students.size(); i++)
    {
        Students[i].print();
    }
    return success;
}
//----------------------------------------------------------------------------
//this method lists the course names and ids
bool University::ListCourses()
{
    cout << "Courses: " << endl;
    for(int i = 0; i < Courses.size(); i++)
    {
        Courses[i].print();
    }
    return success;
}
//----------------------------------------------------------------------------
//this method lists the faculty names and ids
bool University::ListFaculties()
{
    cout << "Faculties: " << endl;
    for(int i = 0; i < Faculties.size(); i++)
    {
        Faculties[i].print();
    }
    return success;
}

//----------------------------------------------------------------------------
//this method controls all aspects of creating and printing objects
//param: filename-transaction file with controls
bool University::ProcessTransactionFile(string fileName)
{
    /*
     - open the transaction file and process it one by one
     - If the file could not be opened, print appropriate message and return failure;
     otherwise, return success
     */
    fstream fin;
    fin.open(fileName.data());
    string cmd;
    string name, loc, email, address, dob, gender, major;
    long id, faculty, student, course, department, taughtBy;
    int yos, maxSeat, yoe;
    float salary;
    if(!fin)
        cout << "Check directory file does not exist" << endl;
    
    while(fin >> cmd)
    {
        if(cmd == "CreateNewDepartment")
        {
            fin >> name >> loc >> id;
            CreateNewDepartment(name, loc, id);
        }
    
        if(cmd == "CreateNewStudent")
        {
            fin >> name >> email >> address >> dob >> gender >> yos >> major >> id;
            CreateNewStudent(name, email, address, dob, gender, yos, major, id);
        }
        
        if(cmd == "CreateNewCourse")
        {
            fin >> name >> department >> taughtBy >> maxSeat;
            CreateNewCourse(name, department, taughtBy, maxSeat);
        }
        
        if(cmd == "CreateNewFaculty")
           {
               fin >> name >> email >> address >> dob >> gender >> salary >> yoe >> department;
               CreateNewFaculty(name, email, address, dob, gender, salary, yoe, department);
           }
        
        if(cmd == "ListCoursesTaughtByFaculty")
        {
            fin >> faculty;
            ListCoursesTaughtByFaculty(faculty);
        }
        
        if(cmd == "ListCoursesTakenByStudent")
        {
            fin >> student;
            ListCoursesTakenByStudent(student);
        }

        if(cmd == "ListFacultiesInDepartment")
        {
            fin >> department;
            ListFacultiesInDepartment(department);
        }
        
        if(cmd == "ListStudentsOfAFaculty")
        {
            fin >> faculty;
            ListStudentsOfAFaculty(faculty);
        }
        
        if(cmd == "ListCoursesOfADepartment")
        {
            fin >> department;
            ListCoursesOfADepartment(department);
        }
        
        if(cmd == "AddACourseForAStudent")
        {
            fin >>course >> student;
            AddACourseForAStudent(course, student);
        }
        
        if(cmd == "AssignDepartmentChair")
        {
            fin >> faculty >> department;
            AssignDepartmentChair(faculty, department);
        }
        
        if(cmd == "AssignInstructorToCourse")
        {
            fin >> faculty >> course;
            AssignInstructorToCourse(faculty, course);
        }
        
        if(cmd == "ListDepartments")
        {
            ListDepartments();
        }
        
        if(cmd == "ListStudents")
        {
            ListStudents();
        }
        
        if(cmd == "ListCourses")
        {
            ListCourses();
        }
        
        if(cmd == "ListFaculties")
        {
            ListFaculties();
        }
        
        
        
        
    }
    return success;
}
