#ifndef CONVERTER_CPP
#define CONVERTER_CPP

#include "Menu.h"
#include "City.h"
#include "Capital.h"
#include "Non_capital.h"
#include "Converter.h"
#include<iostream>
#include<iomanip>
#include <cmath>
using namespace std;


Converter::Converter() {    // default constructor
	multiplier = 0;
	offset = 0;
}
Converter::Converter(const double multiplier, const double offset) {  // parameterized constructor
	this->multiplier = multiplier;
	this->offset = offset;
}
double Converter::converter(double num) {   // temperature conversion for one unit to other 
	double result = num * multiplier + offset;
	//return num * (double)multiplier + (double)offset;
	//return setprecision(2) << result;
	// Adjust precision using rounding
	double scale = pow(10, 2);
	result = std::round(result * scale) / scale;
	return result;

}

#endif //

