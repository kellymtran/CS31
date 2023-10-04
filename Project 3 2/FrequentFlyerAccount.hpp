//
//  FrequentFlyerAccount.hpp
//  Project 5 CS 31
//
//  Created by kelly tran on 3/5/23.
//

#ifndef FrequentFlyerAccount_hpp
#define FrequentFlyerAccount_hpp

#include "PlaneFlight.hpp"
#include <iostream>

using namespace std;

class FrequentFlyerAccount {
public:
    FrequentFlyerAccount(string name);

    string getName();

    double getBalance();

    bool addFlightToAccount(PlaneFlight flight);

    bool canEarnFreeFlight(double mileage);

    bool freeFlight(string from, string to, double mileage, PlaneFlight& flight);

private:
    
    string mName;
    double mBalance = 0;
};

#endif 
