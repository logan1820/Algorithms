//
//  main.cpp
//  Algorithms Assignment 1A
//
//  This function contains the main and member functions for the game Mastermind
//
//  randCode, PrintSC, humanGuess, checkCorrect, checkIncorrect, getLength, getRange, and main;


//  Created by Benjamin Logan and Owen Beringer on 9/14/18.
//  Copyright © 2018 Benjamin Logan. All rights reserved.
//
#include "Code.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <ctime>

using namespace std;

void Code::randCode() {
    srand(time(0));
    for (int x=0; x<codeLengthN; x++){
        int num = (rand() % codeRangeM + 1);            // Random number created
        CodeVect.push_back(num);                        // Adds random number to secret vector
    }
}

void Code::PrintSC() {                                  // Prints CodeVect in Object
    cout<<"\nTHE SECRET CODE IS: ";
    for(int i = 0; i < codeLengthN; i++){
        cout << CodeVect[i] << " ";
    }
    cout<<"\n\n";
}

void Code::humanGuess() {                               // Asks for Players Guess
    int input;
    cout << "Enter " << codeLengthN << " integers from 0 to " << codeRangeM << ":\n";
    
    for (int i = 0; i < codeLengthN; i++) {
        cin >> input;
        while (cin.fail() or input > codeRangeM or input < 0) {  // Error Handling
            cout << "Error: Please enter a integer from 0 to " << codeRangeM << ": ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> input;
        }
        CodeVect.push_back(input);                      // Add values to CodeVector
    }
}

int Code::checkCorrect(Code &guess) {            // Checks for Correct values in correct location
    int count = 0;
    for (int check = 0; check < codeLengthN; check++) {
        if(CodeVect[check] == guess.CodeVect[check]) {
            count++;
            guess.CodeVect[check] = -1;          // Replaces these values with -1 to prevent reuse
        }
    }
    return count;
}

int Code::checkIncorrect(Code &guess) {      // Checks code for correct values in incorrect location
    int count = 0;
    for (int i = 0; i < codeLengthN; i++){
        for (int j = 0; j < guess.CodeVect.size(); j++){
            if (guess.CodeVect[i] == -1){   // If -1, than value was already used in checkCorrect
                break;}
            else {
                if (guess.CodeVect[j] == CodeVect[i]) {
                    count++;                // If correct value, replace with -2 to prevent reuse
                    guess.CodeVect[j] = -2;
                    break;
                }
            }
        }
    }
    return count;
}

int getLength() {           // Takes Input For N (Length) And Check For Errors
    int n;
    cout << "Welcome to Mastermind: \n\nEnter the Length of the Secret Code: ";
    cin >> n;
    
    while (cin.fail() or n < 0) {       //Error handling, clears incorrect input and asks again
        cout << "Error: Please enter a positive integer for Length: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> n;
    }
    return n;
}


int getRange() {            // Takes Input For M(Range) And Check For Errors
    int m;
    cout << "Enter a range for the secret code values: ";
    cin >> m;
    
    while (cin.fail() or m < 0) {       // Prevents input errors and reasks for range
        cout << "Error: Please enter a positive integer for Range: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> m;
    }
    return m;
}

int main() {
    
    int n = getLength();            // User input Code Length
    int m = getRange();             // User input Range Value
    
    Code guess(n,m);                // Declare guess Object (User Guess Code)
    Code Code1(n,m);                // Declare Code1 Object (Secret Code)

    Code1.randCode();               // Randomly spawns Secret code
    Code1.PrintSC();                // Prints secret code for grading purpose
    
    guess.humanGuess();             // Asks user for their guess
    
    int correct = Code1.checkCorrect(guess);          // Checks for correct values in correct spots
    int wrong_location = Code1.checkIncorrect(guess); // Checks for correct values in incorrect spots
    
    // Prints values as hint for their next guess
    cout << "The Number of correct digits in the correct location is: " << correct << "\n";
    cout << "The Number of correct digits in wrong location: "<< wrong_location << "\n";
}
