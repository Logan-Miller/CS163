//Logan Miller
//CS163
//Program #1 Vehicle_List ADT

//This program will make use of a vehicle_list class that will manage a LLL of
//vehicles

#include "client.h"

int main()
{
    //initializes the ADT that will manage the data structure
    Vehicle_List vehicles;
    char response = '\0';
   //Welcome screen for the user, displayed upon the programing opening.
   //gives the user a basic overview of what they can do, then gives the user
   //a choice of different options.
    cout << "Welcome, we have a wide variety of vehicles for you to look " 
         "through. Please feel free to browse" << endl;

    cout << "Choices available:" << endl;
    cout << "                 (1) See our full list of available vehicles.\n";
    cout << "                 (2) Search for a specific make/model.\n";
    cout << "                 (3) Input some things you would like to see in\n";
    cout << "                     a vehicle, and we'll show you what's right\n";
    cout << "                     for you.\n";
    cout << "Enter either option 1, 2 or 3. If you would like to quit\n";
    cout << "then simply type 'q'" << endl;
    cout << "Enter choice now: ";
    
    cin >> response;
    cin.ignore(100, '\n');

    //different checks for the user's response, runs desired function based
    //off of the user's choice
    if(response == '1')
    {
        if(!vehicles.sortMan())
        {
            cout << "I'm sorry, but it appears we have no vehicles in stock\n";
            cout << "currently, please try again later.";
        }
    }

    else if(response == '2')
    {
        searchForVehicle(vehicles);
    }
    
    else if(response == '3')
    {
        getFeatures(vehicles);
    }

    else if(response == 'q')
    {
        cout << "Thanks for stopping by." << endl;
        return 0;
    }

    else
    {
        cout << "thanks for using our program" << endl;
    }
    
    
    cout << "thanks for using our program" << endl;

    return 0;
}
