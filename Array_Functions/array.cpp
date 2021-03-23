#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

int locateMaximum( const  string  array[ ],  int  n );
int countFloatingPointValues( const string array[ ], int  n );
bool hasNoCapitals( const string array[ ], int n );
bool identicalValuesTogether( const string array[ ], int n);
bool hasTwoOrMoreDuplicates( const string array[ ], int  n );
int shiftLeft( string array[ ], int n, int amount, string placeholder );
int replaceFirstAndLastOccurrences( string array[ ], int n, char charToFind, char charToReplace );


int main() {
    string folks[8] = { "samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "magdalena", "jon" };
    string data[5] = { "mamaBbcca", "mamaBbcca", "12", "98.76", "tyrion" };
    string string1[10] = { "AA", "BB", "BB", "BB", "cc", "dd", "ee", "ee", "0.1.0", "0.0" };
    string string2[7] = { "55.", "4A", "35", "55.", "15.0", "15.0", "A12A" };
    string string3[8] = { "55.", "4A", "35", "35", "35", "35", "A12A", "35" };
    string string4[2] = { ",55.", "4A" };
    string string5[2] = { "+55.", "4A" };
    string string6[3] = { "-55.", "4A", ".55." };
    string string7[3] = { ".", "", "55." };
    string lecture1[8] = { "A", "B", "C", "D", "E", "F", "G", "H" };
    string lecture2[4] = { "A", "Basdfads", "Casddasdf", "Casddasdf" };
    string lecture3[5] = { "a", "a", "b", "c", "b" };
    string lecture4[5] = { "a", "a", "b", "a", "a" };
    string lecture5[4] = { "a", "a", "b", "b" };
    string lecture6[5] = { "a", "a", "a", "c", "b" };
    string lecture7[5] = { "a", "a", "a", "a", "b" };
    string lecture8[5] = { "a", "a", "a", "a", "b" };
    string lecture9[4] = { "AAA", "ABA", "ACAAA", "zzzzzA" };

    // MAXIMUM
    // 1 max
    assert( locateMaximum( data, 5 ) == 4 );
    assert( locateMaximum( lecture1, 4 ) == 3 );
    assert( locateMaximum( lecture2, 4 ) == 2 );
    // 2 max - return first max
    assert( locateMaximum( string1, 8 ) == 6 );
    // n < 0
    assert( locateMaximum( string1, -8 ) == -1 );
    // n = 0
    assert( locateMaximum( lecture2, 0 ) == -1 );

    // COUNT FLOATS
    // multiple floats (no decimal and decimal)
    assert( countFloatingPointValues( data, 5 ) == 2 );
    assert( countFloatingPointValues( string2, 7 ) == 5 );
    // multiple decimal points
    assert( countFloatingPointValues( string1, 10 ) == 1 );
    assert( countFloatingPointValues( string6, 3 ) == 0 );
    // just decimal point "."
    assert( countFloatingPointValues( string7, 3 ) == 2 );
    // 0 floats
    assert( countFloatingPointValues( data, 2 ) == 0 );
    // commas
    assert( countFloatingPointValues( string4, 2 ) == 0 );
    // +
    assert( countFloatingPointValues( string5, 2 ) == 0 );
    // -
    assert( countFloatingPointValues( string6, 2 ) == 0 );
    // n < 0
    assert( countFloatingPointValues( string6, -1 ) == -1 );
    // n = 0
    assert( countFloatingPointValues( string6, 0 ) == -1 );

    // NO CAPS
    // yes caps
    assert( hasNoCapitals( data, 5 ) == false );
    // yes caps in numbers
    assert( hasNoCapitals( string2, 7 ) == false );
    // no caps
    assert( hasNoCapitals( folks, 8 ) == true );
    // n < 0
    assert( hasNoCapitals( folks, -8 ) == true );
    // n = 0
    assert( hasNoCapitals( folks, 0 ) == true );

    // IDENTICAL VALUES TOGETHER
    // no identical values
    assert( identicalValuesTogether( folks, 6 ) == true );
    // identical values but not together
    assert( identicalValuesTogether( folks, 8 ) == false );
    // some identical values together, others not
    assert( identicalValuesTogether( string2, 7 ) == false );
    assert( identicalValuesTogether( lecture3, 5 ) == false );
    // some identical values together, others not AND they are the same char
    assert( identicalValuesTogether( lecture4, 5 ) == false );
    // all identical values together
    assert( identicalValuesTogether( data, 5 ) == true );
    // 3+ identical values in a row
    assert( identicalValuesTogether( string1, 8 ) == true );
    assert( identicalValuesTogether( string3, 7 ) == true );
    // 3+ identical values in a row, other identicals not together
    assert( identicalValuesTogether( string3, 8 ) == false );
    // n < 0
    assert( identicalValuesTogether( folks, -6 ) == false );
    // n = 0
    assert( identicalValuesTogether( folks, 0 ) == false );

    // 2+ DUPLICATES
    // 0 duplicates
    assert( hasTwoOrMoreDuplicates( string6, 2 ) == false );
    // 1 pair of duplicates
    assert( hasTwoOrMoreDuplicates( folks, 8 ) == false );
    // 2 pairs of duplicates
    assert( hasTwoOrMoreDuplicates( string2, 7 ) == true );
    assert( hasTwoOrMoreDuplicates( lecture3, 5 ) == true );
    assert( hasTwoOrMoreDuplicates( lecture5, 4 ) == true );
    // 3+ of the same (counts as 2+ duplicates)
    assert( hasTwoOrMoreDuplicates( string1, 8 ) == true );
    assert( hasTwoOrMoreDuplicates( string3, 8 ) == true );
    assert( hasTwoOrMoreDuplicates( lecture4, 5 ) == true );
    assert( hasTwoOrMoreDuplicates( lecture6, 5 ) == true );
    assert( hasTwoOrMoreDuplicates( lecture7, 5 ) == true );
    assert( hasTwoOrMoreDuplicates( lecture8, 5 ) == true );
    // n < 0
    assert( hasTwoOrMoreDuplicates( string6, -2 ) == false );
    // n = 0
    assert( hasTwoOrMoreDuplicates( string6, 0 ) == false );

    // SHIFT LEFT
    // amount < n
    assert( shiftLeft( data, 5, 2, "foo" ) == 2 );
    assert( data[0] == "12" );
    assert( data[1] == "98.76" );
    assert( data[2] == "tyrion" );
    assert( data[3] == "foo" );
    assert( data[4] == "foo" );
    data[0] = "mamaBbcca";
    data[1] = "mamaBbcca";
    data[2] = "12";
    data[3] = "98.76";
    data[4] = "tyrion";
    // amount < n, n < total length of array
    assert( shiftLeft( data, 3, 2, "foo" ) == 2 );
    assert( data[0] == "12" );
    assert( data[1] == "foo" );
    assert( data[2] == "foo" );
    assert( data[3] == "98.76" );
    assert( data[4] == "tyrion" );
    data[0] = "mamaBbcca";
    data[1] = "mamaBbcca";
    data[2] = "12";
    data[3] = "98.76";
    data[4] = "tyrion";
    // amount > n
    assert( shiftLeft( data, 5, 10, "bar" ) == 5 );
    assert( data[0] == "bar" );
    assert( data[1] == "bar" );
    assert( data[2] == "bar" );
    assert( data[3] == "bar" );
    assert( data[4] == "bar" );
    data[0] = "mamaBbcca";
    data[1] = "mamaBbcca";
    data[2] = "12";
    data[3] = "98.76";
    data[4] = "tyrion";
    // amount < 0
    assert( shiftLeft( data, 5, -5, "foobar" ) == -1 );
    assert( data[0] == "mamaBbcca" );
    assert( data[1] == "mamaBbcca" );
    assert( data[2] == "12" );
    assert( data[3] == "98.76" );
    assert( data[4] == "tyrion" );
    // n < 0
    assert( shiftLeft( data, -5, 5, "foobar" ) == -1 );
    assert( data[0] == "mamaBbcca" );
    assert( data[1] == "mamaBbcca" );
    assert( data[2] == "12" );
    assert( data[3] == "98.76" );
    assert( data[4] == "tyrion" );
    // n = 0
    assert( shiftLeft( data, -5, 5, "foobar" ) == -1 );
    assert( data[0] == "mamaBbcca" );
    assert( data[1] == "mamaBbcca" );
    assert( data[2] == "12" );
    assert( data[3] == "98.76" );
    assert( data[4] == "tyrion" );
    // amount = 0
    assert( shiftLeft( data, 5, 0, "foobar" ) == 0 );
    assert( data[0] == "mamaBbcca" );
    assert( data[1] == "mamaBbcca" );
    assert( data[2] == "12" );
    assert( data[3] == "98.76" );
    assert( data[4] == "tyrion" );

    // REPLACE FIRST AND LAST
    // no char to find
    assert( replaceFirstAndLastOccurrences( folks, 8, 'A', 'Z' ) == 0 );
    // n < 0
    assert( replaceFirstAndLastOccurrences( folks, -10, 'A', 'Z' ) == -1 );
    // n = 0
    assert( replaceFirstAndLastOccurrences( folks, 0, 'A', 'Z' ) == -1 );
    // some strings have no char to find, others have 1, others have 2, others have 3+
    assert( replaceFirstAndLastOccurrences( folks, 8, 'a', 'Z' ) == 8 );
    assert( folks[0] == "sZmwell" );
    assert( folks[1] == "jon" );
    assert( folks[2] == "mZrgZery" );
    assert( folks[3] == "dZenerys" );
    assert( folks[4] == "tyrion" );
    assert( folks[5] == "sZnsZ" );
    assert( folks[6] == "mZgdalenZ" );
    assert( folks[7] == "jon" );
    folks[0] = "samwell";
    folks[1] = "jon";
    folks[2] = "margaery";
    folks[3] = "daenerys";
    folks[4] = "tyrion";
    folks[5] = "sansa";
    folks[6] = "magdalena";
    folks[7] = "jon";
    assert( replaceFirstAndLastOccurrences( lecture9, 4, 'A', 'z' ) == 7 );
    assert( lecture9[0] == "zAz" );
    assert( lecture9[1] == "zBz" );
    assert( lecture9[2] == "zCAAz" );
    assert( lecture9[3] == "zzzzzz" );
    lecture9[0] = "AAA";
    lecture9[1] = "ABA";
    lecture9[2] = "ACAAA";
    lecture9[3] = "zzzzzA";
    // char to find = char to replace
    assert( replaceFirstAndLastOccurrences( folks, 8, 'a', 'a' ) == 8 );
    assert( folks[0] == "samwell" );
    assert( folks[1] == "jon" );
    assert( folks[2] == "margaery" );
    assert( folks[3] == "daenerys" );
    assert( folks[4] == "tyrion" );
    assert( folks[5] == "sansa" );
    assert( folks[6] == "magdalena" );
    assert( folks[7] == "jon" );
    assert( replaceFirstAndLastOccurrences( lecture9, 4, 'A', 'A' ) == 7 );
    assert( lecture9[0] == "AAA" );
    assert( lecture9[1] == "ABA" );
    assert( lecture9[2] == "ACAAA" );
    assert( lecture9[3] == "zzzzzA" );

    cerr << "All tests succeeded" << endl;

    return 0;
}

int locateMaximum( const  string  array[ ],  int  n ) {
    // set max index = 0 to start
    int max = 0;
    
    // loop through array comparing the strings
    // update index if a new max is found
    for (int i = 1; i < n; i++) {
        if (array[i] > array[max]) {
            max = i;
        }
    }
    
    // return -1 if n <= 0
    if (n <= 0) {
        max = -1;
    }
    
    return(max);
}

int countFloatingPointValues( const string array[ ], int  n ) {
    // float count = 0, decimal check = false to start
    int floats = 0;
    int decimal = false;
    
    // loop through array
    for (int i = 0; i < n; i++) {
        string s = array[i];
        // loop through characters of each string inside the array
        for (size_t j = 0; j < s.length(); j++) {
            // if we find a character that is not a digit or decimal point
            // break out and try the next string in the array
            if ( (!isdigit(s[j])) && (s[j] != '.') ) {
                // set decimal back to false
                decimal = false;
                break;
            }
            
            // if we've found another decimal point
            // break out and try the next string in the array
            if ( (s[j] == '.') && (decimal == true)  ) {
                // set decimal back to false
                decimal = false;
                break;
            }
            
            // if we find our first decimal point, set decimal to true
            // we can only enter if decimal is still false
            if ( (s[j] == '.') && (decimal == false)  ) {
                decimal = true;
            }
            
            // if we make it through the string without breaking out
            // it's a float, increment float count
            if (j == s.length() - 1) {
                // set decimal back to false
                decimal = false;
                floats++;
            }
        }
    }
    
    // return -1 if n <= 0
    if (n <= 0) {
        floats = -1;
    }
    
    return(floats);
}

bool hasNoCapitals( const string array[ ], int n ) {
    // default no capitals, try to prove this wrong
    bool noCapitals = true;
    
    // loop through array
    for (int i = 0; i < n; i++) {
        string s = array[i];
        // loop through characters of each string inside the array
        for (size_t j = 0; j < s.length(); j++) {
            // if we find a character that is uppercase, set capitals to false
            // break out
            if (isupper(s[j])) {
                noCapitals = false;
                break;
            }
        }
    }
    
    // return -1 if n <= 0
    if (n <= 0) {
        noCapitals = true;
    }
    
    return(noCapitals);
}

bool identicalValuesTogether( const string array[ ], int n) {
    // set identical together to true to start
    // if no identical values, technically all are together - true
    bool identicalTogether = true;
    
    // loop through array with a nested loop
    // start j after i - if we find a duplicate, its guaranteed to be before j index
    // if we find duplicate values, make sure there's a duplicate before it
    // basically checking for gaps
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] == array[j] && (i != j) ) {
                if (array[j] != array[j - 1]) {
                    identicalTogether = false;
                }
            }
        }
    }
    
    // return false if n <= 0
    if (n <= 0) {
        identicalTogether = false;
    }
    
    return(identicalTogether);
}

