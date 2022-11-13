#include <iostream>

namespace timeSpace{
    /**Return the current time*/
    clock_t startTime();
    /**Return the difference between the current time and the sime given as parameter*/
    clock_t differenceTime(clock_t startTime);
}