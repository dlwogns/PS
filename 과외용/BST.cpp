#include<iostream>
#include<string> 
#include<string.h> // memset, 
#include<queue>

using namespace std;

class Node {
public:
	int data;
	Node* par;
	Node* left;
	Node* right;
};

class BST {
private:
	Node* root;
	vector <int> arr; // ������� ������ ����.
public:
	BST() {
		root = NULL;
	}
	void insert(int tmp) {
		Node* cur_Node = new Node();
		cur_Node->data = tmp;

		if (root == NULL) {
			root = new Node();
			root->data = tmp;
		}
		else {
			Node* par_Node = NULL;
			Node* cur_Node = root;
			while (cur_Node != NULL) {
				if (tmp > cur_Node->data) {
					par_Node = cur_Node;
					cur_Node = cur_Node->right;
				}
				else {
					par_Node = cur_Node;
					cur_Node = cur_Node->left;
				}
			}
			cur_Node = new Node();
			cur_Node->data = tmp;
			cur_Node->par = par_Node;

			if (cur_Node->data > par_Node->data) {
				par_Node->right = cur_Node;
			}
			else {
				par_Node->left = cur_Node;
			}
		}
	}
	void Inorder(Node* n) {
		if (n->left != NULL) {
			Inorder(n->left);
		}
		arr.push_back(n->data); // �� ���Ϳ� �־���.
		if (n->right != NULL) {
			Inorder(n->right);
		}
	}

	void print() {
		Inorder(root);
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}
		arr.clear();
		cout << endl;
	}

	Node* search(int k) {
		Node* cur_Node = root;
		while (cur_Node->data != k) {
			if (cur_Node->data < k) {
				cur_Node = cur_Node->right;
			}
			else {
				cur_Node = cur_Node->left;
			}

			if (cur_Node == NULL) {
				return cur_Node;
			}
		}
		return cur_Node;
	}

	void Delete(int k) {
        Node* delete_node = search(k);
        if(delete_node->right == NULL && delete_node->left == NULL){
            if(delete_node == root){
                root = NULL;
            }else{
                if(delete_node->par->left == delete_node){
                    delete_node->par->left = NULL;
                    delete_node->par = NULL;
                    delete delete_node;
                }else if(delete_node->par->right == delete_node){
                    delete_node->par->right = NULL;
                    delete_node->par = NULL;
                    delete delete_node;
                }
            }
        }else if(delete_node->left != NULL && delete_node->right == NULL){
            if(delete_node == root){
                root = root->left;
                root->par = NULL;
            }else{
                delete_node->left->par = delete_node->par;
                if(delete_node->par->left == delete_node){
                    delete_node->par->left = delete_node->left;
                }else{
                    delete_node->par->right = delete_node->left;
                }
            }
        }else if(delete_node->left == NULL && delete_node->right != NULL){

        }else if(delete_node->left != NULL && delete_node->right != NULL){
            Node* cur_node = delete_node->right;
            while(cur_node->left != NULL){
                cur_node = cur_node->left;
            }
            if(delete_node == root){
                if(cur_node->right == NULL){

                    Node* temp = cur_node;

                    delete_node->left->par = cur_node;
                    delete_node->right->par = cur_node;
                    cur_node->left = delete_node->left;
                    cur_node->right = delete_node->right;
                    root = cur_node;
                    root = NULL;

                    if(temp->par->left == temp){
                        temp->par->left = NULL;
                    }else {
                        temp->par->right = NULL;
                    }
                }else{
                    delete_node->left->par = cur_node;
                    cur_node->left = delete_node->left;
                    root = cur_node;
                    root->par = NULL;
                }
            }else{
                if(delete_node->par->left == delete_node){
                    delete_node->par->left = delete_node;
                }else{
                    delete_node->par->right = delete_node;
                }
                if(cur_node->right == NULL){

                    Node* temp = cur_node;

                    delete_node->left->par = cur_node;
                    delete_node->right->par = cur_node;
                    cur_node->left = delete_node->left;
                    cur_node->right = delete_node->right;
                    cur_node->par = delete_node->par;

                    if(temp->par->left == temp){
                        temp->par->left = NULL;
                    }else {
                        temp->par->right = NULL;
                    }
                }else{
                    cur_node->par = delete_node->par;
                    delete_node->left->par = cur_node;
                    cur_node->left = delete_node->left;
                    
                }
            }

        }
	}


};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int testCase;
	cin >> testCase;
	BST minje;
	while (testCase--) {
		string s;
		cin >> s;
		if (s == "insert") {
			int tmp;
			cin >> tmp;
			minje.insert(tmp);
		}
		else if (s == "delete") {
			int tmp;
			cin >> tmp;
			minje.Delete(tmp);
		}
		else if (s == "sub") {
			int tmp;
			cin >> tmp;
			minje.sub(tmp);
		}
		else if (s == "print") {
			minje.print();
		}

	}
}
