#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

class ArrayQueue {
private:
    int MX = 10;
    int *arr, start = -1, end = -1, size = 0;
public:
    ArrayQueue(int n) {
        MX = n;
        arr = new int(MX);
    }

    void Push(int x) {
        if (size == MX) return;

        if (start == -1) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % MX;
        }

        arr[end] = x;
        size++;
    }

    int Pop() {
        if (start == -1) return -1;

        int el = arr[start];

        if (size == 1) {
            start = end = -1;
        } else {
            start = (start + 1) % MX;
        }

        size--;
        return el;
    }

    int Front() {
        if (end == -1) return -1;
        return arr[end];
    }

    int Size() {
        return size;
    }
};

int main() {
    file();

    /*
        Queue Implementation using array (Fixed max size).

        Stack function implementations:
        1) Push
        2) Pop
        3) Front
        4) Size
    */
    ArrayQueue aq(5);
    aq.Push(1);
    aq.Push(2);
    aq.Push(3);
    aq.Push(4);
    aq.Push(5);
    aq.Push(6);

    cout << aq.Front() << endl;
    cout << aq.Pop() << endl;
    cout << aq.Pop() << endl;
    cout << aq.Pop() << endl;
    cout << aq.Pop() << endl;
    cout << aq.Pop() << endl;
    cout << aq.Pop() << endl;

    cout << aq.Size() << endl;

    aq.Push(101);
    cout << aq.Front() << endl;


    return 0;
}