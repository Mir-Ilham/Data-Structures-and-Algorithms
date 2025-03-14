#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

class Node {
    public:

    int data;
    Node* next;

    Node (int data, Node* next) {
        this->data = data;
        this->next = next;
    }
    Node (int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Create
Node* buildLinkedList(vector<int> &arr, int n) {
    // The new keyword dynamically allocates memory for a Node object on the heap 
    // and returns a pointer to it.
    if (n == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < n; i++) {
        prev->next = new Node(arr[i]);
        prev = prev->next;
    }
    return head;
}

// Insert
Node* insertHead(Node* head, int val) {
    return new Node(val, head);
}

Node* insertTail(Node* head, int val) {
    if (head == NULL)
        return new Node(val);
    
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node* insertPos(Node* head, int val, int pos) {
    if (head == NULL) {
        if (pos == 0)
            return new Node(val);
        else
            return head;
    }

    if (pos == 0)
        return new Node(val, head);

    int cnt = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (cnt == pos - 1) {
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
        cnt++;
    }
    return head;
}

Node* insertBeforeElement(Node* head, int val, int el) {
    if (head == NULL)
        return NULL;

    if (head->data == el)
        return new Node(val, head);

    Node* temp = head;
    while (temp != NULL) {
        if (temp->next != NULL and temp->next->data == el) {
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
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

int sizeOfLinkedList(Node* head) {
    Node* temp = head;
    int cnt = 0;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

bool searchLinkedList(Node* head, int item) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == item)
            return true;
        temp = temp->next;
    }
    return false;
}

// Delete
Node* removeHead(Node* head) {
    if (head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head) {
    if (head == NULL || head->next == NULL) return NULL;

    Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}

Node* removePos(Node* head, int pos) {
    if (head == NULL) 
        return head;

    if (pos == 0)
        return removeHead(head);

    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL) {
        if (cnt == pos) {
            prev->next = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    return head;
}

Node* removeItem(Node* head, int item) {
    if (head == NULL) 
        return head;

    if (head->data == item)
        return removeHead(head);

    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL) {
        if (temp->data == item) {
            prev->next = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    file();

    /*
        Problem Description:

        Implement functions to -
            1. Build a linked list from an array
            2. Traverse a linked list
            3. Find the length of a linked list
            4. Search an element in a linked list
            5. Insert a node in a linked list
            6. Delete a node from a linked list

    */

    /*
        Function documentation:
        
        ---------- Create ----------
        Node* buildLinkedList(vector<int> &arr, int n)
        // Build a linked list from an array

        ---------- Insert ----------
        Node* insertHead(Node* head, int val)
        // Insert a value at the head of the linked list

        Node* insertTail(Node* head, int val)
        // Insert a value at the tail of the linked list

        Node* insertPos(Node* head, int val, int pos)
        // Insert a value at a position of the linked list

        Node* insertBeforeElement(Node* head, int val, int el)
        // Insert a value before an element of the linked list

        ---------- Read ----------
        void traverseLinkedList(Node* head)
        // Traverse the linked list and print items

        int sizeOfLinkedList(Node* head)
        // Find the size of the linked list

        bool searchLinkedList(Node* head, int item)
        // Search for an item in the linked list

        ---------- Delete ----------
        Node* removeHead(Node* head)
        // Remove the head element from the linked list

        Node* removeTail(Node* head)
        // Remove the tail element from the linked list

        Node* removePos(Node* head, int pos)
        // Remove the element at position from the linked list

        Node* removeItem(Node* head, int item)
        // Remove an item from the linked list
    */

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    Node* head = buildLinkedList(arr, n);

    cout << "Size: " << sizeOfLinkedList(head) << endl;

    cout << "Linked list: ";
    traverseLinkedList(head);

    return 0;
}