//Annie Cen
//UID:305721672
//Project 7

#include "VacationAccount.h"

VacationAccount::VacationAccount(int EmployeeID) : VacationAccount(EmployeeID, 0.0) {
} // this just initialized the account with a starting balance of 0

VacationAccount::VacationAccount(int EmployeeID, double initialBalance) : mID(EmployeeID), mBalance(initialBalance) {
}


double VacationAccount::getBalance(){
    return mBalance;
}

int VacationAccount::getID(){
    return mID;
}

bool VacationAccount::addVacationToAccount(BloodDonation donation){
    if (donation.getID() == mID){
        if (mID != -1 && donation.getAge() != -1 && donation.getWeight() != -1) { // this line just makes sure that everything is valid like age weight and employee id matches and everything which means this person donated and only when they donate can their balance increase
            mBalance = mBalance + 4;
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}
