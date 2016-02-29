#include "table.h"

int main()
{
  
    Table myTable;
    char response = '\n';
    bool running = true;
    Course course;

    cout << "This program allows you to search for classes either by course"
         << " name or course number. Additionally you are able to insert new"
         << " classes into the available list of classes";

    while(running)
    {
        cout << "What would you like to do?" << endl;
        cout << "(1) Add a course to the list of available courses" << endl
             << "(2) Find a course by course number" << endl
             << "(3) Find a course by course name" << endl
             << "(4) Display all courses by a course number" << endl
             << "(5) Display all courses" << endl
             << "(q) Enter q to quit" << endl;
        cout << "Enter your choice: ";
        cin >> response;
        cin.ignore(100, '\n');
        
        if(response == '1')
        {
            course.create_course();
            if(myTable.insert(course) == 0)
            {
                cout << "The course could not be saved" << endl;
            }
        }

        else if(response == '2')
        {
            char * to_insert = new char[50];
            cout << "Enter a course number to search for: ";
            cin.getline(to_insert, 50, '\n');
            cin.clear();
            if(myTable.retrieveByNum(to_insert, course) == 0)
            {
                cout << "No classes matched that number were found" << endl;          
            }
            course.display_course();
            
            delete [] to_insert;
        }

        else if(response == '3')
        {
            char * to_insert = new char[50];
            cout << "Enter a course name to search for: ";
            cin.getline(to_insert, 50, '\n');
            cin.clear();
            if(myTable.retrieveByName(to_insert, course) == 0)
            {
                cout << "No classes matching that name were found" << endl;          
            }
            course.display_course();
            delete [] to_insert;
        }

        else if(response == '4')
        {
            char * to_insert = new char[50];
            cout << "Enter a course number to display: ";
            cin.getline(to_insert, 50, '\n');
            cin.clear();

            if(myTable.display_number(to_insert) == 0)
            {
                cout << "There were no course matching that number" << endl;
            }
            
            delete [] to_insert;
        }

        else if(response == '5')
        {
            myTable.display_all();
        }

        else if(response == 'q')
        {
            running = false;
        }
        
        else
        {
            cout << "Please enter either choice 1 through 5 or q to quit'\n'";
        }
    }
         
    cout << "The program will now close" << endl;
    return 0;
}
