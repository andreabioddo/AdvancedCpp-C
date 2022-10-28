#include <iostream>
using namespace std;

class A{
    public:
        string x;
        A(){}
        A(string i){
            x=i;
        }
        void operator+(A);
        void display();
};

void A::operator+(A a){
    string m = x+a.x;
    cout << "The result of the addition of two obj is: " << m << endl;
}

int main(){
    A a1("welcome");
    A a2("back"),
    a1+a2;
    return 0;
}