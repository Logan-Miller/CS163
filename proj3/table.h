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
    int retrieveByNum(char &number);
    int retrieveByName(char &name);
    int display(char &number);
    int display_all();
private:
    node ** hash_table;
    int hash_func(char * key) const;
    int hash_table_size;
};
