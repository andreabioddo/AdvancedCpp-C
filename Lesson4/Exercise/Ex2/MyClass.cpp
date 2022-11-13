#include <iostream>
#include <type_traits>

using namespace std;

template <class T>
class MyClass{
    private: 
        T value;

    public:
        MyClass(T value);
        T getValue();
        void setValue(T value);
};

/**Constructor of the class MyClass*/
template <class T>
MyClass<T>::MyClass(T v){
    value = v;
}

/**Return the value saved in the class*/
template <class T>
T MyClass<T>::getValue(){
    return value;
}

/**Set value = v, v given as parameter*/
template <class T>
void MyClass<T>::setValue(T v){
    value = v;
}

int main(){
    MyClass <int> a(10);
    cout << "Value: " << a.getValue() << endl;
    a.setValue(20);
    cout << "Value: " << a.getValue() << endl;

    MyClass <string> b("Hello");
    cout << "Value: " << b.getValue() << endl;
    b.setValue("World");
    cout << "Value: " << b.getValue() << endl;

    MyClass <double> c(30.12);
    cout << "Value: " << c.getValue() << endl;
    c.setValue(60.98);
    cout << "Value: " << c.getValue() << endl;

    return 0;
}