//Logan Miller
//CS163
//Program #1 Vehicle_List ADT

#include "vehicle_list.h"

//ADT's constructor
Vehicle_List::Vehicle_List()
{
    head = NULL;
    fileRead();   
}

//ADT's destructor
Vehicle_List::~Vehicle_List()
{
    Node * temp = NULL;
    while(head)
    {
        temp = head;
        head = head->next;
        delete [] temp->vehicle.manufacturer;
        delete [] temp->vehicle.model;
        delete [] temp->vehicle.year;
        delete [] temp->vehicle.price;
        delete [] temp->vehicle.fuelType;
        delete [] temp->vehicle.fuelEff;
        delete [] temp->vehicle.vehicleType;
        delete [] temp->vehicle.engine;
        delete [] temp->vehicle.numPeople;
        
        FeatureNode * tempFeat = NULL;
        while(temp->vehicle.featureHead)
        {
            tempFeat = temp->vehicle.featureHead;
            temp->vehicle.featureHead = temp->vehicle.featureHead->next;
            delete [] tempFeat->feature;
            tempFeat->next = NULL;
            delete tempFeat;
        }

        temp->next = NULL;
        delete temp;
    }
}

//Reads in data from a file, creats nodes and calls a function to create 
//required nested nodes, passes nodes to a build list
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

            file_in.getline(temp->vehicle.manufacturer, 50, ':');
            file_in.getline(temp->vehicle.model, 50, ':');
            file_in.getline(temp->vehicle.year, 50, ':');
            file_in.getline(temp->vehicle.price, 50, ':');
            file_in.getline(temp->vehicle.fuelType, 50, ':');
            file_in.getline(temp->vehicle.fuelEff, 50, ':');
            file_in.getline(temp->vehicle.vehicleType, 50, ':');
            file_in.getline(temp->vehicle.engine, 50, ':');
            file_in.getline(temp->vehicle.numPeople, 50, '|');
            file_in.getline(tempArr, 100, '\n');

            buildNestedList(temp, tempArr);
            buildList(temp);
            file_in.peek();
            delete [] tempArr;
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
//This function is used for creating the data that will be stored in the 
//nested list
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
        //searches for a comma, parses data from before the comma to a comma
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
        //Used for parsing the last bit of the feature's data, the data from
        //the last ',' found and the deliminating '|' characters
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
//nestedList is more of a helper function. This function is really what
//'builds' the nested nodes
bool Vehicle_List::nestedList(Node * &temp, FeatureNode * &tempFeat)
{
    if(!temp->vehicle.featureHead)
    {
        temp->vehicle.featureHead = tempFeat;
        temp->vehicle.featureHead->next = NULL;
        temp->vehicle.featureTail = temp->vehicle.featureHead;
    }

    temp->vehicle.featureTail->next = tempFeat;
    temp->vehicle.featureTail = temp->vehicle.featureTail->next;
    temp->vehicle.featureTail->next = NULL;
    return true;
}


//Recieves an array of wanted features and an array of unwated features.
//Passes each one to their respective functions
bool Vehicle_List::getDeterminants(char * &unwanted, char * &wanted)
{
    assignUnwanted(unwanted);
    assignWanted(wanted);
    if(!sortWishList())
    {
        return false;
    }
    return true;
}

//assign points for unwanted features to each node in the list
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
//Assign points for wanted features to each node in the list
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
    if(!head->next)
    { 
        if(displayList())
        {
            return true;
        }

        return false;
    }

    
    bool moreSwaps = false;
    moreSwaps = sortWishHelper();

    if(displayList())
    {
        return true;
    }

    return false;
}

//sortWishHelper is a function that helps sortWishList, this function is the
//one that actually sorts the data.
bool Vehicle_List::sortWishHelper()
{
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

    if(swaps > 0) sortWishHelper();
    return false;
}

//Sort by manufacturer
bool Vehicle_List::sortMan()
{
    if(!head) return false;
    if(!head->next)
    { 
        if(displayList())
        {
            return true;
        }
        
        return false;
    }

    bool moreSwaps = false;
    moreSwaps = sortManHelper();

    if(displayList())
    {
        return true;
    }

    return false;
}

//much like the helper function above, sortManHelper is the function that is 
//really sorting the list by manufacturer
bool Vehicle_List::sortManHelper()
{

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
        if(strcmp(current->vehicle.manufacturer, previous->vehicle.manufacturer) < 0)
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

    if(swaps > 0) sortManHelper();
    return false;
}

//Displays only a specific make and model 
bool Vehicle_List::findVehicle(char * &car)
{
   
    Node * current = head;
    int foundCar = 0;
    while(current)
    {
        if(strstr(car, current->vehicle.manufacturer) 
        && strstr(car, current->vehicle.model))
        {
            ++foundCar;
        
            FeatureNode * currentFeat = current->vehicle.featureHead;

            cout << "Manufacturer: "
                 << current->vehicle.manufacturer << endl;
            cout << "Model: "
                 << current->vehicle.model << endl;
            cout << "Year: "
                 << current->vehicle.year << endl;
            cout << "Price: "
                 << current->vehicle.price << endl;
            cout << "Fuel Type: "
                 << current->vehicle.fuelType << endl;
            cout << "Fuel Efficiency: "
                 << current->vehicle.fuelEff << endl;
            cout << "Vehicle Type: "
                 << current->vehicle.vehicleType << endl;
            cout << "Engine: "
                 << current->vehicle.engine << endl;
            cout << "Number of people accomodate: " 
                 << current->vehicle.numPeople << endl;
            cout << "*********" << endl;
            cout << "Available Features: ";
            while(currentFeat)
            {
                cout << currentFeat->feature << ", ";
                currentFeat = currentFeat->next;
            }
            
            cout << endl << "********" << endl;
            cout << endl << endl;
        }
        
        current = current->next;
    }

    if(foundCar > 0) return true;

    else return false;
}

//displayList is simply a function that will display all the contents within
//the list, regardless of whether or not they are sorted.
bool Vehicle_List::displayList()
{
    if(head)
    {
        cout << endl << endl;
        Node * current = head;
        while(current)
        {
            FeatureNode * currentFeat = current->vehicle.featureHead;

            cout << "Manufacturer: " 
                 << current->vehicle.manufacturer << endl;
            cout << "Model: "
                 << current->vehicle.model << endl;
            cout << "Year: "
                 << current->vehicle.year << endl;
            cout << "Price: "
                 << current->vehicle.price << endl;
            cout << "Fuel Type: "
                 << current->vehicle.fuelType << endl;
            cout << "Fuel Efficiency: "
                 << current->vehicle.fuelEff << endl;
            cout << "Vehicle Type: "
                 << current->vehicle.vehicleType << endl;
            cout << "Engine: "
                 << current->vehicle.engine << endl;
            cout << "Number of people accomodate: " 
                 << current->vehicle.numPeople << endl;
            cout << "*********" << endl;
            cout << "Available Features: ";
            while(currentFeat)
            {
                cout << currentFeat->feature << ",  ";
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








