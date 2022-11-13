#include <iostream>
#include <string>
#include <cmath>
#include "BinaryConvertion.h"

using namespace std;

namespace BinaryConvertion{

    bool checkIfDigit(int digit){
        return digit == 1 || digit == 0;
    }


    bool check(long int a, struct binary *bin, int maxDigit){
        short temp = 0;
        bin->arr = (int*)malloc(sizeof(int)*maxDigit);
        bin->size = 0;
        while(a!=0){
            temp = a%10;
            if(!checkIfDigit(temp)){
                return false;
            }
            bin->arr[bin->size] = temp;
            bin->size ++;
            a/=10;
        }

        if(bin->size > maxDigit)
            return false;

        return true;
    }

    struct binary getNumberBinaryInline(int maxDigit){
        struct binary bin;
        long int s;
        bool valid = false;
        cout << "Please enter a binary to convert (letters are not allowed)" << endl;
        do{
            cin >> s;
            valid = check(s, &bin, maxDigit);
            if(!valid)
                cout << "Please enter a valid binary" << endl;
        } while(!valid);
        return bin;
    }


    int conversion(struct binary nums, int maxDigit){
        int numConverted = 0;
        for(int i=0; i<nums.size; i++){
            numConverted =  numConverted + pow(2,i) * nums.arr[i];
        }
        return numConverted;
    }


    //Second method to get a binary number
/*
    struct binary getNumberBinary(int maxDigit){
        struct binary bin;
        bin.arr = (int*)malloc(sizeof(int)*maxDigit);
        bin.size = 0;
        string s;
        while(bin.size < maxDigit){
            cin >> s;
            if(s.length() > 1){
                cout << "That is not a number !!" << endl;
            } else {
                if(s[0] == 'q'){
                    return bin;
                } else {
                    try{
                        int b = stoi(s);
                        if(checkIfDigit(b)){
                            bin.arr[bin.size] = b;
                            bin.size++;
                        }
                    } catch(exception e){
                        cout << "Something went wrong: " << endl;
                    }
                }
            }
        }
        return bin;
    }
*/


}
