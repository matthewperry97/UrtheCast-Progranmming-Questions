//
//  arrayMerging.h
//  UrtheCast Programming Questions
//
//  Created by Matthew Perry on 2020-05-06.
//  Copyright © 2020 Matthew Perry. All rights reserved.
//

#ifndef arrayMerging_h
#define arrayMerging_h

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

class ArrayMerger{
public:
    ArrayMerger(){}
    ~ArrayMerger(){}
    std::vector<std::string> calculateArray(const std::vector<std::string> &originalArray, const std::vector<std::string> &addArray, const std::vector<std::string> &removeArray);
private:
    std::vector<std::string>::iterator sortPartition(std::vector<std::string> &array, std::vector<std::string>::iterator start, std::vector<std::string>::iterator end);
    void addToArray(std::vector<std::string> &mainArray, const std::vector<std::string> &addArray);
    void removeFromArray(std::vector<std::string> &mainArray, const std::vector<std::string> &removeArray);
    void sortArray(std::vector<std::string> &array, std::vector<std::string>::iterator start, std::vector<std::string>::iterator end);
    void swapArrayValues(std::vector<std::string> &array, std::vector<std::string>::iterator low, std::vector<std::string>::iterator high);
};

#endif /* arrayMerging_h */
