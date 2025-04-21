/*File Name : Chap5Exercise18.cpp
 Developer/Programmer: Bryan Hurley
 Date: April 2025
 Requirements:
This program reads population data from a file and displays a bar chart.
                 Each '*' represents 1,000 people.
*/

#include <iostream>
#include <fstream>
using namespace std;

// Gets data from People.txt and fills the array
bool loadPopulationData(int pop[], int size) {
    ifstream file("People.txt");
    if (!file) {
        cout << "Error: Could not open People.txt\n";
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (!(file >> pop[i])) {
            cout << "Error: Not enough data in file.\n";
            return false;
        }
    }
    return true;
}

// Prints population bars
void printBars(const int years[], const int pop[], int size) {
    cout << "POPULATION BAR CHART\n";
    for (int i = 0; i < size; i++) {
        cout << years[i] << " | ";
        for (int j = 0; j < pop[i] / 1000; j++)
            cout << "*";
        cout << endl;
    }
}

int main() {
    const int years[] = { 1900, 1920, 1940, 1960, 1980, 2000 };
    const int SIZE = 6;
    int population[SIZE];

    if (loadPopulationData(population, SIZE))
        printBars(years, population, SIZE);

    return 0;
}