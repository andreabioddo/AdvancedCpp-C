#include <iostream>
#include "Sortable.h"
#include "tool.h"
using namespace std;
using namespace SortableSpace;
using namespace timeSpace;
#define arraySize 20

int main(){
    srand((unsigned) time(NULL));
    clock_t start;
    /*Creation of the array that we want to sort and its initialization*/
    int *a = (int *)malloc(sizeof(int) * arraySize);
    double *b = (double *)malloc(sizeof(double) * arraySize);
    for(int i=0; i < arraySize; i++){
        a[i] = rand()%1000000+1;
        b[i] = (double)(rand()%1000000+1);
    }
    Sortable<int>s(a, arraySize);
    Sortable<double>g(b, arraySize);
    cout << "Bubble sort started" << endl; 
    start = startTime();
    s.bubbleSort();
    g.bubbleSort();
    cout << "Bubble sort completed on an array S, with " << s.getSize() << endl;
    cout << "Bubble sort completed on an array G, with " << g.getSize() << endl;
    cout << "Success: " << s.isSorted() << endl;
    cout << "Success: " << g.isSorted() << endl;
    cout << "Time spent to sort: " << differenceTime(start)/1000 << " milliseconds" << endl << endl;
    return 0;

}