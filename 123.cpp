#include <iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    friend class SLL;
};

class SLL{
    private:
        Node* head;
        Node* tail;
    public:
        SLL(){
            head = NULL;
            tail = NULL;
        }
        bool Empty(){
            return (head == NULL && tail == NULL);
        }
        void Append(int data){
            Node* newNode = new Node(data);
            if(Empty()){
                head = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = tail->next;
            }
        }
        void Insert(int idx, int data){
            Node* newNode = new Node(data);
             if(idx == 0){
                if(Empty()){
                    head = newNode;
                    tail = newNode;
                }else{
                    newNode->next = head;
                    head = newNode;
                }
             }else{
                Node* preNode = head;
                Node* curNode = head;
                int cur_idx = 0;
                while(cur_idx != idx){
                    preNode = curNode;
                    curNode = curNode->next;
                    cur_idx += 1;
                }
                if(curNode == NULL){
                    preNode->next = newNode;
                    tail = newNode;
                }
                else{
                    preNode->next = newNode;
                    newNode->next = curNode;
                }
             }
        }
        void Delete(int idx){
            if(idx == 0){
                if(head == tail && (head != NULL && tail != NULL)){
                    head = NULL;
                    tail = NULL;
                }else{
                    Node* curNode = head;
                    head = curNode->next;
                    delete curNode;
                }
            }else{
                Node* preNode = head;
                Node* curNode = head;
                int cnt = 0;
                while(cnt != idx){
                    preNode = curNode;
                    curNode = curNode->next;
                    cnt += 1;
                }
                preNode->next = curNode->next;
                if(curNode == tail){// preNode->next == NULL;
                    tail = preNode;
                }
                delete curNode;
            }
        }
};

int main(){
    SLL sll();

}