#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "City.h"
#include "Non_capital.h"
#include "Capital.h"
#include <vector>
using namespace std;

class Menu
{
    //CityOperations co;
public:
    Menu();
    void display_menu(vector<City*> cities);
    void display_choices(vector<City*> cities);
    void menu_case(vector<City*> cities);
    void sort_choices(vector<City*> cities);  // choices for sort choice menu option
    void search_choices(vector<City*> cities);    // choices for search choice menu option
    void convert_choices(vector<City*> cities);   // choices for convert choice menu option
    void display_capital(vector<City*> cities);   // display only Capital cities
    void display_non_capital(vector<City*> cities); // dipslay only Non_capital cities
    void display_all_cities(vector<City*> cities);
    void convert(vector<City*> cities, char unit);   // function for converting temperature values according to the user choice
    void sort_cities(vector<City*> cities, int sort_choice);   // function for sorting ciites according to temperature values
    void search_city(vector<City*> cities, string& city_name);    // function for search and display tempertaure data for the city name provided by the user
    void search_state(vector<City*> cities, string state_name);    // function for search and display tempertaure data for the state name provided by the user
    void delete_city(vector<City*> cities, string city_name);   // function which skips the city name according to the user input
};

bool min_val(City* c1, City* c2);   // comparators for max, min and avg values
bool max_val(City* c1, City* c2);
bool avg_val_ascending(City* c1, City* c2);


#endif
