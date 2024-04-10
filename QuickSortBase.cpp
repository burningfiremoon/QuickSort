#include <stdio.h>
#include <iostream>
using namespace std;

int Partition(int array[], int start, int end);
void QuickSortBase(int array[], int start, int end);
int LumotoPartition(int array[], int start, int end);
void LomutoPartitionQuickSort(int array[], int start, int end);

int main(){


    int array[10] = {7,4,9,2,5,6,1,8,3,0};

    int * Aptr = array;

    LomutoPartitionQuickSort(array, 0, 9);


    for(int i : array){
        cout << i << " ";
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
