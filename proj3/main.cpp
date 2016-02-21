#include "table.h"

/*
    Course();
    ~Course();
    int create_course();
    int copy_course(const Course &copyFrom);
    int display_course();

    char * courseNum;
    char * courseName;
    int sectionNum;
    int CRN;
    char * courseSched;
    char * courseDesc;
*/

int main()
{
    Course myCourse;
    myCourse.create_course();
    myCourse.display_course();
    
    Table myTable;
    myTable.insert(myCourse);
    
    return 0;
}
