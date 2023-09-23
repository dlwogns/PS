#include <iostream>
using namespace std;

// push -> enqueue, pop -> dequeue
//   0 1 2 3 4 
// dequeue
// -1 1 2 3 4
// dequeue
// 5 -1 2 3 4
// enqueue
// 
// front -> 0, rear -> 0
// euqueue , front-> 0, rear ->1
// dequeue , front -> 1, rear -> 1

class arrQ{
    private:
        int capacity;
        int* arr;
        int rear;
        int front;
    public:
        arrQ(int Size){
            this->capacity = Size;
            arr = new int[capacity+1];
            front = 0;
            rear = 0;
            for(int i=0; i<capacity; i++)
                arr[i] = 0;
        }
        void enqueue(int value){
            if(rear  == this->capacity) {return;}
            rear += 1;
            rear %= capacity + 1;
            arr[rear] = value;
            // front -> 0, rear -> 1, arr[1] = value
        }
        void dequeue(){
            if(front == rear) return;
            front += 1;
            front %= capacity + 1;
            arr[front] = -1;
        }
        int Front(){
            if(rear == front) return -1;
            return arr[front+1];
        }
};


#include <queue>
queue<int>q;
int main(){
    q.push();
    q.pop();
    q.front();

}

// 0/5 -> 0
// 1 / 5 -> 5*0 + 1
// 2/5 -> 5*0 + 2
// 3/ 5 -> 3
// 4/5 -> 4
// 5/5 -> 0

// 1 2 3 4 5 6 7
// 2 3 4 5 6 7 1
// 4 5 6 7 1 2 
// 5 6 7 1 2 4
// 7 1 2 4 5