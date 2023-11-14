#include <iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    friend class DLL;
};

class DLL{
    Node* header;
    Node* trailer;
    DLL(){
        header = new Node(-1);
        trailer = new Node(-1);
    }
    void Insert(int idx, int data){
        if(idx == 0){
            if(header == trailer){
                Node* newNode = new Node(data);
                newNode->prev = header;
                header->next = newNode;
                newNode->next = trailer;
                trailer->prev = newNode;
            }else{
                Node* newNode = new Node(data);
                header->next->prev = newNode;
                newNode->next = header->next;
                header->next = newNode;
                newNode->prev = header;
            }
        }else{
            Node* curNode = header->next;
            int cnt = 0;
            while(cnt != idx){
                curNode = curNode->next;
                cnt += 1;
            }
            // 0 -> 1 -> 2 -> 3 -> trailer
            Node* newNode = new Node(data);
            curNode->prev->next = newNode;
            newNode->prev = curNode->prev;
            newNode->next = curNode;
            curNode->prev = newNode;
        }
    }
    void Delete(int idx){
        Node* curNode = header->next;
        int cnt = 0;
        while(cnt != idx){
            curNode = curNode->next;
            cnt += 1;
        }
        // 0 -> 1 -> 2 -> 3
        curNode->prev->next = curNode->next;
        curNode->next->prev = curNode->prev;
        delete curNode;
        if(header->next == trailer){
            header = trailer = new Node(-1);
        }
    }
};