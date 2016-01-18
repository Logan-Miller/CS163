#include "vehicle_list.h"


//Class functions 

Vehicle_List::Vehicle_List()
{
    head = NULL;
    fileRead();   
}

Vehicle_List::~Vehicle_List()
{
    
}

//Reads in data from a file, creats nodes, passes nodes to a build list
//function that will create a list from said nodes.
bool Vehicle_List::fileRead()
{
    //Temp arrays used for reading in strings from a text file
    char tempMan[50];
    char tempMod[50];
    char tempYer[50];
    char tempPrc[50];
    char tempFtp[50];
    char tempFef[50];
    char tempVtp[50];
    char tempEng[50];
    char tempNum[50];
    
    ifstream file_in;
    file_in.open("vehicles.txt");
    if(file_in)
    {
        //TODO Parse the last line of the text file within the '[ ]', the data
        //inside these brackets on each line of the text file will be its own
        //LLL
        int count = 0;
        while(!file_in.eof())
        {
        count += 1;
            Node * temp = new Node;
            temp->vehicle.manufacturer = new char [50];
            temp->vehicle.model = new char [50];
            temp->vehicle.year = new char [50];
            temp->vehicle.price = new char [50];
            temp->vehicle.fuelType = new char [50];
            temp->vehicle.fuelEff = new char [50];
            temp->vehicle.vehicleType = new char [50];
            temp->vehicle.engine = new char [50];
            temp->vehicle.numPeople = new char [50];
            temp->next = NULL;

            file_in.getline(tempMan,50,':');
            strcpy(temp->vehicle.manufacturer, tempMan);
            file_in.getline(tempMod,50,':');
            strcpy(temp->vehicle.model, tempMod);
            file_in.getline(tempYer,50,':');
            strcpy(temp->vehicle.year, tempYer);
            file_in.getline(tempPrc,50,':');
            strcpy(temp->vehicle.price, tempPrc);
            file_in.getline(tempFtp,50,':');
            strcpy(temp->vehicle.fuelType, tempFtp);
            file_in.getline(tempFef,50,':');
            strcpy(temp->vehicle.fuelEff, tempFef);
            file_in.getline(tempVtp,50,':');
            strcpy(temp->vehicle.vehicleType, tempVtp);
            file_in.getline(tempEng,50,':');
            strcpy(temp->vehicle.engine, tempEng);
            file_in.getline(tempEng,50,'\n');
            strcpy(temp->vehicle.numPeople, tempNum);
            
            buildList(temp);
            file_in.peek();
    //TODO not ready to parse the second list    file_in.getline(temp->vehicle.numPeople, ':', '[');
        }
        cout << count;
    }
    file_in.close();
    return true;
}

//Recieves a node, either sets that node as the beginning of the list or
//appends it to a list if head is not Null
bool Vehicle_List::buildList(Node * &temp)
{
    if(!head)
    {
        head = temp;
        tail = temp;
    }
    
    tail->next = temp;
    tail = tail->next;
    tail->next = NULL;

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
            current = current->next;
        }
        return true;
    }

    return false;
}