bool hasTwoOrMoreDuplicates( const string array[ ], int  n ) {
    // duplicates = false to start, prove true
    bool duplicates = false;
    int count = 0;
    
    // loop through array with a nested loop
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // check if 2 strings in the array are equal and don't have the same index
            // since we're doing a nested loop we have to make sure we're not looking at the exact same element
            if ( (i != j) && (array[i] == array[j]) ) {
                count++;
            }
        }
    }
    
    // return false if n <= 0
    if (n <= 0) {
        duplicates = false;
    }
    
    // need more than 1 pair of duplicates to be true
    if (count > 2) {
        duplicates = true;
    }
    
    return(duplicates);
}

int shiftLeft( string array[ ], int n, int amount, string placeholder ) {
    // make sure n > 0 and amount >= 0 so we don't walk off the edge
    if ( (n > 0) && (amount >= 0)) {
        // loop through array
        for (int i = 0; i < n; i++) {
            // if there's nothing to shift over, input the placeholder
            if (i+amount >= n) {
                array[i] = placeholder;
            }
            // shift the rest over by amount
            else {
                array[i] = array[i+amount];
            }
        }
        // if amount goes past n, changed values only = n
        if (amount > n) {
            amount = n;
        }
    }
    
    // return -1 if n <= 0 or amount < 0
    else {
        amount = -1;
    }
    
    return(amount);
}

