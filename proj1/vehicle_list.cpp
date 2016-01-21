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
    ifstream file_in;
    file_in.open("vehicles.txt");
    if(file_in)
    {
        while(!file_in.eof())
        {
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
            
            temp->vehicle.featureHead = NULL;
            temp->vehicle.featureTail = NULL;
            temp->next = NULL;

            char * tempArr = new char[100];

            file_in.getline(temp->vehicle.manufacturer,50,':');
            file_in.getline(temp->vehicle.model,50,':');
            file_in.getline(temp->vehicle.year,50,':');
            file_in.getline(temp->vehicle.price,50,':');
            file_in.getline(temp->vehicle.fuelType,50,':');
            file_in.getline(temp->vehicle.fuelEff,50,':');
            file_in.getline(temp->vehicle.vehicleType,50,':');
            file_in.getline(temp->vehicle.engine,50,':');
            file_in.getline(temp->vehicle.numPeople,50,'|');
            file_in.getline(tempArr,100,'\n');

            buildNestedList(temp, tempArr);
            buildList(temp);
            file_in.peek();
        }
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

//Function to parse data read in from text file after a '|'
bool Vehicle_List::buildNestedList(Node * &temp, char * &tempArr)
{
    int arrLen = 0;
    arrLen = strlen(tempArr);

    int index = 0;
    int fStart = 0;
    int fEnd = 0;
    int count = 0;

    while(index < arrLen)
    {
        if(tempArr[index] == ',')
        {
            count += 1;
            fEnd = index - 1;
            
            FeatureNode * tempFeat = new FeatureNode;
            tempFeat->feature = new char[100];
            tempFeat->next = NULL;
            
            strncpy(tempFeat->feature, tempArr + fStart, fEnd-fStart+1);
            fStart = index + 1;
         
            nestedList(temp, tempFeat);
        }

        if(tempArr[index] == '|')
        {          
            fEnd = index - 1;
            
            FeatureNode * tempFeat = new FeatureNode;
            tempFeat->feature = new char[100];
            tempFeat->next = NULL;
            
            strncpy(tempFeat->feature, tempArr + fStart, fEnd-fStart+1);
            fStart = index + 1;
         
            nestedList(temp, tempFeat);
        }
    
        ++index;
    }
    
    return true;
}

bool Vehicle_List::nestedList(Node * &temp, FeatureNode * &tempFeat)
{
    if(!temp->vehicle.featureHead)
    {
        temp->vehicle.featureHead = tempFeat;
        temp->vehicle.featureHead->next = NULL;
        temp->vehicle.featureTail = temp->vehicle.featureHead;
    }

    /*FeatureNode * currentFeat = temp->vehicle.featureHead;
    
    while(currentFeat->next)
    {
        currentFeat = currentFeat->next;
    }

    currentFeat->next = tempFeat;
    currentFeat->next = NULL;*/

    temp->vehicle.featureTail->next = tempFeat;
    temp->vehicle.featureTail = temp->vehicle.featureTail->next;
    temp->vehicle.featureTail->next = NULL;
    return true;
}


//Sort by manufacturer TODO then display
bool Vehicle_List::sortMan()
{
    if(!head) return false;
    if(!head->next) return true;

    int swaps = 0;
    bool makeSwaps = true;
    Node * current = head;
    Node * previous = NULL;
    Vehicle tempVehicle;
    int tempInt = 0;

    while(current->next)
    {
    cout << "looking for swap" << endl;
        previous = current;
        current = current->next;
        if(strcmp(current->vehicle.manufacturer, previous->vehicle.manufacturer) < 0)
        {
        cout << "swap found" << endl;
            tempVehicle = previous->vehicle;
            tempInt = previous->pointVal;
            previous->vehicle = current->vehicle;
            previous->pointVal = current->pointVal;
            current->vehicle = tempVehicle;
            current->pointVal = tempInt;
            ++swaps;
        }
    }

    if(swaps > 0) sortMan();

    return true;
}

//Recieves an array of wanted features and an array of unwated features.
//Passes each one to their respective functions
bool Vehicle_List::getDeterminants(char * &unwanted, char * &wanted)
{
    assignUnwanted(unwanted);
    assignWanted(wanted);
    return true;
}

//assign points for unwanted features
bool Vehicle_List::assignUnwanted(char * &unwanted)
{
    Node * current = head;

    while(current)
    {
        if(strstr(unwanted, current->vehicle.manufacturer)) 
        current->pointVal = current->pointVal - 1;
        if(strstr(unwanted, current->vehicle.model))
        current->pointVal = current->pointVal - 1;
        if(strstr(unwanted, current->vehicle.year))
        current->pointVal = current->pointVal - 1;
        if(strstr(unwanted, current->vehicle.price))
        current->pointVal = current->pointVal - 1;
        if(strstr(unwanted, current->vehicle.fuelType))
        current->pointVal = current->pointVal - 1;
        if(strstr(unwanted, current->vehicle.fuelEff))
        current->pointVal = current->pointVal - 1;
        if(strstr(unwanted, current->vehicle.vehicleType))
        current->pointVal = current->pointVal - 1;
        if(strstr(unwanted, current->vehicle.engine))
        current->pointVal = current->pointVal - 1;
        
        FeatureNode * currentFeat = current->vehicle.featureHead;

        while(currentFeat)
        {
            if(strstr(unwanted, currentFeat->feature))
            current->pointVal = current->pointVal - 1;
            currentFeat = currentFeat->next;
        }
        
        current = current->next;
    }

    return true;
}
//Assign points for wanted features
bool Vehicle_List::assignWanted(char * &wanted)
{
    Node * current = head;

    while(current)
    {
        if(strstr(wanted, current->vehicle.manufacturer)) 
        current->pointVal = current->pointVal + 2;
        if(strstr(wanted, current->vehicle.model))
        current->pointVal = current->pointVal + 2;
        if(strstr(wanted, current->vehicle.year))
        current->pointVal = current->pointVal + 2;
        if(strstr(wanted, current->vehicle.price))
        current->pointVal = current->pointVal + 2;
        if(strstr(wanted, current->vehicle.fuelType))
        current->pointVal = current->pointVal + 2;
        if(strstr(wanted, current->vehicle.fuelEff))
        current->pointVal = current->pointVal + 2;
        if(strstr(wanted, current->vehicle.vehicleType))
        current->pointVal = current->pointVal + 2;
        if(strstr(wanted, current->vehicle.engine))
        current->pointVal = current->pointVal + 2;
        
        FeatureNode * currentFeat = current->vehicle.featureHead;

        while(currentFeat)
        {
            if(strstr(wanted, currentFeat->feature))
            current->pointVal = current->pointVal + 2;
            currentFeat = currentFeat->next;
        }
        
        current = current->next;
    }

    return true;
}
//Sorts the list by the user's most wanted features, represented by an
//integer value within the node
bool Vehicle_List::sortWishList()
{

    if(!head) return false;
    if(!head->next) return true;

    int swaps = 0;
    bool makeSwaps = true;
    Node * current = head;
    Node * previous = NULL;
    Vehicle tempVehicle;
    int tempInt = 0;

    while(current->next)
    {
        previous = current;
        current = current->next;
        if(current->pointVal > previous->pointVal)
        {
            tempVehicle = previous->vehicle;
            tempInt = previous->pointVal;
            previous->vehicle = current->vehicle;
            previous->pointVal = current->pointVal;
            current->vehicle = tempVehicle;
            current->pointVal = tempInt;
            ++swaps;
        }
    }

    if(swaps > 0) sortWishList();

    return true;
}
//Displays a specific make or model 
bool Vehicle_List::findVehicle(char * &car)
{
   
    Node * current = head;

    while(current)
    {
        if(strstr(car, current->vehicle.manufacturer) 
        && strstr(car, current->vehicle.model))
        {
        
            FeatureNode * currentFeat = current->vehicle.featureHead;

            cout << current->vehicle.manufacturer << endl;
            cout << current->vehicle.model << endl;
            cout << current->vehicle.year << endl;
            cout << current->vehicle.price << endl;
            cout << current->vehicle.fuelType << endl;
            cout << current->vehicle.fuelEff << endl;
            cout << current->vehicle.vehicleType << endl;
            cout << current->vehicle.engine << endl;
            cout << "*********" << endl;
            cout << "Available Features :";
            while(currentFeat)
            {
                cout << currentFeat->feature << " ";
                currentFeat = currentFeat->next;
            }
            
            cout << endl << "********" << endl;
            cout << endl << endl;
        }
        
        current = current->next;
    }

    return true;
}




//*****************************************************************************
//TODO For testing purposes, display entire list
//*****************************************************************************
bool Vehicle_List::displayList()
{
    if(head)
    {
        Node * current = head;
        while(current)
        {
            FeatureNode * currentFeat = current->vehicle.featureHead;

            cout << current->vehicle.manufacturer << endl;
            cout << current->vehicle.model << endl;
            cout << current->vehicle.year << endl;
            cout << current->vehicle.price << endl;
            cout << current->vehicle.fuelType << endl;
            cout << current->vehicle.fuelEff << endl;
            cout << current->vehicle.vehicleType << endl;
            cout << current->vehicle.engine << endl;
            cout << "*********" << endl;
            cout << "Available Features :";
            while(currentFeat)
            {
                cout << currentFeat->feature << " ";
                currentFeat = currentFeat->next;
            }
            
            cout << endl << "********" << endl;
            cout << endl << endl;
            
            current = current->next;
        }
        return true;
    }

    return false;
}








