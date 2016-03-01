#include <iostream>
#include <cstring>
using namespace std;

//Course is an object that has 6 data values that determine what the course is
//Function include a constructor, a destructor, a way to create and enter in 
//the values to make the course, a copy function to copy in data from another
//course, a display function for the course's data, two getters for the course
//name and number, and two functions that check if an supplied string matches 
//either the course name or number
class Course
{
public:
    Course();
    ~Course();
    int create_course();
    int copy_course(const Course &copyFrom);
    int display_course();
    int getNum(char * number);
    int getName(char * name);
    int number_match(char * number);
    int name_match(char * name);

private:
    char * courseNum;
    char * courseName;
    int sectionNum;
    int CRN;
    char * courseSched;
    char * courseDesc;
};

struct node
{
    Course course;
    node * left;
    node * right;
};

//BST
class Table
{

public:
    Table();
    ~Table();
    int insert_course(Course &course);
    int retrieve_num(char * number, Course &course);
    int retrieve_range(char * lBound, char * uBound, Course * courses);
    int display_all();
    int remove(char * number);
    int remove_all();
private:
    node * root;
};
