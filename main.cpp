#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std;

// Function declarations
vector<double> readConfig();
int getUnitPrice(int, vector<double> charges);

int main()
{
    vector<double> charges = readConfig();
    vector<double> unitsVector;

    int units, unit;
    double price = 0;

    cout << "Enter total number of unit consumed (Must be integer): ";
    cin >> units;

    unit = units;
    int iterations = ceil(units / 100.0);

    for (int i = 1; i <= iterations; i++)
    {
        if (i == iterations)
        {
            unitsVector.push_back(unit);
            break;
        }

        unit = unit - 100;
        unitsVector.push_back(100);
    }

    for (int i = 0; i <= unitsVector.size(); i++)
    {
        int index = i;

        if ((charges.size() - 1) < i)
        {
            index = charges.size() - 1;
        }

        price = price + (unitsVector[i] * charges[index]);
    }

    cout << "Total Bill is: " << price << endl;
}

vector<double> readConfig()
{
    ifstream file("config.txt");

    if (!file.is_open())
    {
        cout << "Configuration file not found" << endl;
        exit(EXIT_FAILURE);
    }

    string input;
    vector<double> charges;

    while (getline(file, input))
    {
        int index = input.find("= ");
        charges.push_back(stod(input.substr(index + 2)));
    }

    return charges;
}

int getUnitPrice(int index, vector<double> charges)
{
    return charges[index];
}