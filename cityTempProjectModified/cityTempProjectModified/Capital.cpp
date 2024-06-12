#ifndef CAPITAL_CPP
#define CAPITAL_CPP

#include <iostream>
#include "City.h"
#include "Capital.h"
using namespace std;

//Capital::Capital(string name) : City(name) {  // parameterized constructor taking city name as parameters
//    size = 4;
//    pTemp = new double* [size];
//    for (int i = 0; i < size; i++) {
//        pTemp[i] = new double[total_samples];
//    }
//}
Capital::Capital(string name, string state) : City(name) {    // parameterized constructor taking city and state name both as parameters
    size = 4;
    pTemp = new double* [size];
    for (int i = 0; i < size; i++) {
        pTemp[i] = new double[total_samples];
    }
    this->state = state;
}
string Capital::get_stateName() {    // returns state name for the Capital city 
    return this->state;
}

#endif
