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

//Node object for the hash table's. Has a course for its data and a node 
//pointer
struct node
{
    Course course;
    node * next;
};

//The Table ADT handles two different hash tables, one for tracking courses by
//name and another for tracking courses by number. It has a hash function for 
//genereting keys and a size for the hash table's array. The table has a 
//constructor, a destructor, a function for inserting courses, a way to 
//retrieve a course by name or number, a display by course number and 
//function displaying all the data in a hash function.
class Table
{
public:
    Table(int size = 5);
    ~Table();
    int insert(Course &aCourse);
    int retrieveByNum(char * number, Course &course);
    int retrieveByName(char * name, Course &course);
    int display_number(char * number);
    int display_all();
private:
    node ** num_hash_table;
    node ** name_hash_table;
    int hash_func(char * key) const;
    int hash_table_size;
};
