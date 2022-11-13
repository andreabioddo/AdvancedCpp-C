#include <iostream>
using namespace std;

template <class T>
class Stack {
    private:
        T *ar;
        int size;
        int top;
    
    public:
        /**Constructor of the class Stack*/
        Stack(int s){
            size = s;
            ar = (T*)malloc(sizeof(T)*size);
            top = -1;
        }
        
        /**Return the stack's size*/
        int getSize(){
            return size;
        }

        /**Push an element*/
        void push(T elem){
            if(isFull()){
                cout << "Stack full" << endl;
                exit(EXIT_FAILURE);
            }
            else {
                top++;
                ar[top] = elem;
            }
        }

        /**Return true if the stack is full, false otherwise*/
        bool isFull(){
            return top == size;
        }
        
        /*Return true if the stack is empty, false otherwise*/
        bool isEmpty(){
            return top == -1;
        }
        

        T pop(){
            if(isEmpty()){
                cout << "Stack is empty: pop not allowed" << endl;
                exit(EXIT_FAILURE);
            }
            T elem = ar[top];
            top--;
            return elem;
        }
        

        /*Return the max value in the stack*/
        T getMax(){
            if(isEmpty()){
                cout << "Stack is empty: getMax not allowed" << endl;
                exit(EXIT_FAILURE);
            }
            T max = ar[0];
            for(int i=0; i < size; i++)
                if(ar[i] > max)
                    max = ar[i];
            
            return max;
        }

        /**Return the sum of all items in the stack*/
        T getSum(){
            if(isEmpty()){
                cout << "Stack is getSum: getMax not allowed" << endl;
                exit(EXIT_FAILURE);
            }
            T sum = ar[0];
            for(int i=1; i < size; i++)
                sum = sum + ar[i];
            return sum;
        }

        /**Print on the console the stack*/
        void printStack(){
            cout << "Print stack: " << endl;
            if(isEmpty()){
                cout << "--Stack empty--" << endl;
                return;
            }
            for(int i=0; i <= top; i++)
                cout <<  ar[i] << ", ";
            cout << endl;
        }

        /*Return the number that rapresent the numbers in the stack*/
        int getNumElem(){
            return top+1;
        }
};

int main(){
    Stack<int> el(10);
    //Push 10
    el.push(10);
    //Push 15
    el.push(15);
    cout << "Num elements: " << el.getNumElem() << endl;
    el.printStack();
    cout << "SUM: " << el.getSum() << endl;

    cout << "Max elem in stack: " << el.getMax() << endl;
    cout << "Pop elem: " << el.pop() << endl;
    el.printStack();
    cout << "Pop elem: " << el.pop() << endl;
    el.printStack();

    Stack<double> it(10);
    //Push 10
    it.push(10.10);
    //Push 15
    it.push(15.10);
    cout << "Num elements: " << it.getNumElem() << endl;
    it.printStack();
    cout << "SUM: " << it.getSum() << endl;

    cout << "Max elem in stack: " << it.getMax() << endl;
    cout << "Pop elem: " << it.pop() << endl;
    it.printStack();
    cout << "Pop elem: " << it.pop() << endl;
    it.printStack();
}

