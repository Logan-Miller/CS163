
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;


//Second Node for vehicle features
struct FeatureNode
{
    char * feature;
    FeatureNode * next;
};

//A vehicle is made up of 10 different features, 9 char *'s and a node that 
//will be used to create a LLL of features that will also be char *'s
struct Vehicle
{
    char * manufacturer;
    char * model;
    char * year;
    char * price;
    char * fuelType;
    char * fuelEff;
    char * vehicleType;
    char * engine;
    char * numPeople;
    FeatureNode * featureHead;
};

//Node used for building a LLL of vehicles. Has data for a vehicle as well as
//an integer that will be used for assigning a point rating of each vehicle
struct Node
{
    Vehicle vehicle;
    int pointVal;
    Node * next;
};

//Class Vehicle_List is an ADT that manages a LLL of vehicles that are loaded
//in from an external text file.
class Vehicle_List
{

public:
    Vehicle_List();
    ~Vehicle_List();
    //Sort and display by manufacturer TODO
    //assign points for wanted features TODO
    //Assign points for unwanted features TODO
    //Sort by wishlist TODO
    //Display specific make or model TODO
    //TODO For testing purposes, display entire list
    bool displayList();
private:
    //private data members
    Node * head;
    Node * tail;
    //Function used to build the list. Reads in data from an external data file
    //parses the information, and then builds a LLL
    bool buildList();   
};
