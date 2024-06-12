#ifndef CONVERTER_H
#define CONVERTER_H

#include "Menu.h"
#include "City.h"
#include "Capital.h"
#include "Non_capital.h"
#include<iostream>
using namespace std;

class Converter {
	double multiplier;
	double offset;

public:
	Converter();    // default constructor
	Converter(const double multiplier, const double offset);      // parameterized constructor
	double converter(double num);  // temperature conversion for one unit to other
};

#endif //

