#include "vehicle_list.h"


//Class fucntions 

//Should build a LLL from an external data file. 
Vehicle_List::Vehicle_List()
{
    head = NULL;
    buildList();   
}

Vehicle_List::~Vehicle_List()
{

}

bool Vehicle_List::buildList()
{
    ifstream file_in;
    file_in.open("talent.txt");

    if(file_in)
    {
        Node * temp = head;
        //TODO parse each line of the text file, load each line's data to
        //a node and create a LLL
        //TODO Parse the last line of the text file within the '[ ]', the data
        //inside these brackets on each line of the text file will be its own
        //LLL
        while(file_in.getline(temp->vehicle.manufacturer, ':'))
        {
            file_in.getline(temp->vehicle.model, ':');
            file_in.getline(temp->vehicle.year, ':');
            file_in.getline(temp->vehicle.price, ':');
            file_in.getline(temp->vehicle.fuelType, ':');
            file_in.getline(temp->vehicle.fuelEff, ':');
            file_in.getline(temp->vehicle.vehicleType, ':');
            file_in.getline(temp->vehicle.engine, ':');
            file_in.getline(temp->vehicle.numPeople, ':', '[');
            
            temp->next = new Node;
            temp = temp->next;
        }
    }
    file_in.close();
}
//Sort and display by manufacturer TODO
//assign points for wanted features TODO
//Assign points for unwanted features TODO
//Sort by wishlist TODO
//Display specific make or model TODO
//TODO For testing purposes, display entire list

bool Vehicle_List::displayList()
{

}
