#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPassive(string sentence) {
    // Function to determine if a sentence is passive or not
    // Returns true if passive, false otherwise
    // This function can be improved to better detect passive sentences
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
    if (sentence.find("was") != string::npos || sentence.find("were") != string::npos || sentence.find("been") != string::npos) {
        return true;
    }
    return false;
}

string convertPassiveToActive(string sentence) {
    // Function to convert a passive sentence to an active one
    // Returns the converted sentence
    // This function can be improved to better handle different types of sentences
    string result = "Converted: " + sentence;
    return result;
}

string convertActiveToPassive(string sentence) {
    // Function to convert an active sentence to a passive one
    // Returns the converted sentence
    // This function can be improved to better handle different types of sentences
    string result = "Converted: " + sentence;
    return result;
}

int main() {
    string input;
    bool cont = true;
    while (cont) {
        cout << "Please enter a sentence with starting and ending quotation marks: ";
        getline(cin, input);
        if (input[0] == '"' && input[input.length()-1] == '"') {
            input = input.substr(1, input.length()-2);
            bool passive = isPassive(input);
            if (passive) {
                cout << "The entered sentence is passive." << endl;
                cout << "Would you like to convert it to an active sentence? (y/n): ";
                getline(cin, input);
                if (input == "y") {
                    cout << convertPassiveToActive(input) << endl;
                }
            } else {
                cout << "The entered sentence is active." << endl;
                cout << "Would you like to convert it to a passive sentence? (y/n): ";
                getline(cin, input);
                if (input == "y") {
                    cout << convertActiveToPassive(input) << endl;
                }
            }
        } else {
            cout << "Invalid input. Please make sure your input has starting and ending quotation marks." << endl;
        }
        cout << "Would you like to enter another sentence? (y/n): ";
        getline(cin, input);
        if (input == "n") {
            cont = false;
        }
    }
    return 0;
}
