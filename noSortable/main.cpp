#include <iostream>
#include "Ex1.h"

#define arraySize 20

using namespace std;
//using namespace SortableSpace;

int main(){
/*
    srand((unsigned) time(NULL));
    clock_t start, end, difference;
  
    for(int i=0; i < arraySize; i++){
        a[i] = rand()%1000000+1;
    }
  */  
    
    
    int *a = (int *)malloc(sizeof(int) * arraySize);
    
    
    bubbleSort<int>(a, arraySize);

    printArray<int>(a, arraySize);
    
    /*Test bubblesort method
    cout << "Bubble sort started" << endl; 
    start = clock();
    Sortable<int> bubble = bubbleSort(s);
    end = clock();
    difference = end - start;
    cout << "Bubble sort completed on an array with " << bubble.getSize() << endl;
    cout << "Success: " << bubble.isSorted() << endl;
    cout << "Time spent to sort: " << difference/1000 << " milliseconds" << endl << endl;
    */
    
    
    


    return 0;
}