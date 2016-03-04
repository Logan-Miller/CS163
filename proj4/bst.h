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

//Node object are used to construct a BST. They have some data (a course) as
//well as a left and right node pointer.
struct node
{
    Course course;
    node * left;
    node * right;
};

//Table is an object for creating, inserting, searching and deleting from a BST
//It has functions to insert a course to the BST, retrieve courses based on
//their course number, retrieve courses based on a range of course numbers, to
//display all data within the BST, to remove a course based on a search term 
//from the BST, and to delete all data within the BST.
class Table
{

public:
    Table();
    ~Table();
    int insert_course(Course &course);
    int retrieve_num(char * number, Course ** &course);
    int retrieve_range(char * lBound, char * uBound, Course ** &courses);
    int display_all();
    int remove(char * number);
    int remove_all();
private:
    node * root;
    int insert_helper(node * &root, Course &course);
    int display_helper(node * root);
    int find_matches(char * number, node * root);
    int find_matches(char * lBound, char * uBound, node * root);
    int add_matches(char * number, Course ** &courses, node * root, int &index);
    int add_matches(char * lBound, char * uBound, Course ** &courses, node * root, int &index);
    int remove_helper(char * number, node * &root);
    int remove_all_helper(node * &root);
};







