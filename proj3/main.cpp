#include "table.h"

//This program allows the user to create courses by entering in all the
//required course data, save that course, display all courses saved, search
//for a course by course name or number, or display all courses matching a
//desired course number.
int main()
{
  
    Table myTable;
    char response = '\n';
    bool running = true;
    Course course;

    //Welcome screen for the user outlinning what they are able to do
    cout << "This program allows you to search for classes either by course"
         << " name or course number. Additionally you are able to insert new"
         << " classes into the available list of classes";

    //The program mainly runs in this while loop, this allows the user to
    //continually add, search and display
    while(running)
    {
        //Prompt for the user, gives them choices to select from
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
        
        //First case, if choosen has the user create a course and then inserts
        //the course into the table
        if(response == '1')
        {
            course.create_course();
            if(myTable.insert(course) == 0)
            {
                cout << "The course could not be saved" << endl;
            }
        }

        //Second case if the choosen the user can search for a course by
        //number
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

        //Third case if the choosen the user can search for a course by name
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

        //Fourth choice, if choosen the user can display all courses matching 
        //a course number
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

        //Fifth choice, if choosen displays all saved courses.
        else if(response == '5')
        {
            myTable.display_all();
        }

        //the stop case to end the program
        else if(response == 'q')
        {
            running = false;
        }
        
        //Prompt in case something not matching the above choices was entered
        else
        {
            cout << "Please enter either choice 1 through 5 or q to quit'\n'";
        }
    }
         
    //Closing screen for the program
    cout << "The program will now close" << endl;
    return 0;
}