int replaceFirstAndLastOccurrences( string array[ ], int n, char charToFind, char charToReplace ) {
    // replacements = 0 to start
    int replacements = 0;
    int count = 0;
    
    // if the characters passed in are the same
    if (charToFind == charToReplace) {
        // loop through array
        for (int i = 0; i < n; i++) {
            string s = array[i];
            // loop through characters of each string inside the array
            for (size_t j = 0; j < s.length(); j++) {
                // if we find the desired character, increment the count
                // don't change bc no reason to
                if (s[j] == charToFind) {
                    count++;
                }
            }
            // only "changing" first and last occurances
            // if we find more than duplicates, set to 2
            if (count > 2) {
                count = 2;
            }
            // update number of replacements
            // set count back to 0 for next string
            replacements += count;
            count = 0;
        }
    }
    // general case where characters passed in are different
    else {
        // loop through array
        for (int i = 0; i < n; i++) {
            string s = array[i];
            // loop through characters of each string inside the array FORWARDS
            for (size_t j = 0; j < s.length(); j++) {
                // once we find the first character to replace, change it, increment replacements, and break out
                if (s[j] == charToFind) {
                    s[j] = charToReplace;
                    replacements++;
                    break;
                }
            }
            // loop through characters of each string inside the array BACKWARDS
            for (size_t k = s.length(); k > 0; k--) {
                // once we find the first character to replace (backwards), change it, increment replacements, and break out
                if (s[k-1] == charToFind) {
                    s[k-1] = charToReplace;
                    replacements++;
                    break;
                }
            }
            array[i] = s;
        }
    }
    
    // return -1 if n <= 0
    if (n <= 0) {
        replacements = -1;
    }
    
    return(replacements);
}
