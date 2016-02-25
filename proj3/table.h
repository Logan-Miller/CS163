#include <iostream>
#include <cstring>
using namespace std;

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
    node * next;
};

class Table
{
public:
    Table(int size = 5);
    ~Table();
    int insert(Course &aCourse);
    int retrieveByNum(char * number, Course &course);
    int retrieveByName(char * name, Course &course);
    int display_number(char * number);
    //int display_name(char * name);
    int display_all();
private:
    node ** num_hash_table;
    node ** name_hash_table;
    int hash_func(char * key) const;
    int hash_table_size;
};
