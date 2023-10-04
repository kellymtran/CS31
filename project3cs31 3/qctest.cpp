#include <cassert>
#include <iostream>
#include <string>

using namespace std;

bool isValidQC(string results) {
    int i = 0; //start i at 0 to allow i as index to read through the string
    
    while (i < results.length()) {
        int countPasses = 0;
        int countDefects = 0;
        int countTests = 0; //start passes, defects, and tests at 0 to start count for later
        
        if (results[i] != 'Q') return false; //if the results don't start with "Q" then it's not valid
        if (results[i] == 'Q') i++; //if the results do start with "Q" then we incrememt i to move onto the next character
        
        if (results[i] == '0' || (!isdigit(results[i]))) return false; //If the results after Q are zero or it's not a digit, then we return false
        
        for (; isdigit(results[i]); i++) { //if it is a digit, then we continue on with counting the values inside Q
            countTests = countTests * 10 + results[i] - '0';
        } //we count the value inside Q by multiplying the count with 10 to get it in the right place, and then we add the value in the index and subtract that by the value of character '0' in the ASCII table to get our true value, and repeat the steps until we reach a character that is not a digit.
        
        if (results[i] == 'd') {
            i++; //we use an if statement to see if d or p comes next
            if (isdigit(results[i]) == false) return false;
            else { //if it's not a digit, then we return false
                for (; isdigit(results[i]); i++) {
                    countDefects = countDefects * 10 + results[i] - '0';
                } //if it is a digit, then we count up the value the same way as in the first for-loop mentioned.
                
                if (results[i] != 'p') return false;
                else { //we follow up with "p" in this scenario because we already started with "d", and then we do the same thing
                    i++;
                    if (results[i] == '0' || !isdigit(results[i])) return false;
                    else {
                        for (; isdigit(results[i]); i++) {
                            countPasses = countPasses * 10 + results[i] - '0';
                        }
                    }
                }
            }
        }
        
        else if (results[i] == 'p') { //scenario where "p" comes before "d"
            i++;
            if (!isdigit(results[i])) return false;
            else {
                for (; isdigit(results[i]); i++) {
                    countPasses = countPasses * 10 + results[i] - '0';
                }
                
                if (results[i] != 'd') return false;
                else {
                    i++;
                    if (!isdigit(results[i])) return false;
                    else {
                        for (; isdigit(results[i]); i++) {
                            countDefects = countDefects * 10 + results[i] - '0';
                        }
                    }
                }
            }
        }

        if (countPasses + countDefects != countTests) return false; //we make sure that the passes and defects add up to the number of tests run, and if not then we return false
    }
    return true; //if all criteria is followed, then we return true
}

int passQC(string results) { //this is to count number of passes overall
    int totalPasses = 0;
    if (!isValidQC(results)) return -1; //if string is invalid, we return -1

    for (int i = 0; i < results.length(); i++) {
        if (results[i] == 'p') { //we count throughout the length of the string and look for where the index is the character p, and we initialize countPasses as 0, and increment i to move onto the next character.
            int countPasses = 0;
            i++;
            for (; i < results.length() && isdigit(results[i]); i++) {
                countPasses = countPasses * 10 + (results[i] - '0');
            } //we make sure that the next character is a digit, and we add up the values the same way as before
            totalPasses += countPasses;
        } //after every iteration, we add the countPasses to the totalPasses, so we can return the totalPasses later.
    }
    
    return totalPasses;
}

int defectQC(string results) { //same method as with the passes.
    int totalDefects = 0;
    if (!isValidQC(results)) return -1;

    for (int i = 0; i < results.length(); i++) {
        if (results[i] == 'd') {
            int countDefects = 0;
            i++;
            for (; i < results.length() && isdigit(results[i]); i++) {
                countDefects = countDefects * 10 + (results[i] - '0');
            }
            totalDefects += countDefects;
        }
    }
    
    return totalDefects;
}

int totalQC(string results) { //same method was with the passes and defects.
    int totalTests = 0;
    if (!isValidQC(results)) return -1;

    for (int i = 0; i < results.length(); i++) {
        if (results[i] == 'Q') {
            int countTests = 0;
            i++;
            for (; i < results.length() && isdigit(results[i]); i++) {
                countTests = countTests * 10 + (results[i] - '0');
            }
            totalTests += countTests;
        }
    }
    return totalTests;
}

int batches(string results) { //for batches, we look for where the index is the character Q, and we add that to the overall total of batches.
    int Batches = 0;
    if (!isValidQC(results)) return -1;

    for (int i = 0; i < results.length(); i++) {
        if (results[i] == 'Q') {
            Batches++;
        }
    }
    return Batches;
}

int main()
 {
     string s;
           cout.setf( ios::boolalpha );
            for(;;)
            {
                cout << "Enter a possible teststring: ";
                getline(cin, s); if (s == "quit") break;
                cout << "isValidQC returns ";
                cout << isValidQC(s) << endl;
                cout << "pass test result(s) returns ";
                cout << passQC(s) << endl;
                cout << "defectQC(s) returns ";
                cout << defectQC(s) << endl;
                cout << "totalQC(s) returns ";
                cout << totalQC(s) << endl;
                cout << "batches(s) returns ";
                cout << batches(s) << endl;
     }
            return( 0 );
 }
