
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

//individual feature
struct Feature
{
    char * featureName;
};

//A vehicle is made up of 10 different features
struct Vehicle
{
    Feature manufacturer;
    Feature model;
    Feature year;
    Feature price;
    Feature fuelType;
    Feature fuelEff;
    Feature vehicleType;
    Feature engine;
    Feature numPeople;
    Feature features; //TODO possibly a second LLL for features
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
private:
    //private data members
    Node * head;
    
};
