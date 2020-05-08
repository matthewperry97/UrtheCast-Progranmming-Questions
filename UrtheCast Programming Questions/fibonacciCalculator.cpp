//
//  fibonacciCalculator.cpp
//  UrtheCast Programming Questions
//
//  Created by Matthew Perry on 2020-05-06.
//  Copyright © 2020 Matthew Perry. All rights reserved.
//

#include "fibonacciCalculator.h"

using namespace std;

int FibonacciCalculator::calculateFibonacci(int n) {
    if (n == 1) {
        return 1;
    } else if (n == 0) {
        return 0;
    }
    
    return calculateFibonacci(n-1) + calculateFibonacci(n-2);
};

