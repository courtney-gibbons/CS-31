// Courtney Gibbons
// 705485300

#include <iostream>

#include "PlaneFlight.h"
#include "FrequentFlyerAccount.h"

using namespace std;

// constructor
PlaneFlight::PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage) {
    
    // initialize cost
    // set cost = -1 if < 0
    if (cost < 0) {
        mCost = -1;
    }
    else {
        mCost = cost;
    }
    
    // initialize from city
    // ignore if empty string or if from = to
    if ( (fromCity != "") && (fromCity != toCity) ) {
        mFromCity = fromCity;
    }
    
    // initialize to city
    // ignore if empty string or if from = to
    if ( (toCity != "") && (fromCity != toCity) ) {
        mToCity = toCity;
    }
    
    // initialize name
    // ignore if empty string
    if (passengerName != "") {
        mName = passengerName;
    }
    
    // initialize mileage
    // set mileage = -1 if < 0
    if (mileage < 0) {
        mMileage = -1;
    }
    else {
        mMileage = mileage;
    }
}

// getter/setter for cost
double PlaneFlight::getCost() {
    return(mCost);
}
void PlaneFlight::setCost(double cost) {
    // set cost = -1 if < 0
    if (cost < 0) {
        mCost = -1;
    }
    else {
        mCost = cost;
    }
}

// getter/setter for mileage
double PlaneFlight::getMileage() {
    return(mMileage);
}
void PlaneFlight::setMileage(double mileage) {
    // set mileage = -1 if < 0
    if (mileage < 0) {
        mMileage = -1;
    }
    else {
        mMileage = mileage;
    }
}

// getter/setter for name
string PlaneFlight::getName() {
    return(mName);
}
void PlaneFlight::setName(string name) {
    // ignore if empty string
    if (name != "") {
        mName = name;
    }
}

// getter/setter for from
string PlaneFlight::getFromCity() {
    return(mFromCity);
}
void PlaneFlight::setFromCity(string from) {
    // ignore if empty string or if from = to
    if ( (from != "") && (from != mToCity) ) {
        mFromCity = from;
    }
}

// getter/setter for to
string PlaneFlight::getToCity() {
    return(mToCity);
}
void PlaneFlight::setToCity(string to) {
    // ignore if empty string or if from = to
    if ( (to != "") && (mFromCity != to) ) {
        mToCity = to;
    }
}
