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

Node* insert(Node* head, int val) {
    if (head == NULL) return new Node(val);

    Node* temp = head;
    while (true) {
        if (val < temp->data) {
            if (temp->left == NULL) {
                temp->left = new Node(val);
                break;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->right == NULL) {
                temp->right = new Node(val);
                break;
            } else {
                temp = temp->right;
            }
        }
    }

    return head;
}

Node* buildBST(vector<int> &arr) {
    Node* head = NULL;

    for (int i = 0; i < arr.size(); i++)
        head = insert(head, arr[i]);

    return head;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* search(Node* head, int val) {
    while (head != NULL and head->data != val)
        head = (val < head->data) ? head->left : head->right;
    return head;
}

int main() {
    file();

    /*
        Problem Description:

        Implement functions to -
            1. Insert a node into a Binary Search Tree given it's head
            2. Build a Binary Search Tree from an array
            3. Traverse the BST
            4. Search for an element in the BST
    */

    /*
        Function documentation:
        
        ---------- Create ----------
        Node* buildBST(vector<int> &arr)
        // Build a Binary Search Tree from unique array elements

        ---------- Insert ----------
        Node* insert(Node* head, int val)
        // Insert a value in the Binary Search Tree given it's head (assuming val not present)

        ---------- Read ------------
        void inorder(Node* root)
        // Traverse the BST inorder (Sorted output)

        Node* search(Node* head, int val)
        // Search in a BST, return the Node that matches val else return NULL

        ---------- Delete ----------
    */

    Node* head = NULL;
    vector<int> arr = {6, 9, 1, 0, 12, 4};
    head = buildBST(arr);

    cout << "Inorder traversal of BST: ";
    inorder(head);
    cout << endl;

    return 0;
}