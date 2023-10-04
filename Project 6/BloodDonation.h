/*
 Kelly Tran
 405808641
 CS31
*/

#ifndef BloodDonation_h
#define BloodDonation_h

#include <stdio.h>
#include <iostream>

using namespace std;

class BloodDonation{
    
public:
    BloodDonation(int EmployeeID, int EmployeeAge, double EmployeeWeight);
    
    int getID();
    int getAge();
    double getWeight();
    
    void setID(int id);
    void setAge(int age);
    void setWeight(double weight);

private:
    int mID;
    int mAge;
    double mWeight;
};

#endif /* BloodDonation_h */

