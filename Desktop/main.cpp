//
//  main.cpp
//  Algorithms Project
//
//  Created by Benjamin Logan on 9/14/18.
//  Copyright © 2018 Benjamin Logan. All rights reserved.
//

#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

class Code {
    public:
        void PrintSC();                                 // Prints Secret Code for grading purposes
        int checkCorrect(const Code &player) const;      // Returns correct digits in correct location
        int checkIncorrect(const Code &player) const;    // Returns correct digits in wrong location
        void randCode();                                // Creates Secret Code Randomly
        void humanGuess();                       // Asks User for Guess
        Code(int lengthN, int rangeM){                  // Constructor
            codeLengthN = lengthN;                      // Initializes Code Length
            codeRangeM = rangeM;                        // Initializes Code Range
        };
    
    private:
        int codeLengthN;                        // Secret Code Length
        int codeRangeM;                         // Secret Code Values Range
        vector<int> playerGuess;                // Players Guess Vector
        vector<int> SecretCode;                 // Secret Code Vector
};

void Code::randCode() {
    for (int x=0; x<codeLengthN; x++){
        int num = (rand() % codeRangeM + 1);
        SecretCode.push_back(num);
    }
}

void Code::PrintSC() {
    for(int i = 0; i < codeLengthN; i++){
        cout << SecretCode[i];
    }
    cout<<"\n";
}

void Code::humanGuess() {
    
    //cout << "Guess the " << codeLengthN << " number code with values from 0 to " << codeRangeM;
    //cout << "\n";
    playerGuess = {2,1,2,2,2};
}


int Code::checkCorrect(const Code &player) const {
    int count=0;
    for (int check = 0; check < codeLengthN; check++) {
        if(SecretCode[check] == player.playerGuess[check]) {
            count++;
            //cout<<check + 1<<"\n";
        }
    }
    return count;
}

int Code::checkIncorrect(const Code &player) const {
    int count = 0;
    for (int i = 0; i < codeLengthN; i++){
        for (int j = 0; i < codeLengthN - 1; i++){
            if (player.playerGuess[j] == SecretCode[i]) {
                if (j != i && SecretCode[i] != player.playerGuess[i]){
                    count++;
                    //cout<<j;
                }
            }
        }
    }
    return count;
}

int main() {
    
    int n;
    int m;
    
    cout << "Welcome to Mastermind: \n\nEnter the Length of the Secret Code: ";
    cin >> n;
    cout << "Enter a Range for the Secret Code Values: ";
    cin >> m;
    
    Code player(n,m);
    Code Code1(n,m);
    
    Code1.randCode();
    Code1.PrintSC();
    
    player.humanGuess();
    
    int correct = Code1.checkCorrect(player);
    int wrong_location = Code1.checkIncorrect(player);
    
    cout << "The Number of correct digits in the correct location is: " << correct << "\n";
    cout << "The Number of correct digits in wrong location: "<< wrong_location << "\n";

    return 0;
}
