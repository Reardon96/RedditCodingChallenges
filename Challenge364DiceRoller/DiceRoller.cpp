// Challenge 364 - Dice Roller.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <ctime>
#include <array>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int randomNumberGenerator(int numSides) 
{
    int diceRoll = rand() % numSides + 1;
    return diceRoll;
}

int sumRoll(int numDice, int numSides) 
{
    int result = 0;
    int currentRoll = 0;
    for (int i = 0; i < numDice; i++) 
    {
        currentRoll = randomNumberGenerator(numSides);
        result += currentRoll;
        cout << "Roll " << i + 1 << ": " << currentRoll << "\n";
    }
    cout << "Total: " << result;
    return result;
}

vector<int> parseInput(string input)
{
    replace(input.begin(), input.end(), 'd', ' ');
    vector<int> arr;
    stringstream ss(input);
    int temp;
    while (ss >> temp)
    {
        arr.push_back(temp);
    }
    return arr;
}

int main()
{
    vector<int> userInputParsed;
    string userInput;
    cout << "Input dice roll: ";
    cin >> userInput;
    userInputParsed = parseInput(userInput);

    srand((int)time(0));
    sumRoll(userInputParsed.at(0), userInputParsed.at(1));
}



