/*
 Kelly Tran
 405808641
 CS31
*/

#include "VacationAccount.h"
#include <iostream>

using namespace std;

VacationAccount::VacationAccount(int EmployeeID){
    mID = EmployeeID;
    mBalance = 0.0;
}

int VacationAccount::getID(){
    return mID;
}

double VacationAccount::getBalance(){
    return mBalance;
}

bool VacationAccount::addVacationToAccount(BloodDonation donation){
    if(donation.getID() == mID && mID != -1 && donation.getAge() != -1 && donation.getWeight() != -1){
        mBalance = mBalance + 4; //if the doner ID matches the vacation account ID and their ID, age, and weight is valid, we can add 4 hours to their balance as a reward for donating :D
        return true;
    }
    else {
        return false;
    }
}

