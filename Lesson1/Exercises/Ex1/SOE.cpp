/**
 * @file SOE.cpp
 * @author Andrea Bioddo (anbioddo@edu.aau.at)
 * @brief 
 * @version 0.1
 * @date 2022-10-20
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief The class SOE (Sieve Of Eratosthenes) has some public methods to print 
 * the array generated using the algorithm, set a new limit to find the primes number.
 * 
 */
class SOE {
    public: 
        SOE();
        SOE(int n);
        void setLimit(int l);
        void printPrimesNum();

    private:
        void findPrimesNum();
        int* primesNum;
        int size;
        int limit;
};

/**
 * @brief Construct a new SOE::SOE object. If no limit is given, the limit for default is set to 0.
 * 
 */
SOE::SOE(){
    limit=0;
    size=0;
    primesNum=(int*)malloc(0);
}

/**
 * @brief Construct a new SOE::SOE object
 * 
 * @param l set a limit to n and then it run the alorithm
 */
SOE::SOE(int l){
    setLimit(l);
    findPrimesNum();
}

/**
 * @brief set a new 
 * 
 * @param l 
 */
void SOE::setLimit(int l){
    if(l<0){
        cout << "Operation not allowed: limit cannot be negative" << endl;
        exit(EXIT_FAILURE);
    }
    limit = l;
    findPrimesNum();
}

/**
 * @brief Print the array with the primes number finded using the algorithm.
 * 
 */
void SOE::printPrimesNum(){
    cout << "USing SOE, there are " << size << " primes numbers with a limit set to: " << limit << endl;
    cout << "The numbers are: " << endl;
    for(int i=0; i<size; i++){
        cout << primesNum[i] << " ";
    }
    cout << endl;
}

/**
 * @brief this method use the SOE algorithm and save the result into an array.
 * 
 */
void SOE::findPrimesNum(){
    bool arr[limit+1];
    size = 0;
    for(int i=0; i<=limit; i++)
        arr[i] = true;
    for(int p=2; p*p<=limit; p++){
        if(arr[p]){
            for(int j=p*2; j<=limit; j=j+p){
                arr[j] = false;
            }
        }
    }

    primesNum = (int*)malloc(sizeof(int)*limit);
    for(int p=2; p<=limit; p++){
        if(arr[p]){
            primesNum[size] = p;
            size++;
        }
    }
    primesNum = (int*)realloc(primesNum, sizeof(int)*size);
}

int main(){
    clock_t start, end;
    start = clock();
    SOE a(4);
    end = clock();
    a.printPrimesNum();
    cout << "Result found in: " << (end-start)/10000 << " milliseconds." << endl << endl;
    start = clock();
    a.setLimit(100);
    end = clock();
    a.printPrimesNum();
    cout << "Result found in: " << (end-start)/10000 << " milliseconds." << endl;
}