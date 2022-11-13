#include "BinaryConvertion.h"
#include <iostream>
using namespace std;
using namespace BinaryConvertion;


int main(){

    /**Using the propmt, I ask user to write a binary*/
    struct binary nums = getNumberBinaryInline();
    /**Covert the binary number in a number in deciaml base*/
    cout << "The result of your binary is:\n" << conversion(nums) << endl;
    return 0;
}