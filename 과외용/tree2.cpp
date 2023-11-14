#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node* par;
        vector<Node*> children_v;
        Node(int data){
            this->data = data;
            this->par = NULL;
        }
};

class Tree{
    public:
        Node* root;
        vector<Node*> node_v;

        Tree(int data){
            Node* node = new Node(data);
            this->root = node;
            this->node_v.push_back(node);
        }
        void insertNode(int par_data, int chi_data){
            Node* node = new Node(chi_data);
            for(int i=0; i<node_v.size(); i++){
                if(node_v[i]->data == par_data){
                    node_v[i]->children_v.push_back(node);
                    node->par = node_v[i];
                    node_v.push_back(node);
                    return;
                }
            }
        }
        void deleteNode(int data){
            for(int i=0; i < node_v.size(); i++){
                if(node_v[i]->data == data){
                    if(node_v[i] == root){
                        cout<<-1<<'\n';
                        return;
                    }
                    // 자식을 올려보낸다
                    Node* parNode = node_v[i]->par;
                    Node* curNode = node_v[i];
                    for(Node* child : node_v[i]->children_v){
                        child->par = parNode;
                        parNode->children_v.push_back(child);
                    }
                    for(int j=0; j < parNode->children_v.size(); j++){
                        if(parNode->children_v[j]->data == data){
                            parNode->children_v.erase(parNode->children_v.begin()+j);
                        }
                    }

                    node_v.erase(node_v.begin()+i);
                    delete curNode;
                    return;
                }
            }
        }
        void preorder(Node* curnode){ // root부터 시작
            cout<<curnode->data<<' ';
            for(Node* node : curnode->children_v){
                preorder(node);
            }
            
        }
        void postorder(Node* curnode){ // root 시작
            for(Node* node : curnode->children_v){
                preorder(node);
            }
            cout<<curnode->data<<' ';
        }


};

int arr[100];
arr[1] -> root
arr[1 * 2] -> root left child
~~~~~~