//
//  PlaneFlight.hpp
//  Project 5 CS 31
//
//  Created by kelly tran on 3/5/23.
//

#ifndef PlaneFlight_hpp
#define PlaneFlight_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class PlaneFlight{
    
public:
    PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage);
    //these are the constructors
    string getName(); //this is to declare the accessor functions
    string getFromCity();
    string getToCity();
    double getCost();
    double getMileage();
    
    void setName(string passengerName); //this is to declare the mutator functions
    void setFromCity(string fromCity);
    void setToCity(string toCity);
    void setCost (double cost);
    void setMileage (double mileage);
    
private:
    // these are the private variables
    double mCost;
    double mMileage;
    string mName;
    string mFromCity;
    string mToCity;
    
};

#endif
