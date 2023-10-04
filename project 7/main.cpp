//Annie Cen
//UID:305721672
//Project 7

#include <iostream>
#include <cassert>
#include "BloodDonation.h"
#include "DonationTimeline.h"
#include "VacationAccount.h"
#include "EmployeeAccount.h"

using namespace std;

int main() {
    BloodDonation donor(123456, 50 , 150);
    BloodDonation cool(123456, 50, 150);
    
    DonationTimeline zerotime(126542);
    DonationTimeline donortime(123456, 2, 2003, 18);
    DonationTimeline cooltime(123456, 3, 2010, 20);
    EmployeeAccount account(123456);
    Employee employee = {123456, 50, 150, 2182003};
    bool found = false;
    VacationAccount vacayaccount(123456);
    account.addEverythingToAccount(donor,donortime);
    
    // this tests the basic get functions of the employee account
    assert(account.getDate() == 2182003);
    assert(account.getAge() == 50);
    assert(account.getWeight() == 150);
    assert(account.getID() == 123456);
    
    account.putEmployee(employee);
    
    //checks if the find employee function works and ran through the array to find the correct employee
    assert(account.findEmployee(123456,found).mID == employee.mID);
    assert(account.findEmployee(123456,found).mAge == employee.mAge);
    assert(account.findEmployee(123456,found).mWeight == employee.mWeight);
    assert(account.findEmployee(123456,found).mDate == employee.mDate);
    
    //checks if the balance increases accurately
    assert(vacayaccount.getBalance() == 0);
    vacayaccount.addVacationToAccount(donor);
    assert(vacayaccount.getBalance() == 4);
    vacayaccount.addVacationToAccount(cool);
    assert(vacayaccount.getBalance() == 8);
    // this tests the default initialization yay!
    assert(zerotime.getID() == 126542);
    assert(zerotime.getDay() == 0);
    assert(zerotime.getDate() == 0);
    assert(zerotime.getYear() == 0);
    assert(zerotime.getMonth() == 0);
    
    // this tests the normal situation where everything is defined!
    assert(donortime.getID() == 123456);
    assert(donortime.getDay() == 18);
    assert(donortime.getDate() == 2182003);
    assert(donortime.getYear() == 2003);
    assert(donortime.getMonth() == 2);
    
    // this tests whether the function for timeBetween the donations!
    assert(donortime.timeBetweenDonation(3, 2005) == 6); // this should be 25 months but because its past 6 months i just set it to 6 since it doesn't matter when as this function is just to assist in determining if someone is eligible to donate
    assert(donortime.timeBetweenDonation(7, 2003) == 5);
    assert(donortime.timeBetweenDonation(8, 2003) == 6);
    assert(donortime.timeBetweenDonation(1, 2004) == 11);
    assert(donortime.timeBetweenDonation(1, 2003) == -1);
    
    //this checks if the function checking if people can donate works so basically if the value is above 6 it should return true otherwise false
    assert(donortime.canDonate(6) == true);
    assert(donortime.canDonate(5) == false);
    assert(donortime.canDonate(-1) == false);
    assert(donortime.canDonate(10) == true);
    
    //this checks that the updateDonationDate function works and updates the info in the class DonationTimeline
    assert(donortime.getDate() == 2182003);
    donor.updateDonationDate(donortime, 3222023);
    assert(donortime.getDate() == 3222023);

    // this basically checks if the last time you donated is the same as the current date becaue one person cant donate on the same day
    assert(donor.sameDayDonation(3222023) == true);
    return 0;
}
