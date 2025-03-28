// stack by array
#include <iostream>
using namespace std;

class arrStack {
public:
    int* arr;
    int capacity;
    int idx;
    arrStack(int capacity){
        this->capacity = capacity;
        this->arr = new int[capacity];
        this -> idx = -1;
    }
    int Size(){
        return idx+1;
    }
    bool Empty(){
        return idx == -1;
    }
    int top(){
        if(Empty()) return -1;
        else return arr[idx];
    }
    void push(int e){
        if(Size( )== capacity){
            cout<<"FULL\n";
            return;
        }else{
            arr[++idx] = e;
        }
    }
    int pop(){
        if(Empty()) return -1;
        else{
            return arr[idx--];
            return arr[--idx];
        }
    }
};
