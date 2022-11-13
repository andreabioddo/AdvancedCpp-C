#include <iostream>
#include "Ex1.h"

using namespace std;

//namespace SortableSpace{

    
    template <class T>
    void swap(int* a,int* b){
       int c = *a;
        *a = *b;
        *b = c; 

    }

    template <class T>
    void bubbleSort(int* arr, int size){
        for(int i = 0; i < size; ++i)
            for(int j = 0; j < size-(i+1); ++j)
                if(arr[j] > arr[j+1])
                    swap(arr[j], arr[j+1]);

    }

    template <class T>
    void printArray(int* arr, int size){
        for(int i=0; i < size; i++){
            cout << arr[i] << ", " << endl;
        }
        cout << endl;
    }
//}