/**
 * @file Ex2.cpp
 * @author Andrea Bioddo (anbioddo@edu.aau.at)
 * @version 0.1
 * @date 2022-10-28
 * @brief Class that rapresents Time, with methods set, get and increment. Time class has also protected method needed
 * to check the validity of the values passed
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief Class that rapresent Time
 * 
 */
class Time{
    protected:
        int hour;
        int minute;
        int second;
        bool checkHour(int h);
        bool checkMinSec(int t);
        bool checkTime(int h, int m, int s);

    public:
        Time(int h, int m, int s);
        void getTime(int &h, int &m, int &s);
        void setTime(int newH, int newM, int newS);
        void incrementTime();
};

/**
 * @brief Check if the input is a number between 0 and 23. Return true
 * if the h follows the rule, false otherwise
 * 
 */
bool Time::checkHour(int h){
    return (h>=0 && h<=23);
}

/**
 * @brief Check if the input is a number between 0 and 59. Return true
 * if the h follows the rule, false otherwise
 * 
 */
bool Time::checkMinSec(int t){
    return (t>=0 && t <=59);
}

/**
 * @brief Check if the inputs are right to rapresent time. Return true
 * if the h, m, and s rapresent, false otherwise
 * 
 */
bool Time::checkTime(int h, int m, int s){
    if(!checkHour(h))
        return false;
    if(!checkMinSec(m))
        return false;
    if(!checkMinSec(s))
        return false;
    return true;
}

/**
 * @brief Time constructor
 * 
 */
Time::Time(int h, int m, int s){
    if(!checkTime(h,m,s)){
        cout << "Error: wrong values "<< endl;
        exit(EXIT_FAILURE);
    }
    hour=h;
    minute=m;
    second=s;
}

/**
 * @brief Set new values for Hour, Minute and Second
 * 
 */
void Time::setTime(int newH, int newM, int newS){
    if(!checkTime(newH,newM,newS)){
        cout << "Error: wrong values "<< endl;
        exit(EXIT_FAILURE);
    }
    hour=(newH != -1) ? newH : hour;
    minute=(newM != -1) ? newM : minute;
    second=(newS != -1) ? newS : second;
}

/**
 * @brief Set the three pointers with the actual time
 * 
 */
void Time::getTime(int &h, int &m, int &s){
    h = hour;
    m = minute;
    s = second;
}

/**
 * @brief increment of one second the time
 * 
 */
void Time::incrementTime(){
    if(second < 59){
        second++;
    } else if(second == 59){
        second = 0;
        if(minute < 59){
            minute++;
        } else if(minute == 59){
            minute = 0;
            if(hour < 23){
                hour++;
            } else if(hour == 23){
                hour = 0;
            }
        }
    }
}

int main(){
    Time a(1,1,1);
    int h,m,s;
    cout <<"Test" << endl;
    a.getTime(h,m,s);
    cout << "Hour: " << h << " minute: " << m << " second: " << s << endl;
    a.setTime(23,59,58);
    a.incrementTime();
    a.incrementTime();
    a.getTime(h,m,s);
    cout << "Hour: " << h << " minute: " << m << " second: " << s << endl;
    a.setTime(10,00,58);
    a.incrementTime();
    a.incrementTime();
    a.getTime(h,m,s);
    cout << "Hour: " << h << " minute: " << m << " second: " << s << endl;
    return 0;
}



