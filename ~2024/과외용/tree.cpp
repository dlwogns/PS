// Array, List, queue, Stack, vector
// 선형 자료구조. Linear DataStructure
// 1 2 3 4 5 

// 비선형 자료구조.
// 트리, 그래프, 우선순위 큐

#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* parent;
    vector<Node*> children_node;

    Node(int data){
        this->data = data;
        this->parent = NULL;
    }
};

class Tree{
public:
    Node* root;
    vector<Node*> node_v;

    Tree(int);
    void insertNode(int, int);
    void deleteNode(int);
    void printChi(int);
    void printPar(int);
    void printDepth(int);
    void printLevel(int);

    void preorder(Node*);
    void postorder(Node*);
};

Tree::Tree(int data){
    Node* node = new Node(data);
    this->root = node;
    this->node_v.push_back(root);
}

void Tree::insertNode(int par, int data){
    Node* node = new Node(data);
    for(int i=0; i<node_v.size(); i++){
        if(node_v[i]->data == par){
            node_v[i]->children_node.push_back(node);
            node_v.push_back(node);
            node->parent = node_v[i];
            return;
        }
    }
}

void Tree::deleteNode(int data){
    Node* curNode;
    Node* parNode;

    for(int i=0; i<node_v.size(); i++){
        if(node_v[i]->data == data){
            if(node_v[i] == root){
                cout<<-1<<endl;
                return;
            }

            curNode = node_v[i];
            parNode = curNode->parent;
            for(Node* child : curNode->children_node){
                parNode->children_node.push_back(child);
                child->parent = parNode;
            }
            //iter++
            for(int j=0; j<parNode->children_node.size(); j++){
                if(parNode->children_node[j]->data == data){
                    //erase
                    parNode->children_node.erase(parNode->children_node.begin()+j);
                }
            }
            node_v.erase(node_v.begin()+i);
            delete curNode;
            return;
        }
    }
}
void Tree::preorder(Node* node){
    cout<<node->data<<' ';
    for(int i=0; i<node->children_node.size(); i++){
        preorder(node->children_node[i]);
    }
}
void Tree::postorder(Node* node){
    for(int i=0; i<node->children_node.size(); i++){
        postorder(node->children_node[i]);
    }
    cout<<node->data<<' ';
}
//            /1\
//         /2\    /3\
//        4   5  6   7

// preorder, inorder, postorder

// preorder
// 1 2 4 5 3 6 7 

// postorder
// 4 5 2 6 7 3 1

// in graph, bfs, dfs
// breadth first search
// depth first search

void Tree::printChi(int data){
    for(int i=0; i<node_v.size(); i++){
        if(node_v[i]->data == data){
            if(node_v[i]->children_node.empty()){
                cout<<-1<<endl;
                return;
            }
            for(Node* child : node_v[i]->children_node){
                cout<<child->data<<' ';
            }
            cout<<endl;
            return;
        }
    }
}
void Tree::printPar(int data){
    for(int i=0; i<node_v.size(); i++){
        if(node_v[i]->data == data){
            if(node_v[i] == root){
                cout<<-1<<endl;
                return;
            }
            cout<<node_v[i]->parent->data<<endl;
            return;
        }
    }
}
void Tree::printDepth(int data){
    for(int i=0; i<node_v.size(); i++){
        if(node_v[i]->data == data){
            Node* curnode = node_v[i];
            int depth =0;
            while(curnode != root){
                depth += 1;
                curnode = curnode->parent;
            }
            cout<<depth<<endl;
            return;
        }
    }
}
int main(){
    Tree tree(1);
    tree.insertNode(1, 2);
    tree.insertNode(1, 3);
    tree.insertNode(2, 4);
    tree.insertNode(2, 5);
    tree.insertNode(3, 6);
    tree.insertNode(3, 7);
    tree.printDepth(3);
}