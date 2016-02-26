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
  
    Table myTable;

    cout << "This program allows you to search for classes either by course"
         << " name or course number. Additionally you are able to insert new"
         << " classes into the available classes as well as ";
         //TODO
  
  /*  Course myCourse;
    myCourse.create_course();
    
    Course aCourse;
    aCourse.create_course();

    char * temp = new char[50];
    char * temp2 = new char[50];
    char * temp3 = new char[50];
    strcpy(temp, "11");
    strcpy(temp2, "11");
    strcpy(temp3, "22");

    Table myTable;
    myTable.insert(myCourse);
    myTable.insert(aCourse);
    
    cout << endl << "Displaying course" << endl << endl;
    
    myTable.display_all();
    
    cout << endl << endl << "Displaying courses with number '11'" << endl << endl;
    myTable.display_number(temp);
    
    cout << endl << endl << "retrieving course 1, and displaying " << endl << endl;
    myTable.retrieveByNum(temp2, aCourse);
    aCourse.display_course();
    
    cout << endl << endl << "retrieving course 2, and displaying " << endl << endl;
    myTable.retrieveByName(temp3, myCourse);
    myCourse.display_course();
    */
    

    /*char * temp = new char[50];
    strcpy(temp, "55");
    if(myTable.retrieveByNum(temp, aCourse)) cout << endl << "Found!" << endl;
    else cout << "not found" << endl;
    
    aCourse.display_course();*/
    
    //myTable.display_all();
    //char * temp = new char[50];
    //strcpy(temp,"22");
    //myTable.display_name(temp);

    
    return 0;
}
