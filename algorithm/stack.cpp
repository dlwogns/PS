#include <iostream>
#include <stack>
using namespace std;
// FILO (fisrt in Last out)
// -> next, 숫자 - 노드
// 0 <- 1 <- 3 

// 1 2 3 4 5 6
// int size = 0;

// push(append), pop, top

class Node{
    int data;
    Node* next;
    Node(int input_data){
        this->data = input_data;
        next = NULL;
    }
    friend class Stack;
};

class Stack{
    public:
        Node* head, tail;
        int Size;
        Stack(){
            this->head = NULL;
            this->tail = NULL;
            Size = 0;
        }
        int size(){
            return Size;
        }
        void push(int e){
            Node* newNode = new Node(e);
            if(this->Size == 0){
                head = newNode;
                tail = newNode;
                Size += 1;
            }else{
                newNode->next = head;
                head = newNode;
                Size += 1;
            }
        }
        void pop(){
            if(this->Size == 0)
                return;
            Node* tmp = this->head;
            head = tmp->next;
            delete tmp;
            Size -= 1;
        }
        int top(){
            return head->data;
        }
};