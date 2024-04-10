#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;


// move these to a .h file later
void QuickSortBase(int array[], int start, int end);
void QuickSortBaseWithIntrospection(int array[], int start, int end);
void LomutoPartitionQuickSort(int array[], int start, int end);
void LomutoPartitionQuickSortWithIntrospectionAndMedianOfThree(int array[], int start, int end);
int Partition(int array[], int start, int end);
int LumotoPartition(int array[], int start, int end);
int LumotoPartitionWithMedianOfThree(int array[], int start, int end);
void InsertionSort(int array[], int start, int end);
int* readNumbersFromFile(const char* filename, int size);

int main(){

    const int SIZE = 1000;
    int* array = readNumbersFromFile("1000_RNG.txt", SIZE);

    LomutoPartitionQuickSortWithIntrospectionAndMedianOfThree(array, 0, SIZE-1);


    for(int i = 0; i < SIZE; i++){
        cout << array[i] << " ";
    }

    return 1;
}

void QuickSortBase(int array[], int start, int end){
    // base quicksort using end as initial pivot

    if (end <= start){return;}

    int pivot = Partition(array, start, end);
    
    QuickSortBase(array, start, pivot - 1);
    QuickSortBase(array, pivot + 1, end);
}

void LomutoPartitionQuickSort(int array[], int start, int end){
    // base quicksort using end as initial pivot

    if (end <= start){return;}

    int pivot = LumotoPartition(array, start, end);
    
    QuickSortBase(array, start, pivot - 1);
    QuickSortBase(array, pivot + 1, end);
}

void QuickSortBaseWithIntrospection(int array[], int start, int end){
    // base quicksort using end as initial pivot

    if (end <= start){return;}

    if (end - start < 5){
        InsertionSort(array, start, end);
        return;
    }

    int pivot = Partition(array, start, end);
    
    QuickSortBase(array, start, pivot - 1);
    QuickSortBase(array, pivot + 1, end);
}

void LomutoPartitionQuickSortWithIntrospectionAndMedianOfThree(int array[], int start, int end){
    // base quicksort using end as initial pivot

    if (end <= start){return;}

    if (end - start < 7){
        InsertionSort(array, start, end);
        return;
    }

    int pivot = LumotoPartitionWithMedianOfThree(array, start, end);
    
    QuickSortBase(array, start, pivot - 1);
    QuickSortBase(array, pivot + 1, end);
}

int Partition(int array[], int start, int end){
    int i = start - 1;
    for (int j = start; j <= end-1; j++){
        if (array[j] < array[end]){
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    i++;
    int temp = array[i];
    array[i] = array[end];
    array[end] = temp;

    return i;

}

int LumotoPartition(int array[], int start, int end){

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
    return i;
}

int medianIndexOfThreeValues(int array[]){

    if ((array[0] >= array[1] && array[0] <= array[2]) || (array[0] >= array[2] && array[0] <= array[1]))
        return 0;
    else if ((array[1] >= array[0] && array[1] <= array[2]) || (array[1] >= array[2] && array[1] <= array[0]))
        return 1;
    else
        return 2;

}

int LumotoPartitionWithMedianOfThree(int array[], int start, int end){

    //Moving Median of three to the end
    // will have at least 8 values
    int tempArr[3] = {array[start], array[(start+end)/2], array[end]};

    array[end] = tempArr[medianIndexOfThreeValues(tempArr)];
    array[end-1] = *max_element(array, array + 3);
    array[start] = *min_element(array, array + 3);

    int i = start + 1;
    for (int j = start + 1; j < end -1; j++){
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
    return i;
}

void InsertionSort(int array[], int start, int end){

    int key, j;
    for (int i = start+1; i < end; i++){
        key = array[i];
        j = i-1;

        while (j >= start && array[j] > key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
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
