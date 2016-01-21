//Logan Miller
//CS163
//Program #1 Vehicle_List ADT

#include "client.h"

//getFeatures interacts with the user to get things that they want in a car
//as well as thigns they don't want in a car. It then supplies these two 
//data structures to the ADT
void getFeatures(Vehicle_List &vehicles)
{
    char * wanted = new char[150];
    char * unwanted = new char[150];
    char answer = '\0';
    
    cout << "what are some features you'd like to have in a car?" << endl;
    cout << "Enter wanted features: ";
    cin.get(wanted, 150, '\n');
    cin.ignore(150, '\n');
    
    cout << "what are some features you don't want in a car?" << endl;
    cout << "Enter unwanted features: ";
    cin.get(unwanted, 150, '\n');
    cin.ignore(150, '\n');

    cout << "Great, let's see which vehicles are the best fit for you.";
    cout << endl;

    if(!vehicles.getDeterminants(unwanted, wanted))
    {
        cout << "I'm sorry but we do not have any vehicles currently"
             << endl;
    }

    delete [] wanted;
    delete [] unwanted;
}

//searchForVehicle asks the user to enter in a vehicle they would like to see.
//Function then supplies the string to the ADT
void searchForVehicle(Vehicle_List &vehicles)
{
    char * car = new char[100];

    cout << "What is the specific make and model you are looking for?" << endl;
    cout << "Enter a make model (e.g. 'volkswagon passat'): ";
    cin.get(car, 150, '\n');
    cin.ignore(150, '\n');
    cout << endl << endl;

    if(!vehicles.findVehicle(car))
    {
        cout << "It appears we do no currently have that make/model in\n";
        cout << "our registry." << endl;
    }

    delete [] car;
}
