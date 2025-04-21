#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

class Node {
    public:

    int data;
    Node* left;
    Node* right;

    Node (int data, Node* left, Node* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    Node (int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* getExampleTree() {
    Node* root = new Node(1);

    root->left = new Node(7);
    root->right = new Node(9);

    root->left->left = new Node(2);
    root->left->right = new Node(6);

    root->left->right->left = new Node(5);
    root->left->right->right = new Node(11);

    root->right->right = new Node(9);

    root->right->right->left = new Node(5);

    return root;
}

// Traversals

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    file();

    Node* root = getExampleTree();
    
    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    return 0;
}