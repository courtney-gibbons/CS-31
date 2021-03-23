#include <iostream>
#include <string>
using namespace std;

int main() {
    // define & initialize variables
    string month = "";
    int day = 0;
    int year = 0;
    int month_code = 0;
    int century_value = 0;
    int century_code = 0;
    int year_code = 0;
    int day_code = 0;
    string day_of_the_week = "";
    
    // use user input to set variables
    cout << "Provide a month: ";
    getline(cin, month);
    cout << "Provide a day: ";
    cin >> day;
    cout << "Provide a year: ";
    cin >> year;
    
    // are variables valid?
    // if the month isn't typed exactly correct, invalid!
    if ((month != "January") && (month != "February") && (month != "March") && (month != "April") && (month != "May") && (month != "June") && (month != "July") && (month != "August") && (month != "September")&& (month != "October") && (month != "November") && (month != "December")) {
        cout << "Invalid month!" << endl;
        return(-1);
    }
    // if the day isn't between 1 and 31 (inclusive), invalid!
    // did not check for invalid dates like February 31st
    if ((day < 1) || (day > 31)) {
        cout << "Invalid day!" << endl;
        return(-1);
    }
    // if the year isn't between 1 and 3000 (inclusive), invalid!
    if ((year < 1) || (year > 3000)) {
        cout << "Invalid year!" << endl;
        return(-1);
    }
    
    // computing month code
    if ((month == "July") || (month == "April")) {
        month_code = 0;
    }
    if ((month == "January") || (month == "October")) {
        month_code = 1;
    }
    if (month == "May") {
        month_code = 2;
    }
    if (month == "August") {
        month_code = 3;
    }
    if ((month == "February") || (month == "March") || (month == "November")) {
        month_code = 4;
    }
    if (month == "June") {
        month_code = 5;
    }
    if ((month == "September") || (month == "December")) {
        month_code = 6;
    }
    //cout << "Month Code 1: " << month_code << endl; // test
    
    // leap year offset
    // if year mod 4 = 0 AND year mod 100 != 0, it's a leap year
    // EXCEPTION: if year mod 400 = 0, it's a leap year (use or to handle this exception)
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        if ((month == "January") || (month == "February")) {
            month_code = month_code - 1;
        }
    }
    //cout << "Month Code 2: " << month_code << endl; // test
    
    // century code
    century_value = (year / 100) % 4;
    if (century_value == 0) {
        century_code = -2;
    }
    if (century_value == 1) {
        century_code = 3;
    }
    if (century_value == 2) {
        century_code = 1;
    }
    if (century_value == 3) {
        century_code = -1;
    }
    //cout << "Century Value: " << century_value << endl; // test
    //cout << "Century Code: " << century_code << endl; // test
    
    // year code
    year_code = ((year % 100) / 4) + (year % 100);
    //cout << "Year Code: " << year_code << endl; // test
    
    // day code
    day_code = (century_code + day + year_code + month_code) % 7;
    //cout << "Day Code: " << day_code << endl; // test
    
    // day of the week
    if (day_code == 0) {
        day_of_the_week = "Sunday";
    }
    if ((day_code == 1) || (day_code == -6)) {
        day_of_the_week = "Monday";
    }
    if ((day_code == 2) || (day_code == -5)) {
        day_of_the_week = "Tuesday";
    }
    if ((day_code == 3) || (day_code == -4)) {
        day_of_the_week = "Wednesday";
    }
    if ((day_code == 4) || (day_code == -3)) {
        day_of_the_week = "Thursday";
    }
    if ((day_code == 5) || (day_code == -2)) {
        day_of_the_week = "Friday";
    }
    if ((day_code == 6) || (day_code == -1)) {
        day_of_the_week = "Saturday";
    }
    
    cout << month << " " << day << ", " << year << " was a " << day_of_the_week << "!" << endl;
    
    return(0);
}
