//
//  arrayMerging.cpp
//  UrtheCast Programming Questions
//
//  Created by Matthew Perry on 2020-05-06.
//  Copyright © 2020 Matthew Perry. All rights reserved.
//

#include "arrayMerging.h"

using namespace std;

// Public Methods
vector<string> ArrayMerger::calculateArray(const vector<string> &originalArray, const vector<string> &addArray, const vector<string> &removeArray) {
    vector<string> result = originalArray; // Create deep copy of originalArray
    this->addToArray(result, addArray);
    this->removeFromArray(result, removeArray);
    this->sortArray(result, result.begin(), result.end());
    return result;
}

// Private Methods
vector<string>::iterator ArrayMerger::sortPartition(vector<string> &array, vector<string>::iterator start, vector<string>::iterator end) {
    unsigned long pivot = (*end).length();
    
    for(vector<string>::iterator j = start; j <= end; j++) {
        unsigned long valueLength = (*j).length();
        if (valueLength <= pivot) {
            this->swapArrayValues(array, start, j);
            start++;
        }
    }
    
    this->swapArrayValues(array, start, end);
    return start++;
}

void ArrayMerger::addToArray(vector<string> &mainArray, const vector<string> &addArray) {
    for (vector<string>::const_iterator iter = addArray.begin(); iter != addArray.end(); iter++) {
        string value = *iter;
        
        // Add value to main array iff not in main array already
        if (find(mainArray.begin(), mainArray.end(), value) == mainArray.end()) {
            mainArray.push_back(value);
        }
    }
}

void ArrayMerger::removeFromArray(vector<string> &mainArray, const vector<string> &removeArray) {
    for (vector<string>::const_iterator iter = removeArray.begin(); iter != removeArray.end(); iter++) {
        string value = *iter;
        
        // Erase value from main array (assuming only 1 occurence in vector as designed above)
        vector<string>::iterator valueIter = find(mainArray.begin(), mainArray.end(), value);
        mainArray.erase(valueIter);
    }
}

// Most character count to least character count
// In the event of a tie, reverse alphabetical
void ArrayMerger::sortArray(vector<string> &array, vector<string>::iterator startIter, vector<string>::iterator endIter) {
//    Sort by largest character count to smallest
    sort(array.begin(), array.end(), []
         (const string &first, const string &second){
            if(first.length() > second.length()){
                return true;
            } else if (first.length() == second.length()) {
                return (second < first);
            }
            return false;
    });
    
//    Sub-sort by reverse alphabetical
//    for (vector<string>::iterator iter = array.begin(); iter != (array.end()-1); iter++){
//        string firstVal = *iter;
//        string secondVal = *(iter+1);
//        
//        if (firstVal.length() == secondVal.length()) {
//            if (secondVal > firstVal) {
//                *iter = secondVal;
//                *(iter+1) = firstVal;
//            }
//        }
//    }
}

void ArrayMerger::swapArrayValues(vector<string> &array, vector<string>::iterator low, vector<string>::iterator high) {
    long lowIndex = distance(array.begin(), low);
    long highIndex = distance(array.begin(), high);
    array[lowIndex] = (*high);
    array[highIndex] = (*low);
}
