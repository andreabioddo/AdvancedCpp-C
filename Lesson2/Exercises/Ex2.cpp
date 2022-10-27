#include <iostream>
using namespace std;

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

bool Time::checkHour(int h){
    return (h>=0 && h<=23);
}

bool Time::checkMinSec(int t){
    return (t>=0 && t <=59);
}

bool Time::checkTime(int h, int m, int s){
    if(!checkHour(h))
        return false;
    if(!checkMinSec(m))
        return false;
    if(!checkMinSec(s))
        return false;
    return true;
}

Time::Time(int h, int m, int s){
    if(!checkTime(h,m,s)){
        cout << "Error: wrong values "<< endl;
        exit(EXIT_FAILURE);
    }
    hour=h;
    minute=m;
    second=s;
}

void Time::setTime(int newH, int newM, int newS){
    if(!checkTime(newH,newM,newS)){
        cout << "Error: wrong values "<< endl;
        exit(EXIT_FAILURE);
    }
    hour=(newH != -1) ? newH : hour;
    minute=(newM != -1) ? newM : minute;
    second=(newS != -1) ? newS : second;
}

void Time::getTime(int &h, int &m, int &s){
    h = hour;
    m = minute;
    s = second;
}

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
    a.getTime(h,m,s);
    cout << h << " " << m << " " << s << endl;
    a.setTime(23,59,58);
    a.incrementTime();
    a.incrementTime();
    a.getTime(h,m,s);
    cout << h << " " << m << " " << s << endl;    
    return 0;
}



