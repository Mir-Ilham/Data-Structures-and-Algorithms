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

int main() {
    file();

    /*
        Stack Implementation using array (Fixed max size).

        Stack function implementations:
        1) Push
        2) Pop
        3) Top
        4) Size
    */
    ArrayStack ast(10);
    ast.Push(5);
    ast.Push(15);
    ast.Push(25);

    cout << ast.Size() << endl;
    cout << ast.Top() << endl;
    cout << ast.Pop() << endl;
    cout << ast.Pop() << endl;
    cout << ast.Pop() << endl;
    cout << ast.Pop() << endl;


    return 0;
}