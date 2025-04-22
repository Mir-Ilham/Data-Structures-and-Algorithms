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

// BFS Traversal

void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();
        cout << front->data << " ";

        if (front->left)
            q.push(front->left);
        
        if (front->right)
            q.push(front->right);
    }
}

int main() {
    file();

    Node* root = getExampleTree();
    
    cout << "Level order: ";
    levelOrder(root);
    cout << endl;

    return 0;
}