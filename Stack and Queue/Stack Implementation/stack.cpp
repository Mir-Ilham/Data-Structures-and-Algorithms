#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

class ArrayStack {
private:
    int MX = 10;
    int *arr, top = -1;
public:
    ArrayStack(int n) {
        MX = n;
        arr = new int(MX);
    }
    
    void Push(int x) {
        if (top == MX - 1) return;
        top++;
        arr[top] = x;
    }

    int Pop() {
        if (top == -1) return -1;
        return arr[top--];
    }

    int Top() {
        if (top == -1) return -1;
        return arr[top];
    }

    int Size() {
        return top + 1;
    }
};

class Node {
public:
    Node* next;
    int data;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

class LinkedListStack {
private:
    Node* top;
    int size;
public:
    LinkedListStack() {
        this->top = nullptr;
        this->size = 0;
    }
    
    void Push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }

    int Pop() {
        if (top == NULL) return -1;

        Node* temp = top;
        top = top->next;
        int el = temp->data;
        delete temp;
        size--;
        return el;
    }

    int Top() {
        if (top == NULL)
            return -1;
        return top->data;
    }

    int Size() {
        return size;
    }
};

int main() {
    file();

    /*
        Stack Implementation using array and linked list.

        Stack function implementations:
        1) Push
        2) Pop
        3) Top
        4) Size
    */
   
    // ArrayStack ast(10);
    // ast.Push(5);
    // ast.Push(15);
    // ast.Push(25);

    // cout << ast.Size() << endl;
    // cout << ast.Top() << endl;
    // cout << ast.Pop() << endl;
    // cout << ast.Pop() << endl;
    // cout << ast.Pop() << endl;
    // cout << ast.Pop() << endl;

    LinkedListStack lst;
    lst.Push(5);
    lst.Push(15);
    lst.Push(25);

    cout << lst.Pop() << endl;
    cout << lst.Top() << endl;
    cout << lst.Size() << endl;
    cout << lst.Pop() << endl;

    return 0;
}