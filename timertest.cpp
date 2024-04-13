#include <iostream>
#include <chrono> // For timing
#include <fstream>
#include <random>
#include <algorithm>
#include "QuickSort.h"
using namespace std;

// Function for testing sorting speed
void testSortingSpeed(int numNumbers, const char* filename) {

    // Timing variables
    chrono::duration<double> totalTimeQuickSortBase(0), totalTimeLomutoPartitionQuickSort(0), totalTimeQuickSortBaseWithIntrospection(0), totalTimeLomutoPartitionQuickSortWithIntrospectionAndMedianOfThree(0);

    // Number of iterations for timing
    const int numIterations = 1000;

    for (int i = 0; i < numIterations; ++i) {
        // Generate random numbers and write to file
        if (!generateRandomNumbersFile(filename, numNumbers)) {
            cerr << "Failed to generate random numbers file." << endl;
            return;
        }

        // Read numbers from file
        int* numbers = readNumbersFromFile(filename, numNumbers);
        if (numbers == nullptr) {
            cerr << "Failed to read numbers from file." << endl;
            return;
        }

        // Copy numbers to not take multiple inputs of the same file
        int* numbersCopy1 = new int[numNumbers];
        int* numbersCopy2 = new int[numNumbers];
        int* numbersCopy3 = new int[numNumbers];
        int* numbersCopy4 = new int[numNumbers];

        copy(numbers, numbers + numNumbers, numbersCopy1);
        copy(numbers, numbers + numNumbers, numbersCopy2);
        copy(numbers, numbers + numNumbers, numbersCopy3);
        copy(numbers, numbers + numNumbers, numbersCopy4);

        // Timing QuickSortBase
        auto startTime = chrono::high_resolution_clock::now();
        QuickSortBase(numbersCopy1, 0, numNumbers - 1);
        auto endTime = chrono::high_resolution_clock::now();
        totalTimeQuickSortBase += endTime - startTime;

        // Timing LomutoPartitionQuickSort
        startTime = chrono::high_resolution_clock::now();
        LomutoPartitionQuickSort(numbersCopy2, 0, numNumbers - 1);
        endTime = chrono::high_resolution_clock::now();
        totalTimeLomutoPartitionQuickSort += endTime - startTime;

        // Timing QuickSortBaseWithIntrospection
        startTime = chrono::high_resolution_clock::now();
        QuickSortBaseWithIntrospection(numbersCopy3, 0, numNumbers - 1);
        endTime = chrono::high_resolution_clock::now();
        totalTimeQuickSortBaseWithIntrospection += endTime - startTime;

        // Timing LomutoPartitionQuickSortWithIntrospectionAndMedianOfThree
        startTime = chrono::high_resolution_clock::now();
        LomutoPartitionQuickSortWithIntrospectionAndMedianOfThree(numbersCopy4, 0, numNumbers - 1);
        endTime = chrono::high_resolution_clock::now();
        totalTimeLomutoPartitionQuickSortWithIntrospectionAndMedianOfThree += endTime - startTime;


        // Free dynamically allocated memory
        delete[] numbersCopy1;
        delete[] numbersCopy2;
        delete[] numbersCopy3;
        delete[] numbersCopy4;
        delete[] numbers;

        if (!deleteFile(filename)) {
            cerr << "Failed to delete file." << endl;
        }
        cout << i << endl;

    }

    // Calculate average time
    double averageTimeQuickSortBase = totalTimeQuickSortBase.count() / numIterations;
    double averageTimeLomutoPartitionQuickSort = totalTimeLomutoPartitionQuickSort.count() / numIterations;
    double averageTimeQuickSortBaseWithIntrospection = totalTimeQuickSortBaseWithIntrospection.count() / numIterations;
    double averageTimeLomutoPartitionQuickSortWithIntrospectionAndMedianOfThree = totalTimeLomutoPartitionQuickSortWithIntrospectionAndMedianOfThree.count() / numIterations;

    // Write results to file
    ofstream outFile("test.txt");
    if (outFile.is_open()) {
        outFile << "Average Time for QuickSortBase: " << averageTimeQuickSortBase << " seconds" << endl;
        outFile << "Average Time for LomutoPartitionQuickSort: " << averageTimeLomutoPartitionQuickSort << " seconds" << endl;
        outFile << "Average Time for QuickSortBaseWithIntrospection: " << averageTimeQuickSortBaseWithIntrospection << " seconds" << endl;
        outFile << "Average Time for LomutoPartitionQuickSortWithIntrospectionAndMedianOfThree: " << averageTimeLomutoPartitionQuickSortWithIntrospectionAndMedianOfThree << " seconds" << endl;
        outFile.close();
        cout << "Results written to test.txt" << endl;
    } else {
        cerr << "Error opening file for writing." << endl;
    }




}

int main() {
    const char* filename = "random_numbers.txt";
    int numNumbers = 10000; // Number of random numbers to generate
    testSortingSpeed(numNumbers, filename);

    return 0;
}