/*
 Kelly Tran
 405808641
 CS31
*/

#include "BloodDonation.h"
#include <iostream>

using namespace std;

BloodDonation::BloodDonation(int EmployeeID, int EmployeeAge, double EmployeeWeight){
    setID(EmployeeID);
    setAge(EmployeeAge);
    setWeight(EmployeeWeight);
}

int BloodDonation::getID(){
    return mID;
}

void BloodDonation::setID(int id){ //This was one of the more confusing parts about this project, because I didn't know how to go through each digit and make sure it was between 0-9. I then figured that I could just make bounds between the six-digit numbers if you guys aren't testing for leading zeroes.
    if (id >= 100000 && id <= 999999){
        mID = id; //if the number  is less than 100000, it would be a five digit number. If it is greater than 999999, it would be a seven digit number.
    }
    else {
        mID = -1;
    }
}

int BloodDonation::getAge(){
    return mAge;
}

void BloodDonation::setAge(int age){
    if (age >= 21 && age <= 65){
        mAge = age;
    }
    else {
        mAge = -1;
    }
}

double BloodDonation::getWeight(){
    return mWeight;
}

void BloodDonation::setWeight(double weight){
    if (weight >= 101.00 && weight <= 280.00){
        mWeight = weight;
    }
    else {
        mWeight = -1;
    }
}

