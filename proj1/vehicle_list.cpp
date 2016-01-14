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
    file_in.open("vehicles.txt");
    if(file_in)
    {
        Node * temp = new Node;
        temp->vehicle.manufacturer = NULL;
        temp->vehicle.model= NULL;
        temp->vehicle.year= NULL;
        temp->vehicle.price= NULL;
        temp->vehicle.fuelType= NULL;
        temp->vehicle.fuelEff= NULL;
        temp->vehicle.vehicleType= NULL;
        temp->vehicle.engine= NULL;
        temp->next = NULL;
        head = temp;

        //TODO parse each line of the text file, load each line's data to
        //a node and create a LLL
        //TODO Parse the last line of the text file within the '[ ]', the data
        //inside these brackets on each line of the text file will be its own
        //LLL
        //TODO create a temp array, getline the data, strcpy the data to the node
        //Seg faults if using current way
        while(!file_in.eof())
        {

            file_in.getline(temp->vehicle.manufacturer,50,':');
            file_in.getline(temp->vehicle.model,50,':');
            file_in.getline(temp->vehicle.year,50,':');
            file_in.getline(temp->vehicle.price,50,':');
            file_in.getline(temp->vehicle.fuelType,50,':');
            file_in.getline(temp->vehicle.fuelEff,50,':');
            file_in.getline(temp->vehicle.vehicleType,50,':');
            file_in.getline(temp->vehicle.engine,50,'\n');
            
            temp->next = new Node;
            temp = temp->next;
//TODO not ready to parse the second list    file_in.getline(temp->vehicle.numPeople, ':', '[');
        }
    }
    file_in.close();
    return true;
}
//Sort and display by manufacturer TODO
//assign points for wanted features TODO
//Assign points for unwanted features TODO
//Sort by wishlist TODO
//Display specific make or model TODO
//TODO For testing purposes, display entire list
bool Vehicle_List::displayList()
{
    if(head)
    {
        Node * current = head;
        while(current)
        {
            cout << current->vehicle.manufacturer << endl;
            cout << current->vehicle.model << endl;
            cout << current->vehicle.year << endl;
            cout << current->vehicle.price << endl;
            cout << current->vehicle.fuelType << endl;
            cout << current->vehicle.fuelEff << endl;
            cout << current->vehicle.vehicleType << endl;
            cout << current->vehicle.engine << endl;
        }
        return true;
    }

    return false;
}








