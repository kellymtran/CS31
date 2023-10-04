//Annie Cen
//UID:305721672
//Project 7

#include <stdio.h>
#include "EmployeeAccount.h"


EmployeeAccount::EmployeeAccount(int EmployeeID){
    mID = EmployeeID;
}


int EmployeeAccount::getAge(){
    return mAge;
}
int EmployeeAccount::getWeight(){
    return mWeight;
}
int EmployeeAccount::getDate(){
    return mDate;
}

int EmployeeAccount::getID(){
    return mID;
}

void EmployeeAccount::addEverythingToAccount(BloodDonation donation, DonationTimeline time){ // this function basically adds everything into an account for each employee
    if(mID == donation.getID()){
        mWeight = donation.getWeight();
        mAge = donation.getAge();
        mID = donation.getID();
        mDate = time.getDate();
    }
}

void EmployeeAccount::putEmployee(Employee someone){ // this function will add the object of struct Employee and add it to an array to collect all the employees up to 100 of them
    for(int i  = 0; i < 100; i++){
        if (array[i].mID == 0){
            array[i] = someone;
            return;
        }// this is just a demo for the case where there will only ever be 100 doners at once :)
    }
}

Employee EmployeeAccount::findEmployee(int EmployeeID, bool &found){ // this function creates a loop that will run through the array until it finds the employee id matches the parameter
    for(int i  = 0; i < 100; ++i){
        if (array[i].mID == EmployeeID){
            found = true;
            return array[i];
            }
        }
    
        found = false;
        return Employee();
    }


