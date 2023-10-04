//Annie Cen
//UID:305721672
//Project 7

#ifndef BloodDonation_h
#define BloodDonation_h
#include "DonationTimeline.h"
#include <stdio.h>

using namespace std;

class BloodDonation
{
public:
    
    BloodDonation(int EmployeeID, int EmployeeAge, double EmployeeWeight); // this is the original code from project 6
    
    int getID();
    void setID(int id);
    
    int getAge();
    void setAge(int age);
    
    double getWeight();
    void setWeight(double weight);
    
    
    void updateDonationDate(DonationTimeline& time, int currentDate); // the purpose of this is to update the donation date when the person donates so it will update everything as the LastDate will now become the current date so everything is up to date in the records
    bool sameDayDonation(int currentDate); // this will cover the case that someone tries to donate on the same day so it should prevent them if the dates match up *note that the date is set up in the MMDDYYYY format
    
    
private:
    int mID;
    int mAge;
    double mWeight;
    int LastDate;
    friend class DonationTimeline;
    friend class EmployeeAccount;
};




#endif /* BloodDonation_h*/
