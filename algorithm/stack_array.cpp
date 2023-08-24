#include <iostream>
#include <stack>
using namespace std;

class arrStack{
    public:
        int* arr;
        int capacity;
        int Size;
    arrStack(int c){
        this->capacity = c;
        this->arr = new int[capacity];
        this->Size = -1;
    }
    // size, empty, top, push, pop
    int size(){
        return this->Size+1;
    }
    bool empty(){
        return this->Size == -1;
    }
    int top(){
        if(empty()) return -1;
        else return arr[Size];
    }
    void push(int e){
        if(capacity == size()) cout<<"FULL"<<endl;
        else arr[size()] = e;
    }
    void pop(){
        if(empty()) cout<<"EMTPY"<<endl;
        else {
            Size -= 1;
        }
    }
};

