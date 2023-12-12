// array queue
// Circular queue
#include <iostream>
using namespace std;
class Queue{
    private:
        int* arr;
        int rearidx;
        int frontidx;
        int capacity;
    public:
        Queue(int capacity){
            this->capacity = capacity;
            arr = new int[capacity+1];
            frontidx = rearidx = 0;
        }
    
        void enqueue(int value){
            if(frontidx == (rearidx+1) % (capacity+1)){
                cout<<"FULL\n";
            }else{
                rearidx = (rearidx+1) % (capacity+1);
                arr[rearidx] = value;
            }
        }
        void dequeue(){
            if(frontidx == rearidx){
                cout<<"EMPTY\n";
            }
            frontidx = (frontidx+1)%(capacity+1);
            arr[frontidx] = 0;
        }

        int Front(){
            if(frontidx == rearidx){
                cout<<"EMPTY\n";
                return -1;
            }
            return arr[(frontidx+1)%(capacity+1)];
        }

};