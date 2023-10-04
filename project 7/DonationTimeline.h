//Annie Cen
//UID:305721672
//Project 7

#ifndef DonationTimeline_h
#define DonationTimeline_h

class DonationTimeline
{
public:

    DonationTimeline(int EmployeeID, int month, int year, int day); // this class is essentially a time keeper as it tracks the time between donations and makes sure enough time has passed so people are able to donate
    DonationTimeline(int EmployeeID); // this one is to initialize the class as if it is the employees first time then the month and year and day should be 0 initially
            
    int getID();
    
    int getMonth();
    void setMonth(int Month);

    int getYear();
    void setYear(int Year);
    
    int getDay();
    void setDay(int Day);
    
    int getDate();
    
    int timeBetweenDonation(int thisMonth, int thisYear); // this function will calculate the time between donations generally as you can see it doesnt care for the day as the  minimum time between donation is dependent on months so the dates are relatively irrelevant to this calculation and there is another function in the BloodDonation class that takes care of the donation on the same day
    bool canDonate(int TimeBetween); // this will determine if peope can donate based on the time passed as calculate in the timeBetweenDonation function
    
private:
    int mID;
    int mMonth;
    int mYear;
    int mDay;
    int timeBetween;
    int mDate;
    friend class BloodDonation;
    
};
#endif /* DonationTimeline_h */
