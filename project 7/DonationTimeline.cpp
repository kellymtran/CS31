//Annie Cen
//UID:305721672
//Project 7

#include "DonationTimeline.h"

DonationTimeline::DonationTimeline(int EmployeeID, int month, int year, int day){
    if(canDonate((timeBetweenDonation(month, year))) == true){
        setDay(day);
        setYear(year);
        setMonth(month);
        mDate = month*1000000 + day*10000 + year; // this is basically putting all the information about the time and dates in to one form to look at all at once so it looks like MMDDYYYY but it only does this in the case that the person is able to donate
    }
    
    mID = EmployeeID;

}

DonationTimeline::DonationTimeline(int EmployeeID)
        : DonationTimeline{ EmployeeID, 0, 0, 0 } {
    } // this is just to initialize a default setting everything in the timeline to 0 originally using contructor delegation to make it easier and faster (typing wise)

int DonationTimeline::getID(){
    return mID;
}

int DonationTimeline::getDate(){
    return mDate;
}

int DonationTimeline::getMonth(){
    return mMonth;
}
void DonationTimeline::setMonth(int Month){
    mMonth = Month;
}


int DonationTimeline::getYear(){
    return mYear;
}
    
void DonationTimeline::setYear(int Year){
    mYear = Year;
}

int DonationTimeline::getDay(){
    return mDay;
}
void DonationTimeline::setDay(int Day){
    mDay = Day;
}

int DonationTimeline::timeBetweenDonation(int thisMonth, int thisYear){
    if(thisYear == mYear){
        if (thisMonth == mMonth) {
            timeBetween = 0;
            return timeBetween;
        }
        
        else if(thisMonth > mMonth) { // this else if statement covers the easy case of when the last time someone
            timeBetween = thisMonth - mMonth;
            return timeBetween;
        }
        else {
            return -1;
        }
    }
    else if(thisYear != mYear) {
        if (thisMonth == mMonth){
            timeBetween = 12;
            return timeBetween;
        }
        
        else if (thisMonth > mMonth){
            timeBetween = 6; // this isnt the actual time between of course, but because every case in this else if statement will be longer than 6 months and the only purpose for knowing the value of the time between is to determine if it is valid for the doner to donate again so i just assigned it to 6 with is a valid amount of months
            return timeBetween;
        }
        
        else if (thisMonth < mMonth) {
            timeBetween = (thisMonth + (12)*(thisYear - mYear)) - mMonth; // this is basically to cover the situation when the years are different and the month of the current month is smaller so a direct subtraction could skew results
            return timeBetween;
        }
        else {
            return -1;
        }
    }
    else{
        return -1;
    }
}

bool DonationTimeline::canDonate(int TimeBetween){
    if(TimeBetween >= 6){ // since the minimum time between donations is six months this is going to return true as long as the time passed is 6 or greater
        return true;
    }
    else {
        return false;
        
    }
}
