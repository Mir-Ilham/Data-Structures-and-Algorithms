#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

class Node {
    public:

    int data;
    Node *prev, *next;

    Node (int data, Node* prev, Node* next) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
    Node (int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

// Create
Node* buildDoublyLinkedList(vector<int> &arr, int n) {
    if (n == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < n; i++) {
        prev->next = new Node(arr[i], prev, nullptr);
        prev = prev->next;
    }
    return head;
}

// Read
void traverseLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Insert
Node* insertBeforeHead(Node* head, int val) {
    Node * newHead = new Node(val, nullptr, head);
    head->prev = newHead;
    
    return newHead;
}

Node* insertBeforeTail(Node* head, int val) {
    if (head->next == NULL)
        return insertBeforeHead(head, val);

    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    Node* back = tail->prev;
    Node* newNode = new Node(val, back, tail);
    back->next = newNode;
    tail->prev = newNode;
    return head;
}

Node* insertBeforeKthElement(Node* head, int k, int val) {
    if (k == 0)
        return insertBeforeHead(head, val);

    Node* temp = head;
    int pos = 0;
    while (temp->next != NULL) {
        if (pos == k) break;
        temp = temp->next;
        pos++;
    }

    Node* back = temp->prev;
    Node* newNode = new Node(val, back, temp);
    back->next = newNode;
    temp->prev = newNode;
    return head;
}

// Delete
Node* removeHead(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    
    head->prev = nullptr;
    temp->next = nullptr;

    delete temp;
    return head;
}

Node* removeTail(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    
    Node *tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    Node *newTail = tail->prev;
    newTail->next = nullptr;
    tail->prev = nullptr;
    delete tail;
    return head;
}

Node* removeKthElement(Node* head, int k) {
    if (head == NULL) return NULL;

    int pos = 0;
    Node *temp = head;
    while (temp != NULL) {
        if (pos == k) break;
        pos++;
        temp = temp->next;
    }

    Node* back = temp->prev;
    Node* front = temp->next;

    if (back == NULL and front == NULL) {
        delete temp;
        return NULL;
    } else if (back == NULL) {
        return removeHead(head);
    } else if (front == NULL) {
        return removeTail(head);
    }

    back->next = front;
    front->prev = back;
    temp->prev = nullptr;
    temp->next = nullptr;
    delete temp;

    return head;
}

int main() {
    file();

    /*
        Problem Description:

        Implement functions to -
            1. Build a doubly linked list from an array
            2. Traverse a doubly linked list
            3. Insert a node in a doubly linked list
            4. Delete a node from a doubly linked list

    */

    /*
        Function documentation:
        
        ---------- Create ----------
        Node* buildDoublyLinkedList(vector<int> &arr, int n)
        // Build a doubly linked list from an array

        ---------- Insert ----------
        Node* insertBeforeHead(Node* head, int val)
        // Insert a value before the head of the doubly linked list

        Node* insertBeforeTail(Node* head, int val)
        // Insert a value before the tail of the doubly linked list

        Node* insertBeforeKthElement(Node* head, int k, int val)
        // Insert a value before the kth element of the doubly linked list

        ---------- Read ----------
        void traverseLinkedList(Node* head)
        // Traverse the linked list and print items

        ---------- Delete ----------
        Node* removeHead(Node* head)
        // Remove the head element from the doubly linked list

        Node* removeTail(Node* head)
        // Remove the tail element from the doubly linked list

        Node* removeKthElement(Node* head, int k)
        // Remove the kth element from the doubly linked list
    */

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    Node* head = buildDoublyLinkedList(arr, n);

    head = insertBeforeKthElement(head, 0, 101);

    cout << "Linked list: ";
    traverseLinkedList(head);

    return 0;
}