#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>
#include "utilities.h"

using namespace std;

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