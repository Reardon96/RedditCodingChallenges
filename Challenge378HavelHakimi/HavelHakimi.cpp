// Challenge 378 - Havel-Hakimi.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> zeroElimination(vector<int> vec) {
    vec.erase(remove(vec.begin(), vec.end(), 0), vec.end());
    return vec;
}

vector<int> descendingSort(vector<int> vec) {

    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    return vec;
}

bool lengthCheck(unsigned int n, vector<int> vec) {

    if (n > vec.size()) {
        return true;
    }
    else {
        return false;
    }
}

vector<int> frontElimination(int n, vector<int> vec) {

    for (int i = 0; i < n; i++) {
        vec[i] = vec[i] - 1;
    }
    return vec;
}

int main()
{
    vector<int> inputVector = { 5, 3, 0, 2, 6, 2, 0, 7, 2, 5 };
    bool algorithmResult = false;
    int n = 0;
    int iteration = 1;
  
    while (true) {
        // Remove all 0's from the sequence
        inputVector = zeroElimination(inputVector);
        
        // If the sequence is now empty, stop and return true
        if (inputVector.size() == 0) {
            algorithmResult = true;
            break;
        }

        // Sort the sequence in descending order 
        inputVector = descendingSort(inputVector);

        // Remove the first answer and call it n
        n = inputVector[0];
        inputVector.erase(inputVector.begin());

        // If n is greater than the length of this new sequence, stop and return false
        if (lengthCheck(n, inputVector) == true) {
            algorithmResult = false;
            break;
        }

        // Subtract 1 from each of the first N elements of the new sequence
        inputVector = frontElimination(n, inputVector); 
        
        // Output vector to console
        cout << "\n" << "Iteration " << iteration << ": [ ";
        for (unsigned int i = 0; i < inputVector.size(); i++) {
            cout << inputVector[i] << " ";
        }
        cout << "]";

        iteration++;
    }
    cout << "\n" << algorithmResult;
}

