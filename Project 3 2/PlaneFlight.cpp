//
//  PlaneFlight.cpp
//  Project 5 CS 31
//
//  Created by kelly tran on 3/5/23.
//

#include "PlaneFlight.hpp"
#include <iostream>

using namespace std;


PlaneFlight::PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage){
    setCost(cost); //these are the constructors
    setMileage(mileage);
    setName(passengerName);
    setFromCity(fromCity);
    setToCity(toCity);
}

double PlaneFlight::getCost(){
    return mCost;
}

void PlaneFlight::setCost(double cost){
    if (cost >= 0){
        mCost = cost;
    }
    else {
        mCost = -1;
    }
}

double PlaneFlight::getMileage(){
    return mMileage;
}

void PlaneFlight::setMileage(double mileage){
    if (mileage >= 0){
        mMileage = mileage;
    }
    else {
        mMileage = -1;
    }
}

string PlaneFlight::getName(){
    return mName;
}

void PlaneFlight::setName(string passengerName){
    if (passengerName != ""){
        mName = passengerName;
    }
}

string PlaneFlight::getToCity(){
    return mToCity;
}

void PlaneFlight::setToCity(string toCity){
    if (toCity != "" && toCity != mFromCity){
        mToCity = toCity;
    }
}

string PlaneFlight::getFromCity(){
    return mFromCity;
}

void PlaneFlight::setFromCity(string fromCity){
    if (fromCity != "" && fromCity != mToCity){
        mFromCity = fromCity;
    }
}
