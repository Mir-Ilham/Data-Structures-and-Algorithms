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

// Recursive Traversals

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

// Iterative Traversals
void iterativePreorder(Node* root) {
    stack<Node*> st;
    st.push(root);

    while(!st.empty()) {
        Node* top = st.top();
        st.pop();

        cout << top->data << " ";
        
        if (top->right) st.push(top->right);
        if (top->left) st.push(top->left);
    }
}

void iterativeInorder(Node* root) {
    stack<Node*> st;
    Node* curNode = root;

    while(true) {
        if (curNode != NULL) {
            st.push(curNode);
            curNode = curNode->left;
        } else {
            if (st.empty()) break;
            Node* top = st.top();
            st.pop();
            cout << top->data << " ";
            curNode = top->right;
        }
    }
}

void iterativePostorder2ST(Node* root) {
    stack<Node*> st1, st2;

    st1.push(root);

    while (!st1.empty()) {
        Node* top = st1.top();
        st1.pop();

        if (top->left)
            st1.push(top->left);
        if (top->right)
            st1.push(top->right);

        st2.push(top);
    }

    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

void iterativePostorder1ST(Node* root) {
    stack<Node*> st;

    Node* cur = root; 

    while (cur != NULL || !st.empty()) {
        if (cur != NULL) {
            st.push(cur);
            cur = cur->left;
        } else {
            Node* temp = st.top()->right;

            if (temp == NULL) {
                temp = st.top();
                st.pop();
                cout << temp->data << " ";

                while (!st.empty() and st.top()->right == temp) {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            } else {
                cur = temp;
            }
        }
    }
}

void printAllTraversals(Node* root) {
    if (root == NULL) return;

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    vector<int> pre, in, post;
    
    while (!st.empty()) {
        auto top = st.top();
        st.pop();

        Node* topNode = top.first;
        int order = top.second;

        if (order == 1) {
            pre.push_back(topNode->data);
            st.push({topNode, order+1});

            if (topNode->left)
                st.push({topNode->left, 1});
        } else if (order == 2) {
            in.push_back(topNode->data);
            st.push({topNode, order+1});

            if (topNode->right)
                st.push({topNode->right, 1});
        } else {
            post.push_back(topNode->data);
        }
    }

    cout << "All Traverals" << endl;

    cout << "Preorder: ";
    for (int x : pre)
        cout << x << " ";
    cout << endl;

    cout << "Inorder: ";
    for (int x : in)
        cout << x << " ";
    cout << endl;

    cout << "Postorder: ";
    for (int x : post)
        cout << x << " ";
    cout << endl;
}

int main() {
    file();

    Node* root = getExampleTree();
    
    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Iterative Inorder: ";
    iterativeInorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Iterative Preorder: ";
    iterativePreorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    cout << "Iterative Postorder 2ST: ";
    iterativePostorder2ST(root);
    cout << endl;

    cout << "Iterative Postorder 1ST: ";
    iterativePostorder1ST(root);
    cout << endl;

    printAllTraversals(root);

    return 0;
}