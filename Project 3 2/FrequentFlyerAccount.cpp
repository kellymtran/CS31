//
//  FrequentFlyerAccount.cpp
//  Project 5 CS 31
//
//  Created by kelly tran on 3/5/23.
//

#include "FrequentFlyerAccount.hpp"
#include <iostream>

using namespace std;

FrequentFlyerAccount::FrequentFlyerAccount(string name){
    mName = name;
}

string FrequentFlyerAccount::getName(){
    return mName; //this is to get entered name an refer it to the account
}

double FrequentFlyerAccount::getBalance(){
    return mBalance; //same as before, but with balance
}

bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight){
    if(flight.getName() == mName){
        mBalance = mBalance + flight.getMileage();
        return true; //this is to show that the new balance will be the old balance plus the mileage from the added flight
    }
    else{
        return false;
    }
}

bool FrequentFlyerAccount::canEarnFreeFlight(double mileage){
    if(mBalance >= mileage){
        return true; //this is to show that if the balance is greater than the mileage, the passenger is qualified for a free flight
    }
    else{
        return false;
    }
}

bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight& flight){
    if(canEarnFreeFlight(mileage) == true){
        
        flight = PlaneFlight(mName, from, to, 0, mileage);
        mBalance = mBalance - flight.getMileage();
        return true; //this is to generate a flight if the passenger qualifies for a free flight and the cost is 0, but the balance goes down with the flight mileage.
    }
    else{
        return false;
    }
}
