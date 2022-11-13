#include <iostream>
using namespace std;

#include "Sortable.h"

#define arraySize 10


namespace SortableSpace{

    /**
     * @brief return the max number into the array
     * 
     */
    template <class T>
    T Sortable<T>::getMax(){
        T max=array[0];
        for(int i=0; i<size;i++)
            if(array[i]>max)
                max=array[i];
        return max;
    }

    /**
     * @brief Construct a new Sortable<T>:: Sortable object. It set the size and the array
     * 
     * @param arr array
     * @param s array's size
     */
    template <class T>
    Sortable<T>::Sortable(T arr[], int s){
        array = arr;
        size = s;
    }

    /**
     * @brief return the array saved
     * 
     */
    template <class T>
    T* Sortable<T>::getArray(){
        return array;
    }

    /**
     * @brief return the array's size
     * 
     */
    template <class T>
    int Sortable<T>::getSize(){
        return size;
    }

    /**
     * @brief swap between two T elements 
     * 
     * @param a element a
     * @param b element b
     */
    template <class T>
    void Sortable<T>::swap(T* a, T* b){
        T c = *a;
        *a = *b;
        *b = c; 
    }

    /**
     * @brief return a bollean value that check if the Sortable obj is sorted
     * 
     */
    template <class T>
    bool Sortable<T>::isSorted(){
        for(int i=0; i<size-1;i++)
            if(array[i]>array[i+1])
                return false;
        return true;
    }

    /**
     * @brief print the array of the obj a
     * 
     * @param a Sortable obj
     */
    template <class T>
    void Sortable<T>::printSortable(){
        for(int i=0; i < size; i++){
            cout << " " << array[i];
        }
        cout << endl;
    }

    /**
     * @brief Using bubble sort, this method sort the array saved
     * 
     * @param arr the object that we want to order
     */
    template <class T>
    void Sortable<T>::bubbleSort(){
        for(int i = 0; i < size; ++i)
            for(int j = 0; j < size-(i+1); ++j)
                if(array[j] > array[j+1])
                    swap(&array[j], &array[j+1]);
    }

    template class Sortable<long>;
    template class Sortable<short>;
    template class Sortable<double>;
    template class Sortable<int>;
}