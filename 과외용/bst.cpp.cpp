#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* parent;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        parent = left = right = NULL;
    }
};

class BST{
    private:
        Node* root;
    public:
        BST(int data){
            root = new Node(data);
        }
        void Insert(int data){
            Node* newNode = new Node(data);
            Node* curNode = root;
            while(curNode != NULL){
                if(curNode->data < data){
                    if(curNode->right != NULL){
                        curNode = curNode->right;
                        continue;
                    }else{
                        newNode->parent = curNode;
                        curNode->right = newNode;
                        break;
                    }
                }else if(curNode->data > data){
                    if(curNode->left != NULL){
                        curNode = curNode->left;
                        continue;
                    }else{
                        newNode->parent = curNode;
                        curNode->left = newNode;
                        break;
                    }
                }
            }
        }
        Node* search(int data){
            Node* curNode = root;
            while(curNode->data != data){
                if(curNode->data < data){
                    curNode = curNode->right;
                }else if(curNode->data > data){
                    curNode = curNode->left;
                }else{
                    return curNode;
                }
            }
        }
        void Delete(int data){
            // 삭제할 노드 탐색
            Node* delete_node = search(data);

            // 삭제할 노드가 리프노드인 경우.
            if(delete_node->left == NULL && delete_node->right == NULL){
                // 삭제할 노드가 루트 노드인 경우
                if(delete_node == root){
                    // 자식 노드가 없으므로 root = NULL 후 종료.
                    root = NULL;
                    return;
                }
                // 삭제할 노드가 삭제할 노드의 부모노드의 왼쪽 자식인 경우
                if(delete_node->parent->left == delete_node){
                    // 삭제할 노드의 부모노드의 왼쪽 자식 삭제.
                    delete_node->parent->left = NULL;
                    delete_node->parent = NULL;
                // 삭제할 노드가 삭제할 노드의 부모노드의 오른쪽 자식인 경우
                }else{
                    // 삭제할 노드의 부모노드의 오른쪽 자식 삭제.
                    delete_node->parent->right = NULL;
                    delete_node->parent = NULL;
                }
            // 삭제할 노드의 자식 노드가 하나 있고, 그 자식이 오른쪽 자식일 경우
            }else if(delete_node->left == NULL && delete_node->right != NULL){
                // 삭제할 노드가 루트 노드라면 오른쪽 자식을 root로 바꾼다.
                if(delete_node == root){
                    root = root->right;
                    root->parent = NULL;
                    return;
                }
                // 삭제할 노드의 오른쪽 자식의 부모 포인터를 삭제할 노드의 부모로 바꾼다.
                delete_node->right->parent = delete_node->parent;
                // 삭제할 노드가 삭제할 노드의 부모 노드의 왼쪽 자식인지 오른쪽 자식인지 확인.
                if(delete_node->parent->left == delete_node){
                    delete_node->parent->left = delete_node->right;
                }else{
                    delete_node->parent->right = delete_node->right;
                }

            }else if(delete_node->left != NULL && delete_node->right == NULL){
                if(delete_node == root){
                    root = root->left;
                    root->parent = NULL;
                    return;
                }
                delete_node->left->parent = delete_node->parent;
                if(delete_node->parent->left == NULL){
                    delete_node->parent->left =delete_node->left;
                }else{
                    delete_node->parent->right = delete_node->left;
                }
            }else{ // 삭제할 노드의 자식이 두개인 경우.

                // 오른쪽 서브트리에서 가장 왼쪽에 있는 노드.
                Node* curnode = delete_node->right;

                // 왼쪽자식이 없을때 까지 반복문 수행.
                while(curnode->left != NULL){
                    curnode = curnode->left;
                }
                // 삭제할 노드가 root가 아니면
                if(delete_node != root){
                    // 삭제할 노드가 부모의 왼쪽 자식인지, 오른쪽 자식인지 확인.
                    if(delete_node->parent->left == delete_node){
                        delete_node->parent->left = curnode;
                    }else{
                        delete_node->parent->right = curnode;
                    }
                    // curnode의 자식이 없는 경우
                    if(curnode->right == NULL){
                        Node* temp = curnode;
                        // curnode의 부모를 삭제할 노드의 부모로 바꿔준다.
                        curnode->parent = delete_node->parent;
                        // 삭제할 노드의 왼쪽, 오른쪽 자식의 부모를 가리키는 포인터를 curnode로 바꾼다.
                        delete_node->left->parent = curnode;
                        delete_node->right->parent = curnode;
                        // curnode의 왼쪽, 오른쪽 자식을 삭제할 노드의 왼쪽, 오른쪽 자식으로 바꾼다. 
                        curnode->left = delete_node->left;
                        curnode->right = delete_node->right;
                        // curnode의 이동 전 정보를 저장한 temp의 부모의 왼쪽 자식 정보를 지운다.
                        temp->parent->left = NULL;
                    }else{// curnode의 자식이 하나 있는 경우
                    
                        curnode->parent = delete_node->parent;

                        delete_node->left->parent = curnode;
                        delete_node->right->parent = curnode;
                        // 자식이 하나 있는 경우 무조건 오른쪽 자식이므로 자식이 하나있고 오른쪽 자식일때 삭제할 경우와 동일하게 수행한다.
                        curnode->right->parent = curnode->parent;
                        curnode->parent->left = curnode->right;

                        curnode->left = delete_node->left;
                        curnode->right = delete_node->right;
                    }
                }else{// 삭제할 노드가 root인 경우.
                    if(curnode->right == NULL){
                        Node* temp = curnode;

                        delete_node->left->parent = curnode;
                        delete_node->right->parent = curnode;

                        curnode->left = delete_node->left;
                        curnode->right = delete_node->right;

                        // root로 바꿔주고 root->parent를 null 처리.
                        root = curnode;
                        root->parent = NULL;
                        
                        temp->parent->left = NULL;
                    }else{
                        delete_node->left->parent = curnode;
                        delete_node->right->parent = curnode;

                        curnode->right->parent = curnode->parent;
                        curnode->parent->left = curnode->right;

                        curnode->left = delete_node->left;
                        curnode->right = delete_node->right;
                        
                        root = curnode;
                        root->parent = NULL;
                    }
                }
            }
        }
        void Inorder(Node* curnode){
            if(curnode->left != NULL){
                Inorder(curnode->left);
            }
            cout<<curnode->data<<' ';
            if(curnode->right != NULL){
                Inorder(curnode->right);
            }
        }

};

// preorder
// 50 30 1 35 70 60 80

// postorder
// 1 35 30 60 80 70 50 

// inorder
// 1 30 35 50 60 70 80 