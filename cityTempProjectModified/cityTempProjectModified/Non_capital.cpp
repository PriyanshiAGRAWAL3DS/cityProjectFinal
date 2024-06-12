#ifndef NON_CAPITAL_CPP
#define NON_CAPITAL_CPP

#include <iostream>
#include "City.h"
#include "Non_capital.h"
using namespace std;

Non_capital::Non_capital(string name) : City(name) {      // parameterized constructor
    size = 1;
    pTemp = new double* [size];
    pTemp[0] = new double[total_samples];
}

#endif
