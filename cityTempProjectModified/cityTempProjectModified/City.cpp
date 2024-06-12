#ifndef CITY_CPP

#define CITY_CPP



#include "city.h"

#include <iostream>

#include <algorithm>

#include <cmath>

#include <string>

#include <iomanip>



using namespace std;



City::City() {   // default constructor

    name = "";

}



City::City(string city_name)        // parameterized constructor, taking city name as argument

{

    this->name = city_name;

}



string City::get_name() {

    return name;

}

int City::get_size() {

    return size;

}



void City::accept(vector<double> temp) {

    int count = 0;

    for (int i = 0; i < size; i++) {     // populating the temperature data for each city in the 2D array pTemp for capital city size =4 and for on_capital size =1

        for (int j = 0; j < total_samples; j++) {      // total_samples =24

            pTemp[i][j] = temp[count++];

        }

    }

}



double City::get_max() {  

    double maxi = -273.15;   // minimum temperature taken as tempertaure less than this is not found anywhere

    for (int i = 0; i < size; i++) {  // iterating pTemp

        for (int j = 0; j < total_samples; j++) {

            maxi = (maxi > pTemp[i][j]) ? maxi : pTemp[i][j];   // updating maxi when greater value than maxi is found

        }

    }

    return maxi;

}



double City::get_min() {

    double mini = INT_MAX;

    for (int i = 0; i < size; i++) {   // iterating pTemp

        for (int j = 0; j < total_samples; j++) {

            mini = (mini < pTemp[i][j]) ? mini : pTemp[i][j];  // updating mini when lesser value than mini is found

        }

    }

    return mini;

}



double City::get_avg() {

    double sum = 0;

    for (int i = 0; i < size; i++) {   // iterating pTemp

        for (int j = 0; j < total_samples; j++) {

            sum += pTemp[i][j];   // updating sum 

        }

    }

    int elements = size * total_samples;   // find total no of elements

    double result = sum / elements;
    // Adjust precision using rounding
    double scale = pow(10, 2);
    result = round(result * scale) / scale;
    return result; // average = total sum/ total elements

}



void City::display() {
    // function for displaying max, min and avg temperature values for each city along with the city name 
    switch (size) {
    case 1:
        cout << setw(10) << left << name << "   ";
        cout << setw(20) << right << get_min() << "C" << setw(18) << left << "    " << get_max() << "C" << setw(16) << right << "    " << get_avg() << "C" << endl;
        break;

    case 4:
        cout << name << ", " << setw(15) << left << get_stateName();
        cout << setw(10) << left << setw(10) << right << get_min() << "C" << setw(18) << left << "    " << get_max() << "C" << setw(16) << right << "    " << get_avg() << "C" << endl;
        break;
    default:
        cout << "Invalid size!!!\n";
        break;

    }
}
#endif // !CITY_CPP
