//
//  Code.hpp
//  Project 1A
//
//  Created by Benjamin Logan and Owen Beringer on 9/20/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//
//  This function holds the class declaration for Code Class which contains the necessary
//            variables and functions for the game Mastermind

//  Class Code

#ifndef Code_hpp
#define Code_hpp

using namespace std;

#include <vector>
#include <stdio.h>

class Code {
public:
    void PrintSC();                                 // Prints Secret Code for grading purposes
    int checkCorrect(Code &player);                 // Returns correct digits in correct location
    int checkIncorrect(Code &player);               // Returns correct digits in wrong location
    void randCode();                                // Creates Secret Code Randomly
    void humanGuess();                              // Asks User for Guess
    Code(int lengthN, int rangeM){                  // Constructor
        codeLengthN = lengthN;                      // Initializes Code Length
        codeRangeM = rangeM;                        // Initializes Code Range
    };
    
private:
    int codeLengthN;                                // Secret Code Length
    int codeRangeM;                                 // Secret Code Values Range
    vector<int> CodeVect;                           // Players Guess Vector
};


#endif /* Code_hpp */
