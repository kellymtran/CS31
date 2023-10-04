//Annie Cen
//UID:305721672
//Project 7

#include "BloodDonation.h"
#include "EmployeeAccount.h"
#include "DonationTimeline.h"



BloodDonation::BloodDonation(int EmployeeID, int EmployeeAge, double EmployeeWeight){
    setID(EmployeeID);
    setAge(EmployeeAge);
    setWeight(EmployeeWeight);

}

int BloodDonation::getID(){
    return mID;
}

void BloodDonation::setID(int id){
    int counter = 0;
    int test = id;
    int mod = 0;

    while(test != 0) { // this is basically a loop that will run through each of the digits and everytime it does it will add one to the counter so essentially counting how many digits in the int
        mod = test % 10; // this will increment it down so if the number was 123 then it would after the first round turn to 12 then 1 and so the loop would've ran three times thus the counter is at 3 in the end so three digits which is true
        test = test / 10;
        if(mod >= 0 && mod <= 9){
            counter ++;
        }
        else {
            mID = -1;
            break;
        }
    }
    if(counter == 6){// this checks if there are 6 digits in the employee id
        mID = id;
    }
    else{
        mID = -1;
    }
}

int BloodDonation::getAge(){
    return mAge;
}

void BloodDonation::setAge(int age){
    if(age >= 21 && age <= 65) {
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
    if(weight >= 101.00 && weight <= 280.00){
        mWeight = weight;
    }
    else {
        mWeight = -1;
    }
}


void BloodDonation::updateDonationDate(DonationTimeline& time, int currentDate){
    time.mDate = currentDate; // this use of this function is that it will update last donation date from the Employee Account class which has the purpose of keeping the records of the employee itself so it will keep their personal information like weight and age and such
    LastDate = currentDate; // this will allow the function to update the last saved date to the current date which will also help in the function of sameDayDonation as it will update to currentdate and thus if someone tries to do a same day donation the dates will prevent it from happening
}

bool BloodDonation::sameDayDonation(int currentDate){
    if(currentDate == LastDate){
        return true; // return true because they are trying to donate on the same day
    }
    else{
        return false;
    }
}
