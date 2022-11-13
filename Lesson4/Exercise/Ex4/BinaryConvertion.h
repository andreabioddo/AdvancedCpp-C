#include <iostream>
#define BINARYCONVERTION_IMPORTED
#define MAX_DIGIT 16

namespace BinaryConvertion
{

    /*Struct to keep an array and its size to rapresent a binary number*/
    struct binary {
        int *arr;
        int size;
    };

    /**
     * Using the prompt, ask to the user a binary. If the number given by the user
     * are digits, they will save into a binary struct. This library gives the opportunity
     * to choose the max num of digits but the default is set as 16.
     * This function request a number until the 'q' (quit) is wrote in the console
    */
    
    //Uncomment this part to try the second way to upload numbers
    //struct binary getNumberBinary(int maxNum = MAX_DIGIT);

    /**
     * Using the prompt, ask to the user a binary. If the number given by the user
     * are digits, they will save into a binary struct. This library gives the opportunity
     * to choose the max num of digits but the default is set as 16. 
     * This function request a string of bit and then press enter to confirm.
    */
    struct binary getNumberBinaryInline(int maxDigit = MAX_DIGIT);

    /**
     * Given a binary struct that rapresent a binary number, it is converted
     * as a number in decimal base
     */
    int conversion(struct binary nums, int maxDigit = MAX_DIGIT);

    /**
     * Return true if the number given as param is either 0 or 1
     * */
    bool checkIfDigit(int digit);

    /*
     * Check if the numbers given as long int rappresent 
     * a binary number and split tehm and upload in the struct binary
     */
    bool check(long int a, struct binary *bin, int maxDigit);

}