//Annie Cen
//UID:305721672
//Project 7

#ifndef EmployeeAccount_h
#define EmployeeAccount_h
#include "BloodDonation.h"
#include "DonationTimeline.h"
#include "VacationAccount.h"
#include <string>

struct Employee // this is to create the Employee struct which contains its basic information that is asked to be seen in order to donate blood
{
    int mID;
    int mAge;
    int mWeight;
    int mDate;
    
    
};

class EmployeeAccount
{
public:
    EmployeeAccount(int EmployeeID); // this class serves almost like an archive to store the information about the employees
    
    
    int getID();
    int getAge();
    int getWeight();
    int getDate();
    
    
    
    void putEmployee(Employee someone); // this function will basically be the setter and place the employee into an array
    Employee findEmployee(int EmployeeID, bool &found); // this function is basically the getter as it tries to find it in the array
    
    void addEverythingToAccount(BloodDonation donation, DonationTimeline time);
    
private:
    int mID = 0;
    int mAge;
    int mWeight;
    int mDate;
    Employee array[100];
};


#endif /* EmployeeAccount_h */
