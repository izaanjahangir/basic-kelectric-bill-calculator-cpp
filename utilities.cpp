#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>
#include "utilities.h"

using namespace std;

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