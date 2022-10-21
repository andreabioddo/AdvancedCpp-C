/**
 * @file Sortable.cpp
 * @author Andrea Bioddo (anbioddo@edu.aau.at)
 * @brief 
 * @version 0.1
 * @date 2022-10-20
 * 
 */

#include <iostream>

using namespace std;

#define arraySize 100000

class Sortable{
    private:
        int* array;
        int size;
        void swap(int* a, int* b);
    
    public:
        Sortable(int arr[], int s);
        int* getCopyArr();
        int* getArray();
        int getSize();
        int getMax();
        bool isSorted();
        friend Sortable bubbleSort(Sortable a);
        friend Sortable bucketSort(Sortable a);
        friend Sortable countSort(Sortable a);
        friend void printSortable(Sortable s);
};

/**
 * @brief return a copy of the array
 * 
 */
int* Sortable::getCopyArr(){
    int* res = (int*)malloc(sizeof(int)*size);
    for(int i=0; i<size;i++)
        res[i]=array[i];
    return res;
}

/**
 * @brief return the max number into the array
 * 
 */
int Sortable::getMax(){
    int max=array[0];
    for(int i=0; i<size;i++)
        if(array[i]>max)
            max=array[i];
    return max;
}

/**
 * @brief Construct a new Sortable:: Sortable object. It set the size and the array
 * 
 * @param arr array
 * @param s array's size
 */
Sortable::Sortable(int arr[], int s){
    array = arr;
    size = s;
}

/**
 * @brief return the array saved
 * 
 */
int* Sortable::getArray(){
    return array;
}

/**
 * @brief return the array's size
 * 
 */
int Sortable::getSize(){
    return size;
}

/**
 * @brief swap between two integer elements 
 * 
 * @param a element a
 * @param b element b
 */
void Sortable::swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c; 
}

/**
 * @brief return a bollean value that check if the Sortable obj is sorted
 * 
 */
bool Sortable::isSorted(){
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
void printSortable(Sortable a){
    int *arr = a.getArray();
    int size = a.getSize();
    for(int i=0; i < size; i++){
        cout << " " << *arr;
        arr++;
    }
    cout << endl;
}

/**
 * @brief Using bubble sort, this method return a new Sortable sorted
 * 
 * @param arr the object that we want to order
 */
Sortable bubbleSort(Sortable arr){
    int* a = arr.getCopyArr();//get a copy of the array that we want to sort
    int n = arr.getSize();//get the size of the array
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n-(i+1); ++j)
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
    Sortable res(a, n);
    return res;
}

/**
 * @brief Using bucket sort, this method return a new Sortable sorted
 * 
 * @param arr the object that we want to order
 */
Sortable bucketSort(Sortable arr){
    int* a = arr.getCopyArr();//get the copy of the array that we want to sort
    int n = arr.getSize();//get the array's size
    int max = arr.getMax();//get the max value into the array
    int bucket[max];//raete a new array nedded to implement the alg.
    int i;
    for(int i=0; i<=max;i++){
        bucket[i]=0;
    }
    for(int i=0;i<n;i++){
        bucket[a[i]]++;
    }
    for (int i = 0, j = 0; i <= max && j<n; i++){  
        while (bucket[i] > 0){  
            a[j++] = i;
            bucket[i]--;
        }
    }
    Sortable res(a, n);
    return res;
}

/**
 * @brief Using count sort, this method return a new Sortable sorted
 * 
 * @param arr the object that we want to order
 */
Sortable countSort(Sortable a){
    int* arr = a.getCopyArr();//get the copy of the array that we want to sort 
    int size = a.getSize();//get the size of the array
    int* res = (int*)malloc(sizeof(int)*(size+1)); //create the new array we want return 
    int max = a.getMax(); //return the max value of the array
    int count[max+1];//create a new array needed to implement the alg
    for(int i=0; i<=max;++i)
        count[i]=0;
    for(int i=0; i<size;i++)
        count[arr[i]]++;
    for(int i=1; i<=max;i++)
        count[i]+=count[i-1];
    for(int i=size-1; i>=0; i--){
        res[count[arr[i]]-1] = arr[i];
        count[arr[i]] -= 1;
    }
    Sortable f(res, size);
    return f;
}


int main(){
    srand((unsigned) time(NULL));
    clock_t start, end, difference;
    /*Creation of the array that we want to sort and its initialization*/
    int *a = (int *)malloc(sizeof(int) * arraySize);
    for(int i=0; i < arraySize; i++){
        a[i] = rand()%1000000+1;
    }
    Sortable s(a, arraySize);
    /*Test bubblesort method*/
    cout << "Bubble sort started" << endl; 
    start = clock();
    Sortable bubble = bubbleSort(s);
    end = clock();
    difference = end - start;
    cout << "Bubble sort completed on an array with " << bubble.getSize() << endl;
    cout << "Success: " << bubble.isSorted() << endl;
    cout << "Time spent to sort: " << difference/1000 << " milliseconds" << endl << endl;
    
    /*Test bucketsort method*/
    cout << "Bucket sort started" << endl;
    start = clock();
    Sortable bucket = bucketSort(s);
    end = clock();
    difference = end - start;
    cout << "Bucket sort completed on an array with " << bucket.getSize() << endl;
    cout << "Success: " << bucket.isSorted() << endl;
    cout << "Time spent to sort: " << difference/1000 << " milliseconds" << endl << endl;
    
    /*Test countsort method*/
    cout << "Count sort started" << endl;
    start = clock();
    Sortable count = countSort(s);
    end = clock();
    difference = end - start;
    cout << "count sort completed on an array with " << count.getSize() << endl;
    cout << "Success: " << count.isSorted() << endl;
    cout << "Time spent to sort: " << difference/1000 << " milliseconds" << endl;
}