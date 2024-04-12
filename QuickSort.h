#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void QuickSortBase(int array[], int start, int end){
    // base quicksort using end as initial pivot
    if (end <= start){return;}

    //partition
    int i = start;
    for (int j = start; j <= end-1; j++){
        if (array[j] < array[end]){
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
        }
    }
    int temp = array[i];
    array[i] = array[end];
    array[end] = temp;
    
    QuickSortBase(array, start, i - 1);
    QuickSortBase(array, i + 1, end);
}

void LomutoPartitionQuickSort(int array[], int start, int end){

    if (end <= start){return;}

    // LumotoPartition
    int i = start;
    for (int j = start; j < end; j++){
        if (array[j] < array[end]){
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
        }
    }
    int temp = array[i];
    array[i] = array[end];
    array[end] = temp;
    
    LomutoPartitionQuickSort(array, start, i - 1);
    LomutoPartitionQuickSort(array, i + 1, end);
}

void QuickSortBaseWithIntrospection(int array[], int start, int end){
    // base quicksort using end as initial pivot

    if (end <= start){return;}

    if (end - start < 7){
        int key, z;
        for (int i = start+1; i <= end; i++){
            key = array[i];
            z = i-1;

            while (z >= start && array[z] > key){
                array[z+1] = array[z];
                z--;
            }
            array[z+1] = key;
        }
        return;
    }

    //partition
    int i = start;
    for (int j = start; j <= end-1; j++){
        if (array[j] < array[end]){
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
        }
    }
    int temp = array[i];
    array[i] = array[end];
    array[end] = temp;
    
    QuickSortBaseWithIntrospection(array, start, i - 1);
    QuickSortBaseWithIntrospection(array, i + 1, end);
}

void LomutoPartitionQuickSortWithIntrospectionAndMedianOfThree(int array[], int start, int end){
    // base quicksort using end as initial pivot

    if (end <= start){return;}


    //insertion sort
    if (end - start < 7){
        int key, z;
        for (int i = start+1; i < end; i++){
            key = array[i];
            z = i-1;

            while (z >= start && array[z] > key){
                array[z+1] = array[z];
                z--;
            }
            array[z+1] = key;
        }
        return;
    }

    //Moving Median of three to the end
    // will have at most 8
    int tempArr[3] = {array[start], array[(start+end)/2], array[end]};

    int tempIndex = 2;

    if ((tempArr[0] >= tempArr[1] && tempArr[0] <= tempArr[2]) || (tempArr[0] >= tempArr[2] && tempArr[0] <= tempArr[1]))
        int tempIndex = 0;
    else if ((tempArr[1] >= tempArr[0] && tempArr[1] <= tempArr[2]) || (tempArr[1] >= tempArr[2] && tempArr[1] <= tempArr[0]))
        int tempIndex = 1;

    
    array[end] = tempArr[tempIndex];
    // moves higest value to one less and lower value to start, but bad case with < 3 values
    // array[end-1] = *max_element(array, array + 3);
    // array[start] = *min_element(array, array + 3);

    int i = start ;
    for (int j = start ; j < end; j++){
        if (array[j] < array[end]){
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
        }
    }
    int temp = array[i];
    array[i] = array[end];
    array[end] = temp;

    LomutoPartitionQuickSortWithIntrospectionAndMedianOfThree(array, start, i - 1);
    LomutoPartitionQuickSortWithIntrospectionAndMedianOfThree(array, i + 1, end);
}

int* readNumbersFromFile(const char* filename, int size){
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening the file." << std::endl;
        return nullptr;
    }

    int* numbers = new int[size];
    for (int i = 0; i < size; ++i) {
        if (!(inputFile >> numbers[i])) {
            std::cerr << "Error reading from file." << std::endl;
            delete[] numbers; // Free memory in case of error
            return nullptr;
        }
    }

    inputFile.close();
    return numbers;
}
