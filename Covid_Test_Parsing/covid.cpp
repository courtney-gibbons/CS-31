#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isValidResultString(string results);
int positiveTests(string results);
int negativeTests(string results);
int totalTests(string results);
int batches(string results);
void getInformation(bool& isValidResultString, int& totalPositiveTests, int& totalNegativeTests, int& totalTotalTests, int& batches, string results);

int main() {
    
    string s = " ";
    isValidResultString(s);
    positiveTests(s);
    negativeTests(s);
    totalTests(s);
    batches(s);
    
//    string s;
//    cout.setf( ios::boolalpha ); // prints bool values as "true" or "false"
//
//    for(;;) {
//        cout << "Enter a possible result string: ";
//        getline(cin, s); if (s == "quit") break;
//        cout << "isValidResultString returns ";
//        cout << isValidResultString(s) << endl;
//        cout << "positiveTests(s) returns ";
//        cout << positiveTests(s) << endl;
//        cout << "negativeTests(s) returns ";
//        cout << negativeTests(s) << endl;
//        cout << "totalTests(s) returns ";
//        cout << totalTests(s) << endl;
//        cout << "batches(s) returns ";
//        cout << batches(s) << endl;
//    }
    
    return( 0 );
}

bool isValidResultString(string results) {
    // declare variables
    bool isValidResultString = false;
    int positiveTests = 0;
    int negativeTests = 0;
    int totalTests = 0;
    int batches = 1;

    // run function getInformation - uses pass by reference to change variables
    getInformation(isValidResultString, positiveTests, negativeTests, totalTests, batches, results);

    // make sure bools return as true/false not 1/0
    cout.setf(ios::boolalpha);

    // return
    return(isValidResultString);
}

int positiveTests(string results) {
    // declare variables
    bool isValidResultString = false;
    int positiveTests = 0;
    int negativeTests = 0;
    int totalTests = 0;
    int batches = 1;

    // run function getInformation - uses pass by reference to change variables
    getInformation(isValidResultString, positiveTests, negativeTests, totalTests, batches, results);

    // make sure bools return as true/false not 1/0
    cout.setf(ios::boolalpha);

    // if the string is invalid, return -1
    if (isValidResultString == false) {
        return(-1);
    }

    // return
    return(positiveTests);
}

int negativeTests(string results) {
    // declare variables
    bool isValidResultString = false;
    int positiveTests = 0;
    int negativeTests = 0;
    int totalTests = 0;
    int batches = 1;

    // run function getInformation - uses pass by reference to change variables
    getInformation(isValidResultString, positiveTests, negativeTests, totalTests, batches, results);

    // make sure bools return as true/false not 1/0
    cout.setf(ios::boolalpha);

    // if the string is invalid, return -1
    if (isValidResultString == false) {
        return(-1);
    }

    // return
    return(negativeTests);
}

int totalTests(string results) {
    // declare variables
    bool isValidResultString = false;
    int positiveTests = 0;
    int negativeTests = 0;
    int totalTests = 0;
    int batches = 1;

    // run function getInformation - uses pass by reference to change variables
    getInformation(isValidResultString, positiveTests, negativeTests, totalTests, batches, results);

    // make sure bools return as true/false not 1/0
    cout.setf(ios::boolalpha);

    // if the string is invalid, return -1
    if (isValidResultString == false) {
        return(-1);
    }

    // return
    return(totalTests);
}

int batches(string results) {
    // declare variables
    bool isValidResultString = false;
    int positiveTests = 0;
    int negativeTests = 0;
    int totalTests = 0;
    int batches = 1;

    // run function getInformation - uses pass by reference to change variables
    getInformation(isValidResultString, positiveTests, negativeTests, totalTests, batches, results);

    // make sure bools return as true/false not 1/0
    cout.setf(ios::boolalpha);

    // if the string is invalid, return -1
    if (isValidResultString == false) {
        return(-1);
    }

    // return
    return(batches);
}

