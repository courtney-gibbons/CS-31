#include <iostream>

#include "PlaneFlight.h"

using namespace std;

#ifndef FrequentFlyerAccount_H
#define FrequentFlyerAccount_H

class FrequentFlyerAccount {
// private member variables
private:
    string mName;
    double mBalance;
// public operations
public:
    FrequentFlyerAccount(string name);
    
    double getBalance();
    string getName();
    
    bool addFlightToAccount(PlaneFlight flight);
    bool canEarnFreeFlight(double mileage);
    bool freeFlight(string from, string to, double mileage, PlaneFlight & flight);
};

#endif
