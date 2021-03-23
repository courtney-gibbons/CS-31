// Courtney Gibbons
// 705485300

#include <iostream>

#include "PlaneFlight.h"
#include "FrequentFlyerAccount.h"

using namespace std;

// constructor
FrequentFlyerAccount::FrequentFlyerAccount(string name) {
    // initialize name and balance
    mName = name;
    mBalance = 0;
}

// getters for balance and name
double FrequentFlyerAccount::getBalance() {
    return(mBalance);
}
string FrequentFlyerAccount::getName() {
    return(mName);
}

// to add a flight
bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight) { // flight is an object of PlaneFlight
    // get necessary info about the flight using getters
    double mileage = flight.getMileage();
    string name = flight.getName();
    double cost = flight.getCost();
    string to = flight.getToCity();
    string from = flight.getFromCity();
    bool match;
    
    // check if names match, cost >= 0, to != from, to not empty, and from not empty
    if ( (name == mName) && (cost >= 0) && (to != "") && (from != "") && (to != from) ) {
        match = true;
    }
    else {
        match = false;
    }
    
    // check if names match, cost > 0, to != from, to not empty, and from not empty
    // update balance (only if cost > 0)
    if ( (name == mName) && (cost > 0) && (to != "") && (from != "") && (to != from) ) {
        mBalance += mileage;
    }
    
    return(match);
}
// check if you can earn a free flight
bool FrequentFlyerAccount::canEarnFreeFlight(double mileage) {
    bool enough = false;
    // check that you have enough balance and miles > 0
    if ( (mBalance >= mileage) && (mileage > 0) ) {
        enough = true;
    }
    return(enough);
}
// to create a free flight
bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight & flight) {
    string name = mName;
    bool enough;
    
    // checks if we have enough balance + if to or from are valid
    // if so, update flight and return true
    // if not, don't update flight and return false
    if ( (mBalance >= mileage) && (mileage > 0) && (to != "") && (from != "") && (to != from) ) {
        mBalance -= mileage;
        
        // update flight object to be free
        // to bypass the restrictions on to != from, create a temp object
        // set flight = temporary object
        // set cost = 0
        PlaneFlight temp(name, from, to, 0, mileage);
        flight = temp;
        
        enough = true;
    }
    else {
        enough = false;
    }
    return(enough);
}
