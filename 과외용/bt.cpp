#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node* par;
        Node* left_child;
        Node* right_child;
        Node(int data){
            this->data = data;
            par = NULL;
            left_child = NULL;
            right_child = NULL;
        }
};

class bt{
    public:
        Node* root;
        vector<Node*> all_node;
        bt(int data){
            root = new Node(data);
            all_node.push_back(root);
        }
        void insert(int par_data,int data){
            for(auto parnode : all_node){
                if(parnode->data == par_data){
                    if(parnode->left_child == NULL)
                        parnode->left_child = new Node(data);
                    else if(parnode->right_child == NULL){
                        parnode->right_child = new Node(data);
                    }else{
                        cout<<"unable to insert\n";
                    }
                }
            }
        }
        void Delete(int data){
            if(root->data == data){
                cout<<"unable to delete\n";
                return;
            }
        }

};