#ifndef CITY_H
#define CITY_H

#include <iostream>
#include<vector>
#include<string>

using namespace std;

#define total_samples 24
#define capital_size 4
#define non_capital_size 1



class City {

protected:

    string name;  // city name variable

    double max;   // max temperature value

    double min;    // min temperature value

    double avg;   // avg temperature value

    double** pTemp;  // 2D array consisting of temperature data of the object

    int size;   // for capital city =4, for non_capital city=1



public:

    City();  // default constructor

    City(string name);    // parameterized constructor

    string get_name();   // function for providing city name for both capital and Non_capital cities

    void accept(vector<double> temp);    // populate temperature data for each city object

    void display();   // function for displaying max, min and avg temperature values for each city along with the city name 

    int get_size();   // returns size of city object 

    double get_max();   // function which returns max temperature value for each city object

    double get_min();    // function which returns min temperature value for each city object

    double get_avg();    // function which returns avg temperature value for each city object

    virtual string get_stateName() { return ""; };   // function for providing state name only for the capital cities will be ovrridden by the function in the Capital city class
};

#endif // !CITY_H
