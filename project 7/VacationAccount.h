//Annie Cen
//UID:305721672
//Project 7

#ifndef VacationAccount_h
#define VacationAccount_h
#include "BloodDonation.h"
#include <stdio.h>

using namespace std;

class VacationAccount
{
public:
    friend class EmployeeAccount;
    
    VacationAccount(int EmployeeID);
    VacationAccount(int EmployeeID, double startingBalance);
    
    
    double getBalance();
    int getID();
    
    bool addVacationToAccount(BloodDonation donation);
    
private:
    int mID;
    double mBalance = 0;

};

#endif /* VacationAccount_h */
