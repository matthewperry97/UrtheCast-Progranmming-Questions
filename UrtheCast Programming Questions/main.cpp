//
//  main.cpp
//  UrtheCast Programming Questions
//
//  Created by Matthew Perry on 2020-05-06.
//  Copyright © 2020 Matthew Perry. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

#include "arrayMerging.h"
#include "fibonacciCalculator.h"

FibonacciCalculator fc = FibonacciCalculator();
ArrayMerger am = ArrayMerger();
int main(int argc, const char * argv[]) {
//    Calculate Fibanocci sequence
    
    const int index = 20; // ith value to calculate
    int fibonacciVal = fc.calculateFibonacci(index);
    std::cout << "Fibonacci value " << index << " = " << fibonacciVal << std::endl;
    
//    Add and remove from array
//    Original List = ['one', 'two', 'three',]
//    Add List = ['one', 'two', 'five', 'six]
//    Delete List = ['two', 'five']
//    Result List = ['three', 'six', 'one']
    
    std::vector<std::string> originalList = {"one", "two", "three"};
    std::vector<std::string> addList = {"one", "two", "five", "six"};
    std::vector<std::string> removeList = {"two", "five"};
    std::vector<std::string> resultList = am.calculateArray(originalList, addList, removeList);
    
    std::cout << "Resulting List: ";
    for (std::vector<std::string>::iterator iter = resultList.begin(); iter != resultList.end(); iter++) {
        std::cout << (*iter) << " ";
    }
    std::cout << std::endl;
    return 0;
}
