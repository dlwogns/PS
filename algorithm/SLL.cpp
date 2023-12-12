#include <iostream>
#include <string>
using namespace std;

class Node {
private:
    int data;
    Node* next;
    Node* prev;

public:
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    friend class DLinkedList;
};

class DLinkedList {
private:
    Node* header;
    Node* trailer;
    int size;

public:
    DLinkedList() {
        this->header = NULL;
        this->trailer = NULL;
        this->size = 0;
    }
    void insert(int idx, int input_data){
        Node* newNode = new Node(input_data);
        if(idx == 0){
            if(size == 0){
                header = trailer = newNode;
            }else{
                newNode->next = header;
                header->prev = newNode;
                header = newNode;
            }
            size += 1;
        }else if(idx == size){
            trailer->next = newNode;
            newNode->prev = trailer;
            trailer = newNode;
            size += 1;
        }else{
            Node* curNode = header;
            while(idx--){
                curNode = curNode->next;
            }
            newNode->next = curNode;
            curNode->prev->next = newNode;
            newNode->prev = curNode->prev;
            curNode->prev = newNode;
        }
    }

    void Print(){
        Node* curNode = header;
        while(curNode != NULL){
            cout<<curNode->data<<' ';
            curNode = curNode->next;
        }
        cout<<endl;
    }
   
};

int main() {
    string cmd;
    DLinkedList dll;
    dll.insert(0,1);
    dll.insert(0,2);
    dll.insert(2,3);
    dll.insert(1,4);
    dll.Print();

   
}