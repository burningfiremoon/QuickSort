#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "QuickSort.h"
using namespace std;

int main(){

    const int SIZE = 1000;
    int* array = readNumbersFromFile("1000_RNG.txt", SIZE);

    LomutoPartitionQuickSortWithIntrospectionAndMedianOfThree(array, 0, SIZE-1);

    for(int i = 0; i < SIZE; i++){
        cout << array[i] << " ";
    }

    return 1;
}