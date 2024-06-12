#ifndef CAPITAL_H

#define CAPITAL_H

#include <iostream>
#include "City.h"

class Capital : public City {
    string state;   // data member state name
public:
    //Capital(string name);     // parameterized constructor taking city name as parameters
    Capital(string name, string state);    // parameterized constructor taking city and state name both as parameters
    string get_stateName();  // returns state name for the Capital city 

};

#endif

