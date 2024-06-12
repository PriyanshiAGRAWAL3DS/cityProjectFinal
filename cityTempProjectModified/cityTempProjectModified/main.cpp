// MAIN.CPP

#include "City.h"
#include "Capital.h"
#include "Non_capital.h"
#include "Menu.h"
#include <vector>
#include "City.h"
#include "Capital.h"
#include "Non_capital.h"
#include "Menu.h"
#include <vector>
#include <sstream>
#include<iostream>
#include<string>
#include <iomanip>
#include<fstream>
using namespace std;

// Function to parse CSV line into pair of string and vector of doubles
pair<pair<string, string>, vector<double>> parseCSVLineToPair(const string& line) {
    stringstream ss(line);
    pair<string, string> Name; // Fix: Use the pair to store city and state names
    string cityName;
    getline(ss, cityName, ',');
    Name.first = cityName; // Assign city name to the first element of the string pair
    string stateName;
    getline(ss, stateName, ',');
    Name.second = stateName; // Assign state name to the second element of the string pair

    vector<double> temperatures;  // Assign temperature data to the second pointer of the outer pair
    string temp;
    while (getline(ss, temp, ',')) {
        if (!temp.empty()) {
            temperatures.push_back(stod(temp));   // converts string to double
        }
    }
    return make_pair(Name, temperatures);
}
int main() {
    // creating a vector which consists of city name, state name and temperature data for that specific city
    vector<pair<pair<string, string>, vector<double>>> cityTemperatureData;

    // Open CSV file

    ifstream file("D:/work_dsi/Basic Practice Projects/cityProject/exampleModified.csv");

    if (!file.is_open()) {

        cerr << "Error: Unable to open file.\n";
        return 1;
    }



    // Read data from CSV file
    string line;
    while (getline(file, line)) {
        try {
            cityTemperatureData.push_back(parseCSVLineToPair(line));    // push each line of csv file(comma seperated) in cityTemperatureData
        }
        catch (const std::exception& e) {
            cerr << "Error reading CSV line: " << e.what() << endl;
            // Skip the current line and continue with the next one
            continue;
        }
    }
    file.close();

    vector<City*> cities(cityTemperatureData.size());   // create a vector of city pointers

    // populating the temperature data and city name for the Non_capital cities from the cityTemperatureData
    for (int i = 0; i < cityTemperatureData.size(); i++) {
        if (cityTemperatureData[i].second.size() == total_samples * non_capital_size) {  // populating the name and tempData for each city
            cities[i] = new Non_capital(cityTemperatureData[i].first.first);  // for non capital city only city name is populated
            cities[i]->accept(cityTemperatureData[i].second); // populating the temperatdataure 
        }

        // populating city, state name and the temperataure data for Capital cities
        else if (cityTemperatureData[i].second.size() == total_samples * capital_size) {
            cities[i] = new Capital(cityTemperatureData[i].first.first, cityTemperatureData[i].first.second);  // for Capital ciites, city name and state name both are populated
            cities[i]->accept(cityTemperatureData[i].second);   // populating the temperatureData
        }
    }
    //CityOperations co;
    // Menu interaction
    try {
        Menu m;
        m.menu_case(cities);
    }
    catch (const std::exception& e) {
        cerr << "Error in menu interaction: " << e.what() << endl;
    }

    // for memory cleanup
    for (City* city : cities) {
        delete city;   
    }
}
