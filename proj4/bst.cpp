#include "bst.h"

//*****************************************************************************
//*****************Class course************************************************
//*****************************************************************************
//Course constructor, sets all dynamic memory.
Course::Course()
{
    courseNum = new char[50];
    courseName = new char[50];
    sectionNum = 0;
    CRN = 0;
    courseSched = new char[100];
    courseDesc = new char[200];
}

//Course destructor deletes all dynamic memory within the course
Course::~Course()
{
    delete [] courseNum;
    delete [] courseName;
    delete [] courseSched;
    delete [] courseDesc;
}

//Create course prompts the user to enter in the required data for a course
int Course::create_course()
{
    cout << "Enter a course number: ";
    cin.get(courseNum, 50, '\n');
    cin.ignore(100, '\n');
    
    cout << "Enter a course Name: ";
    cin.get(courseName, 50, '\n');
    cin.ignore(100, '\n');
    
    cout << "Enter a section number: ";
    cin >> sectionNum;
    cin.ignore(100, '\n');
    
    cout << "Enter a CRN: ";
    cin >> CRN;
    cin.ignore(100, '\n');

    cout << "The class schedule should be in the form day/time " 
         << "(tue/thur 10:00-10:50)" << endl
         << "Enter the course schedule: ";
    cin.get(courseSched, 100, '\n');
    cin.ignore(100, '\n');
    
    cout << "Enter a course description: ";
    cin.get(courseDesc, 200, '\n');
    cin.ignore(200, '\n');
    cout << endl << endl << endl;

    return 1;
}

//Copy course checks if the current course being copied to has any data saved
//if there is data it deletes dynamic memory. It then creates memory enough
//to hold the data it is copying from. Then the current course data is copied 
//from the supplied course's data.
int Course::copy_course(const Course &copy_from)
{
    if(!copy_from.courseNum || !copy_from.courseName || 
       !copy_from.courseSched || !copy_from.courseDesc) return 0;
    
    if(courseNum) delete [] courseNum;
    if(courseName) delete [] courseName;
    if(courseSched) delete [] courseSched;
    if(courseDesc) delete [] courseDesc;
    
    courseNum = new char[strlen(copy_from.courseNum) + 1];
    courseName = new char[strlen(copy_from.courseName) + 1];
    courseSched = new char[strlen(copy_from.courseSched) + 1];
    courseDesc = new char[strlen(copy_from.courseDesc) + 1];

    strcpy(courseNum, copy_from.courseNum);
    strcpy(courseName, copy_from.courseName);
    strcpy(courseSched, copy_from.courseSched);
    strcpy(courseDesc, copy_from.courseDesc);
    sectionNum = copy_from.sectionNum;
    CRN = copy_from.CRN;
    return 1;
}

//Display course outputs all data within the course to the user
int Course::display_course()
{
   
    if(!courseNum || !courseName || !courseSched || !courseDesc) return 0;

    cout << courseNum << endl;
    cout << courseName << endl;
    cout << sectionNum << endl;
    cout << CRN << endl;
    cout << courseSched << endl;
    cout << courseDesc << endl;
    cout << endl;
    return 1;
}

//Get num returns 0 if the course number is NULL. Otherwise it copys the course
//number and saves it to the supplied string.
int Course::getNum(char * number)
{
    if(!courseNum) return 0;
    strcpy(number, courseNum);
    return 1;
}

//Get name returns 0 if the course name is NULL. Otherwise it copys the course
//name and saves it to the supplied string.
int Course::getName(char * name)
{
    if(!courseName) return 0;
    strcpy(name, courseName);
    return 1;
}

//Number match and name match both check if a supplied string matches the
//course's number or name
int Course::number_match(char * number)
{
    if(strcmp(number, courseNum) == 0) return 1;
    return 0;
}

int Course::name_match(char * name)
{
    if(strcmp(name, courseName) == 0) return 1;
    return 0;
}



//******************************************************************************
//*************************Table ADT********************************************
//******************************************************************************

//TODO
Table::Table()
{
    root = NULL;
}

//TODO
Table::~Table()
{

}

//TODO
int Table::insert_course(Course &course)
{

}

//TODO
int Table::retrieve_num(char * number, Course &course)
{

}

//TODO
int Table::retrieve_range(char * lBound, char * uBound, Course * courses)
{

}

//TODO
int Table::display_all()
{

}

//TODO
int Table::remove(char * number)
{

}

//TODO
int Table::remove_all()
{

}



