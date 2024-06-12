#ifndef MENU_CPP

#define MENU_CPP



#include "Menu.h"
#include "City.h"
#include "Capital.h"
#include "Non_capital.h"
#include "Converter.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
#include <typeinfo>
#include <stdexcept>
#include <limits> // For numeric_limits

using namespace std;

// global const variables  (Multiplier and offset values for temperature conversion in F or K unit
const double Koffset = 273.15;
const double Kmultiplier = 1;
const double Fmultiplier = (9 / 5);
const double Foffset = 32;


// Global functions
bool min_val(City* c1, City* c2)
{
    return c1->get_min() < c2->get_min();
}

bool max_val(City* c1, City* c2)
{
    return c1->get_max() > c2->get_max();
}

bool avg_val_ascending(City* c1, City* c2)
{
    return c1->get_avg() < c2->get_avg();
}

Menu::Menu() { }

void Menu::display_choices(vector<City*> cities) {
    int choice2;
    cout << "1. Display all cities data\n";
    cout << "2. Display only Capital ciites\n";
    cout << "3. Display only non-capital cities data\n";
    cout << "Enter your choice(1/2/3) : ";
    cin >> choice2;
    try {
        if (cin.fail()) {
            cout << "!!!------Invalid input! Please enter a valid integer------!!!\n\n";
            return;
        }

        // Input validation for valid choice range
        if (choice2 < 1 || choice2 > 3) {
            cout << "!!!------Invalid choice! Please enter a number between 1 and 3------!!!\n\n";
            return;
        }

        // Process user's choice
        switch (choice2) {
        case 1:
        {
            display_all_cities(cities);
            break;
        }
        case 2:
        {
            display_capital(cities);
            break;
        }
        case 3:
        {
            display_non_capital(cities);
            break;
        }
        default:
            cout << "!!!--------Invalid input--------!!!\n";
            break;
        }
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
}

void Menu::display_capital(vector<City*> cities) {
    cout << "\nTemperature data for all Capital cities: \n";
    cout << setw(5) << left << "No." << setw(25) << left << "City name" << setw(15) << right << "Min temp" << setw(20) << right << "       Max temp" << setw(20) << right << "      Avg temp" << endl;
    int count = 1;
    bool flag = false;
    for (int i = 0; i < cities.size(); i++) {
        if (cities[i]->get_size() == capital_size) {
            if (count <= 9) {
                cout << "0" << count << ". " << setw(3) << right << "  ";
            }
            else {
                cout << setw(2) << left << count << ". " << setw(3) << right << "  ";
            }
            cities[i]->display();
            flag = true;
            count++;
        }
    }
    if (flag == false) {
        cout << "No capital city data available!!!\n";
    }
}

void Menu::display_non_capital(vector<City*> cities) {
    cout << "\nTemperature data for all non-Capital cities: \n";
    cout << setw(5) << left << "No." << setw(25) << left << "City name" << setw(15) << right << "Min temp" << setw(20) << right << "       Max temp" << setw(20) << right << "      Avg temp" << endl;
    int count = 1;
    bool flag = false;
    for (int i = 0; i < cities.size(); i++) {
        if (cities[i]->get_size() == non_capital_size) {
            if (i < 9) {
                cout << "0" << i + 1 << ". " << setw(3) << right << "  ";
            }
            else {
                cout << setw(2) << left << i + 1 << ". " << setw(3) << right << "  ";
            }
            cities[i]->display();
            flag = true;
            count++;
        }
    }
    if (flag == false) {
        cout << "No capital city data available!!!\n";
    }
}

void Menu::display_all_cities(vector<City*> cities)
{
    cout << setw(5) << left << "No." << setw(25) << left << "City name" << setw(15) << right << "Min temp" << setw(20) << right << "       Max temp" << setw(20) << right << "      Avg temp" << endl;

    for (int i = 0; i < cities.size(); i++) {
        if (i < 9) {
            cout << "0" << i + 1 << ". " << setw(3) << right << "  ";
        }
        else {
            cout << setw(2) << left << i + 1 << ". " << setw(3) << right << "  ";
        }
        cities[i]->display();
    }
}

void Menu::sort_cities(vector<City*> cities, int sort_choice)
{
    if (sort_choice == 1) {
        cout << "\nSorting on the basis of max temperature\n";
        cout << setw(5) << left << "No." << setw(25) << left << "City name" << setw(15) << right << "Max temp" << endl;
        sort(cities.begin(), cities.end(), max_val);

        for (int i = 0; i < cities.size(); i++)
        {
            if (i < 9) {

                cout << "0" << i + 1 << ". " << setw(3) << right << "  ";

            }

            else {

                cout << setw(2) << left << i + 1 << ". " << setw(3) << right << "  ";

            }
            cout << setw(30) << left << cities[i]->get_name() << setw(5) << right << cities[i]->get_max() << " C\n";
        }

    }

    if (sort_choice == 2) {

        cout << "\nSorting on the basis of min temperature\n";
        cout << setw(5) << left << "No." << setw(25) << left << "City name" << setw(15) << right << "       Min temp" << endl;
        sort(cities.begin(), cities.end(), min_val);
        for (int i = 0; i < cities.size(); i++)
        {
            if (i < 9) {

                cout << "0" << i + 1 << ". " << setw(3) << right << "  ";

            }

            else {

                cout << setw(2) << left << i + 1 << ". " << setw(3) << right << "  ";

            }
            cout << setw(30) << left << cities[i]->get_name() << setw(5) << right << cities[i]->get_min() << " C\n";
        }
    }
    if (sort_choice == 3) {
        cout << "Sorting on the basis of avg temperature\n";
        cout << setw(5) << left << "No." << setw(25) << left << "City name" << setw(15) << right << "       Avg temp" << endl;
        sort(cities.begin(), cities.end(), avg_val_ascending);
        for (int i = 0; i < cities.size(); i++)
        {
            if (i < 9) {
                cout << "0" << i + 1 << ". " << setw(3) << right << "  ";
            }
            else {
                cout << setw(2) << left << i + 1 << ". " << setw(3) << right << "  ";
            }
            cout << setw(30) << left << cities[i]->get_name() << setw(5) << right << cities[i]->get_avg() << " C\n";
        }
    }

}

void Menu::search_city(vector<City*> cities, string& city_name)

{
    int res = -1;

    try {
        // Check if the entered city_name is empty
        if (city_name.empty()) {
            throw invalid_argument("Invalid city name! Please enter a non-empty city name.");
        }

        for (int i = 0; i < city_name.length(); i++) {
            city_name[i] = tolower(city_name[i]);
        }

        for (int i = 0; i < cities.size(); i++) {
            if (cities[i]->get_name() == city_name) {
                res = i;
                break;
            }
        }

        if (res == -1) {
            cout << "!!!---City not found---!!!\n";
        }
        else {
            cout << setw(22) << left << "City name" << setw(15) << right << "Min temp" << setw(20) << right << "       Max temp" << setw(22) << right << "      Avg temp" << endl;
            cities[res]->display();
        }
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
}

void Menu::search_state(vector<City*> cities, string state_name)

{
    int res = -1;

    try {
        // Check if the entered city_name is empty
        if (state_name.empty()) {
            throw invalid_argument("Invalid city name! Please enter a non-empty city name.");
        }

        for (int i = 0; i < state_name.length(); i++) {
            state_name[i] = tolower(state_name[i]);
        }

        for (int i = 0; i < cities.size(); i++) {
            if (cities[i]->get_stateName() == state_name) {
                res = i;
                break;
            }
        }

        if (res == -1) {
            cout << "!!!---State not found---!!!\n";
        }
        else {
            cout << setw(22) << left << "city name" << setw(15) << right << "Min temp" << setw(20) << right << "       Max temp" << setw(22) << right << "      Avg temp" << endl;
            cities[res]->display();
        }
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
}
void Menu::delete_city(vector<City*> cities, string city_name)

{
    cout << setw(5) << left << "No." << setw(25) << left << "City name" << setw(15) << right << "Min temp" << setw(20) << right << "       Max temp" << setw(20) << right << "      Avg temp" << endl;
    int count = 0;
    bool flag = false;
    try {
        // Check if the entered city_name is empty
        if (city_name.empty()) {
            throw invalid_argument("Invalid city name! Please enter a non-empty city name.");
        }

        for (int i = 0; i < cities.size(); i++) {
            if (cities[i]->get_name() == city_name) {
                flag = true;
                count = i;
                continue;
            }
            else {
                if (count < 9) {
                    cout << "0" << count + 1 << ". " << setw(3) << right << "  ";
                }
                else {
                    cout << setw(2) << left << count + 1 << ". " << setw(3) << right << "  ";
                }
                cities[i]->display();
                count++;
            }
        }

    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
}

void Menu::convert(vector<City*> cities, char unit) {
    cout << setw(5) << left << "No." << setw(25) << left << "City name" << setw(15) << right << "Min temp" << setw(20) << right << "       Max temp" << setw(20) << right << "      Avg temp" << endl;
    switch (unit) {

    case 'K':

    {

        for (int i = 0; i < cities.size(); i++) {
            if (i < 9) {
                cout << "0" << i + 1 << ". " << setw(3) << right << "  ";
            }
            else {
                cout << setw(2) << left << i + 1 << ". " << setw(3) << right << "  ";
            }
            Converter c(Kmultiplier, Koffset);
            double mini = c.converter(cities[i]->get_min());
            double maxi = c.converter(cities[i]->get_max());
            double avg = c.converter(cities[i]->get_avg());
            cout << setw(30) << left << cities[i]->get_name() << mini << "K" << setw(20) << right << maxi << "K" << setw(18) << right << avg << "K" << endl;
        }
        break;
    }

    case 'F':
    {
        for (int i = 0; i < cities.size(); i++) {
            if (i < 9) {
                cout << "0" << i + 1 << ". " << setw(3) << right << "  ";
            }
            else {
                cout << setw(2) << left << i + 1 << ". " << setw(3) << right << "  ";
            }
            Converter c2(Fmultiplier, Foffset);
            double mini = c2.converter(cities[i]->get_min());
            double maxi = c2.converter(cities[i]->get_max());
            double avg = c2.converter(cities[i]->get_avg());
            cout << setw(30) << left << cities[i]->get_name() << mini << "F " << setw(20) << right << maxi << "F" << setw(20) << right << avg << "F" << endl;
        }
        break;
    }
    default:
    {
        cout << "Invalid Input!!!\n";
        break;
    }
    }
}

void Menu::display_menu(vector<City*> cities)

{

    cout << "!!!--------------------MENU------------------!!!\n";
    cout << endl;
    cout << "1. Display temperature of all cities\n";
    cout << "2. Sort temperature \n";
    cout << "3. Search temperature values for a city\n";
    cout << "4. Delete record of a particular city and display\n";
    cout << "5. Convert Temperature unit from C to other unit\n";
    cout << "6. Exit\n";

}

void Menu::search_choices(vector<City*> cities) {
    int choice2;
    cout << "1. Search by city name\n";
    cout << "2. Search by state name(Only for Capital cities)\n";
    cout << "Enter your choice : ";
    cin >> choice2;
    try {
        if (cin.fail()) {
            cout << "!!!------Invalid input! Please enter a valid integer------!!!\n\n";
            return;
        }

        // Input validation for valid choice range
        if (choice2 < 1 || choice2 > 2) {
            cout << "!!!------Invalid choice! Please enter a number between 1 and 2------!!!\n\n";
            return;
        }

        // Process user's choice
        switch (choice2) {
        case 1:
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character
            string city_name;
            cout << "Enter city name: ";
            getline(cin, city_name);
            search_city(cities, city_name);
            break;
        }
        case 2:
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character
            string state_name = "";
            cout << "Enter state name: ";
            getline(cin, state_name);
            search_state(cities, state_name);
            break;
        }
        default:
            cout << "!!!--------Invalid input--------!!!\n";
            break;
        }
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

}

void Menu::convert_choices(vector<City*> cities) {
    int choice2;
    cout << "1. convert from C to K\n";
    cout << "2. convert from C to F\n";
    cout << "Enter your choice : ";
    cin >> choice2;
    try {
        // Input validation for integer input
        if (cin.fail()) {
            throw runtime_error("Invalid input! Please enter a valid integer.");
        }

        // Input validation for valid choice range
        if (choice2 < 1 || choice2 > 6) {
            throw out_of_range("Invalid choice! Please enter a number between 1 and 6.");
        }

        // Process user's choice
        switch (choice2) {
        case 1:
        {
            convert(cities, 'K');
            break;
        }
        case 2:
        {
            convert(cities, 'F');
            break;
        }
        default:
            cout << "!!!--------Invalid input--------!!!\n";
            break;
        }
    }catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
}

void Menu::menu_case(vector<City*> cities)
{
    bool check = 1;
    //co.set_cities(cities);
    do
    {
        this->display_menu(cities);
        //CityOperations co(cities);
        int choice2;
        cout << "Enter choice from the MENU: ";
        cin >> choice2;
        try {
            // Input validation for integer input
            if (cin.fail()) {
                throw runtime_error("Invalid input! Please enter a valid integer.");
            }

            // Input validation for valid choice range
            if (choice2 < 1 || choice2 > 6) {
                throw out_of_range("Invalid choice! Please enter a number between 1 and 6.");
            }
            cout << endl;
            switch (choice2)
            {
            case 1:
            {
                display_choices(cities);
                break;
            }

            case 2:
            {
                sort_choices(cities);
                break;
            }

            case 3:
            {
                search_choices(cities);
                break;
            }

            case 4:
            {
                string city_name1 = "";
                cout << "Enter the city name want to skip from the display : ";
                cin >> city_name1;
                delete_city(cities, city_name1);
                break;
            }
            case 5:
            {
                convert_choices(cities);
                break;
            }
            case 6:
            {
                cout << "!!!-------SUCCESSFULLY EXITED-------!!!\n";
                check = 0;
                break;
            }
            }

            cout << endl;
        }
        catch (const exception& e) {
            cout << "Exception: " << e.what() << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    } while (check);

}

void Menu::sort_choices(vector<City*> cities)
{
    int choice1;
    cout << "1. sort by maximum temperature.\n";
    cout << "2. sort by minimum temperature.\n";
    cout << "3. sort by average temperature.\n";
    cout << "Enter your choice : ";
    cin >> choice1;
    try {
        // Input validation for integer input
        if (cin.fail()) {
            throw runtime_error("Invalid input! Please enter a valid integer.");
        }

        // Input validation for valid choice range
        if (choice1 < 1 || choice1 > 3) {
            throw out_of_range("Invalid choice! Please enter a number between 1 and 3.");
        }

        // Process user's choice
        switch (choice1)
        {
        case 1:
            sort_cities(cities, choice1);
            break;

        case 2:
            sort_cities(cities, choice1);
            break;
        case 3:
        {
            sort_cities(cities, choice1);
            break;
        }
        default:
            cout << "!!!--------Invalid input--------!!!\n";
            break;
        }
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
}
#endif
