// Cesar Duarte
// CSCI-40 Part 3 Lab



#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// TODO: Step 1 - Define the struct TemperatureRecord
// It should contain two integer fields: day and temperature.
struct TemperatureRecord {
    int day;
    int temperature;
};

// Constants
const int MAX_DAYS = 31;

// Function Prototypes
void readTemperatures(TemperatureRecord records[], int &size); // TODO: Fix the parameters
void printTemperatures(const TemperatureRecord records[], int numRecords);
TemperatureRecord findMin(const TemperatureRecord records[], int numRecords);
TemperatureRecord findMax(const TemperatureRecord records[], int numRecords);
double findAverage(const TemperatureRecord records[], int numRecords);

int main() {
    // TODO: Step 2 - Declare an array of TemperatureRecord structs (MAX_DAYS size)
    TemperatureRecord records[MAX_DAYS];

    int size = 0;  // Actual number of records read

    // TODO: Step 3 - Call readTemperatures() to load data from file
    readTemperatures(records, size);
    if (size == 0) {
        cout << "No temperature records available." << endl;
        return 1;
    }
    // TODO: Step 4 - Print the temperatures
    cout << "Temperature" << endl;
    cout << setw(5) << "Day" << setw(10) << "Temp" << endl;
    printTemperatures(records, size);

    // TODO: Step 5 - Compute and display min, max, and average temperature
    TemperatureRecord min = findMin(records, size);
    TemperatureRecord max = findMax(records, size);
    double avgTemp = findAverage(records, size);

    cout << "The minimum temperature is: " << min.temperature << " on day " << min.day << endl;
    cout << "The maximum temperature is: " << max.temperature << "on day " << max.day << endl;
    cout << "The average temperature is: " << avgTemp << endl;
    return 0;
}


// TODO: Step 6 - Implement readTemperatures()
// Read from "temps.txt" and store data in the array
void readTemperatures(TemperatureRecord records[], int &size) {
    ifstream infile;
    infile.open("temps.txt");
    if (!infile) {
        cout << "Error! File not found." << endl;
        size = 0;
        return;
    }

    size = 0;
    while (infile >> records[size].day >> records[size].temperature) {
        size++;
        if (size >= MAX_DAYS)
            break;
    }

    infile.close();
}

// TODO: Step 7 - Implement printTemperatures()
// Print all stored temperatures in a formatted table
void printTemperatures(const TemperatureRecord records[], int numRecord) {
    for (int i = 0; i < numRecord; i++) {
        cout << setw(5) << records[i].day
            << setw(10) << records[i].temperature << endl;
}

    
}
// TODO: Step 8 - Implement findMin()
// Return the TemperatureRecord with the lowest temperature
TemperatureRecord findMin(const TemperatureRecord records[], int numRecord) {
    TemperatureRecord minRecord = records[0];
    for (int i = 1; i < numRecord; i++) {
        if (records[i].temperature < minRecord.temperature) {
            minRecord = records[i];
        }
    }
    return minRecord;
}
// TODO: Step 9 - Implement findMax()
// Return the TemperatureRecord with the highest temperature
TemperatureRecord findMax(const TemperatureRecord records[], int numRecord) {
    TemperatureRecord maxRecord = records[0];
    for (int i = 1; i < numRecord; i++) {
        if (records[i].temperature > maxRecord.temperature) {
            maxRecord = records[i];
        }
    }
    return maxRecord;
}

// TODO: Step 10 - Implement findAverage()
// Compute and return the average temperature
double findAverage(const TemperatureRecord records[], int numRecord) {
    int sum = 0;
    for (int i = 0; i < numRecord; i++) {
        sum += records[i].temperature;
    }
    return static_cast<double>(sum) / numRecord;
}

