#include "table.h"

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

//*****************************************************************************
//*****************Table ADT Functions*****************************************
//*****************************************************************************

//Constructor for Table class. Initializes two hash tables, one for tracking 
//courses by name and one for tracking courses by number. Both will be of the
//same size
Table::Table(int size)
{
    hash_table_size = size;
    
    num_hash_table = new node * [size];
    for(int i = 0; i < size; ++i)
    {
        num_hash_table[i] = NULL;
    }
    
    name_hash_table = new node * [size];
    for(int i = 0; i < size; ++i)
    {
        name_hash_table[i] = NULL;
    }
}

//Destructor for the Table ADT, deallocates all memory for both hash tables
Table::~Table()
{
    node * head = NULL;
    node * temp = NULL;
    for(int i = 0; i < hash_table_size; ++i)
    {
        head = num_hash_table[i];
        while(head)
        {   
            temp = head;
            head = head->next;
            delete temp;
        }

        head = name_hash_table[i];
        while(head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }   
}

//Recieves a course, makes two copies, one copy for the course number and one
//copy for the course name. Uses the hash function to find an index for both
//the number copy and the name copy. Appends the number course copy to the 
//number hash table. Appends the name course copy to the name hash table. 
int Table::insert(Course &aCourse)
{
    char * cNum = new char[50];
    char * cName = new char[50];
    
    aCourse.getNum(cNum);
    aCourse.getName(cName);
    
    int index = hash_func(cNum);
    int index2 = hash_func(cName);
    
    node * temp = new node;
    node * temp2 = new node;
    
    if(!temp->course.copy_course(aCourse) || 
       !temp2->course.copy_course(aCourse))
    {
        delete temp;
        delete temp2;
        return 0;
    }

    temp->next = num_hash_table[index];
    num_hash_table[index] = temp;
    
    temp2->next = name_hash_table[index2];
    name_hash_table[index2] = temp2;
    return 1;
}

//Recieves a number to search for and a course to append to. Uses the hash
//function to find the index of the desired course number. It then iterates
//through the list at the array's index, checking if the supplied course 
//number matches data within the list. If so the course is copied to the 
//supplied course. If nothing is found 0 is returned. 
int Table::retrieveByNum(char * number, Course &course)
{
    int index = hash_func(number);
    node * current = num_hash_table[index];
    while(current)
    {
        char * temp = new char[50];
        current->course.getNum(temp);
        if(strcmp(temp, number) == 0)
        {
            course.copy_course(current->course);
            return 1;
        }

        delete [] temp;
    }
    return 0;
}

//Recieves a name to search for and a course to append to. Uses the hash
//function to find the index of the desired course name. It then iterates
//through the list at the array's index, checking if the supplied course 
//name matches data within the list. If so the course is copied to the 
//supplied course. If nothing is found 0 is returned. 
int Table::retrieveByName(char * name, Course &course)
{
    
    int index = hash_func(name);
    node * current = name_hash_table[index];
    while(current)
    {
        char * temp = new char[50];
        current->course.getName(temp);
        if(strcmp(temp, name) == 0)
        {
            course.copy_course(current->course);
            return 1;
        }

        delete [] temp;
    }
    return 0;
}

//Display Number is supplied a course number to search for. It iterates through
//the array, and then iterates through every list searchign for course's 
//matching the supplied course number. If a match is found it is displayed.
//If no matches are found returns 0.
int Table::display_number(char * number)
{
    node * current = num_hash_table[hash_func(number)];
    int count = 0;
    
    while(current)
    {
        if(current->course.number_match(number) == 1)
        {
            ++count;
            current->course.display_course();
        }
        
        current = current->next;
    }

    if(count > 0) return 1;
    return 0;
}

//Display all iterates through the number hash table, displaying all data 
//within. Since both hash tables have identical data, just stored at different
//indecis, only one of the hash tables has to be displayed to display all the
//data
int Table::display_all()
{
    node * current = NULL;

    for(int i = 0; i < hash_table_size; ++i)
    {
        current = num_hash_table[i];
        while(current)
        {
            current->course.display_course();
            current = current->next;
        }
    }    

    return 1;
}

//Hash function recieves a string and finds the length of the array, and 
//creates an int value based on each ascii value at each index of the array.
//It then returns this sum, modded by the size of the array so that the index
//returned will be within the bounds of the array.
int Table::hash_func(char * key) const
{
    int arrSize = strlen(key);
    int sum = 0;
    for(int i = 0; i < arrSize; ++i)
    {
        sum = sum + *(key + i);
    }
    return sum % hash_table_size;
}






