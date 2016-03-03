#include "bst.h"

//*****************************************************************************
//*****************Class course************************************************
//*****************************************************************************

//Course is an object consisting of 4 strings and 2 integers. Functions for
//a course include, inputing the data into the object, copying the object, 
//getting the course name or number, and displaying the courses data 

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

//Insert calls its helper function to the actual recursion and insert a course
//into the BST
int Table::insert_course(Course &course)
{
    if(insert_helper(root, course) == 1) return 1;
    return 0;
}

//Insert helper is where the actual recursion takes place for inserting into
//the BST. Recursion runs until root is NULL. It will then insert a new root
//into the BST. Otherwise it checks whether it should travers left or right
//throughout the BST
int Table::insert_helper(node * &root, Course &course)
{
    if(!root)
    {
        root = new node;
        root->course.copy_course(course);
        root->left = NULL;
        root->right = NULL;
        return 1;
    }
    
    char * temp = new char[50];
    char * temp2 = new char[50];
    course.getNum(temp);
    root->course.getNum(temp2);
    
    if(strcmp(temp, temp2) < 0)
    {
        delete [] temp;
        delete [] temp2;
        return insert_helper(root->left, course);
    }

    if(strcmp(temp, temp2) >= 0)
    {
        delete [] temp;
        delete [] temp2;
        return insert_helper(root->right, course);
    }
}

//Should recieve a number to search for throughout the BST and an array of
//pointers to courses that it will fill. It will also recieve an integer for 
//keeping track of the number of matches found.
//TODO
int Table::retrieve_num(char * number, Course ** &courses)
{

    int count = 0;
    count = find_matches(number, root);
    if(count == 0) return 0;
    
    int index = 0;
    courses = new Course * [count];
    add_matches(number, courses, root, index);
    return count;
}

//Helper function for retrieve_num, finds the amount of matches within the BST
//so that an array can be sized to the amount of matches. 
int Table::find_matches(char * number, node * root)
{
    if(!root) return 0;
    
    char * temp = new char[50];
    root->course.getNum(temp);

    if(strcmp(number, temp) == 0)
    {
    
        return find_matches(number, root->left) + find_matches(number, 
        root->right) + 1;
    }
    
    return find_matches(number, root->left) + find_matches(number, root->right);

}

//Helper function for retrieve_num, given a string, an array of courses, the
//root of a BST, and a starting index; the function adds the matched course to
//the array and increments index after a match is found.
int Table::add_matches(char * number, Course ** &courses, node * root, int &index)
{
    if(!root) return 0;

    char * temp = new char[50];
    root->course.getNum(temp);

    if(strcmp(number, temp) == 0)
    {
        courses[index] = &root->course;
        ++index;
    }

    add_matches(number, courses, root->left, index);
    add_matches(number, courses, root->right, index);
    return index;
}

int Table::retrieve_range(char * lBound, char * uBound, Course ** &courses)
{

    int count = 0;
    count = find_matches(lBound, uBound, root);
    if(count == 0) return 0;
    
    int index = 0;
    courses = new Course * [count];
    add_matches(lBound, uBound, courses, root, index);
    return count;
}

int Table::find_matches(char * lBound, char * uBound, node * root)
{
    if(!root) return 0;

    char * temp = new char[50];
    root->course.getNum(temp);
    if(strcmp(lBound, temp) <= 0 && strcmp(uBound, temp) >= 0)
    {
        return find_matches(lBound, uBound, root->left) + find_matches
        (lBound, uBound, root->right) + 1;
    }

    return find_matches(lBound, uBound, root->left) + find_matches(lBound, uBound, root->right);
}

int Table::add_matches(char * lBound, char * uBound, Course ** &courses, node * root, int &index)
{
    if(!root) return 0;

    char * temp = new char[50];
    root->course.getNum(temp);

    if(strcmp(lBound, temp) <= 0 && strcmp(uBound, temp) >= 0)
    {
        courses[index] = &root->course;
        ++index;
    }
    
    add_matches(lBound, uBound, courses, root->left, index);
    add_matches(lBound, uBound, courses, root->right, index);
    return index;
}

//Display all function will call its helper function to do the actual recursion
//and display all the nodes in the BST.
int Table::display_all()
{
    if(!root) return 0;
    if(display_helper(root) == 1) return 1;
    return 0;
}

//Display all's helper function, recursively moves through the BST, displaying
//Node's data left to right.
int Table::display_helper(node * root)
{
    if(root)
    {
        display_helper(root->left);
        root->course.display_course();
        display_helper(root->right);
    }

    return 1;
}

//TODO
int Table::remove(char * number)
{

}

int Table::remove_all()
{
    return remove_all_helper(root);
}

int Table::remove_all_helper(node * &root)
{
    if(!root)return 0;
    
    remove_all_helper(root->left);
    remove_all_helper(root->right);    

    delete root;
    root = NULL;
    return 0;
}