void getInformation(bool& isValidResultString, int& totalPositiveTests, int& totalNegativeTests, int& totalTotalTests, int& batches, string results) {
    
    // initialize strings and integers
    string positiveTests, negativeTests, totalTests;
    int intPositiveTests = 0, intNegativeTests = 0, intTotalTests = 0;
    
    while (results.size() > 0) {
        // check if 0th character is R
        if (results[0] != 'R') {
            isValidResultString = false;
            return;
        }
        // subtract R
        results = results.substr(1, results.size()-1);
        // check if 0th character is 0 - can't have leading 0s or 0 tests
        if (results[0] == '0') {
            isValidResultString = false;
            return;
        }
        for (size_t k = 0; k != results.size(); k++) {
            // loops through number of total tests until finds a + or -
            if ((results[k] == '+') || (results[k] == '-')) {
                // remove from string up until + or - (for reference later)
                results = results.substr(k, results.size()-k);
                // check if 1st character is 0 AND 2nd character is a digit - can't have leading 0s
                if ((results[1] == '0') && (isdigit(results[2]) == true)) {
                    isValidResultString = false;
                    return;
                }
                for (size_t k = 1; k != results.size(); k++) {
                    // loops through number of tests until finds a + or -
                    // check if a + or - is directly following the previous + or -
                    if ((results[1] == '+') || (results[1] == '-')) {
                        isValidResultString = false;
                        return;
                    }
                    // check to see if + then - or - then +
                    // can't have + + or - -
                    if (((results[k] == '-') && (results[0] == '+')) || ((results[k] == '+') && (results[0] == '-'))) {
                        // remove from string up until + or - (for reference later)
                        results = results.substr(k, results.size()-k);
                        // check if empty after + or - - need a full string
                        if ((results == "+") || (results == "-")) {
                            isValidResultString = false;
                            return;
                        }
                        // check if 1st character is 0 AND 2nd character is a digit - can't have leading 0s
                        if ((results[1] == '0') && (isdigit(results[2]) == true)) {
                            isValidResultString = false;
                            return;
                        }
                        for (size_t k = 1; k != results.size()+1; k++) {
                            // loops through number of tests until it ends or finds an R
                            if ((k == results.size()) || results[k] == 'R') {
                                // calculate integer values for the tests
                                // subtract ASCII value for 0 to get the number
                                for (size_t k = 0; k != positiveTests.size(); k++) {
                                    intPositiveTests = intPositiveTests*10 + (positiveTests[k] - '0');
                                }
                                for (size_t k = 0; k != negativeTests.size(); k++) {
                                    intNegativeTests = intNegativeTests*10 + (negativeTests[k] - '0');
                                }
                                for (size_t k = 0; k != totalTests.size(); k++) {
                                    intTotalTests = intTotalTests*10 + (totalTests[k] - '0');
                                }
                                // make sure positive + negative = total tests
                                if (intPositiveTests + intNegativeTests != intTotalTests) {
                                    isValidResultString = false;
                                    return;
                                }
                                // add to variables total _ tests
                                totalPositiveTests += intPositiveTests;
                                totalNegativeTests += intNegativeTests;
                                totalTotalTests += intTotalTests;
                                // set the test variables back to empty and 0 to make the conversion to int easier
                                positiveTests = "";
                                negativeTests = "";
                                totalTests = "";
                                intPositiveTests = 0;
                                intNegativeTests = 0;
                                intTotalTests = 0;
                                // if we've reached the end of our string, return
                                if (k == results.size()) {
                                    isValidResultString = true;
                                    return;
                                }
                                // if we have another batch, increment batch, remove everything up until the R and break out
                                // need to keep R so can pass R test at the start
                                if (results[k] == 'R') {
                                    batches++;
                                    results = results.substr(k, results.size()-k);
                                    break;
                                }
                            }
                            // add to positive tests if +, negative tests is -
                            if (results[0] == '+') {
                                positiveTests += results[k];
                            }
                            if (results[0] == '-') {
                                negativeTests += results[k];
                            }
                            // check to make sure if it's not an R, it's a digit
                            if (!isdigit(results[k])) {
                                isValidResultString = false;
                                return;
                            }
                        }
                    }
                    // break out of this loop if we have already reached the end of a batch
                    if (results[0] == 'R') {
                        break;
                    }
                    // check to make sure if it's not a + or -, it's a digit
                    if (!isdigit(results[k])) {
                        isValidResultString = false;
                        return;
                    }
                    // add to positive tests if +, negative tests is -
                    if (results[0] == '+') {
                        positiveTests += results[k];
                    }
                    if (results[0] == '-') {
                        negativeTests += results[k];
                    }
                }
            }
            // break out of this loop if we have already reached the end of a batch
            if (results[0] == 'R') {
                break;
            }
            // check if 0th character is + or - - can't skip total test number
            if ((results[0] == '+') || (results[0] == '-')) {
                isValidResultString = false;
                return;
            }
            // check to make sure if it's not a + or -, it's a digit
            if (!isdigit(results[k])) {
                isValidResultString = false;
                return;
            }
            // add to total tests
            totalTests += results[k];
        }
    }
    isValidResultString = false;
    return;
}
