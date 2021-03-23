// Courtney Gibbons
// 705485300

#include <iostream>

using namespace std;

#ifndef PlaneFlight_H
#define PlaneFlight_H

class PlaneFlight {
// private member variables
private:
    double mCost;
    string mFromCity;
    string mToCity;
    string mName;
    double mMileage;
// public operations
public:
    PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage);
    
    double getCost();
    void setCost(double cost);
    
    double getMileage();
    void setMileage(double mileage);
    
    string getName();
    void setName(string name);
    
    string getFromCity();
    void setFromCity(string from);
    
    string getToCity();
    void setToCity(string to);
};

#endif
