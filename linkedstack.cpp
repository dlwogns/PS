#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int e){
        data = e;
        next = NULL;
    }
};
class LinkedStack{
public:
    Node* head;
    Node* tail;
    int n;

    LinkedStack(){
        this->head = NULL;
        this->tail = NULL;
        n = 0;
    }
    bool Empty(){
        return n == 0;
    }
    int top(){
        if(Empty()){
            return -1;
        }
        else{
            return head->data;
        }
    }
    void push(int e){
        Node* newNode = new Node(e);
        if(Empty()){
            head = tail = newNode;
            n += 1;
        }else{
            newNode->next = head;
            head = newNode;
            n += 1;
        }
        // 1 <- 2 <- 3 <- 4(head)
        // 2(head) -> 3 -> 4
    }
    int pop(){
        if(Empty()) return -1;
        else{
            Node* temp = head;
            int d = temp->data;
            head = head->next;
            n -= 1;
            delete temp;
            return d;
        }
    }
};
// 1 <- 2 <- 3 <- 4
// int idx = 1;
// idx++; ++idx;
// for(int i=0; i<=N; i++)
