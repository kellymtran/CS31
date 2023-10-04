/*
 Kelly Tran
 405808641
 CS31
*/

#ifndef VacationAccount_h
#define VacationAccount_h

#include "BloodDonation.h"
#include <stdio.h>
#include <iostream>

using namespace std;

class VacationAccount {

public:
    VacationAccount(int EmployeeID);
    
    double getBalance();
    int getID();
    
    bool addVacationToAccount(BloodDonation donation);
    
private:
    
    int mID;
    double mBalance;
    
};

#endif /* VacationAccount_h */

