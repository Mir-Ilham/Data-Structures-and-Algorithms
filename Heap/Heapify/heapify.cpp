#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

void heapifyRecursive(vector<int> &arr, int n, int i, function<bool(int, int)> compare) {
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    // Check if left child is larger
    if (left < n && compare(arr[left], arr[largest]))
        largest = left;

    // Check if right child is larger
    if (right < n && compare(arr[right], arr[largest]))
        largest = right;

    // If largest is not the root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyRecursive(arr, n, largest, compare);
    }
}

void heapify(vector<int> &heap, int i, function<bool(int, int)> compare) {
    int size = heap.size();
    int cur = i;

    while (true) {
        int left = 2 * cur;
        int right = 2 * cur + 1;
        int best = cur;

        // Check left child
        if (left < size && compare(heap[left], heap[best]))
            best = left;

        // Check right child
        if (right < size && compare(heap[right], heap[best]))
            best = right;

        // If current is already in correct place, stop
        if (best == cur) break;

        swap(heap[cur], heap[best]);
        cur = best;
    }
}

int main() {
    file();

    /*
        Problem Description: Implementation of the heapify algorithm

        Input:
        The first line of input includes the number of nodes n.
        The next line contains values for n nodes.
    */

    int n;
    cin >> n;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    function<bool(int, int)> compare = [](int a, int b) { return a > b; };

    for (int i = n / 2; i > 0; i--) {
        heapify(v, i, compare);
    }

    cout << "Max heap: ";
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    cout << endl;

    compare = [](int a, int b) { return a < b; };

    for (int i = n / 2; i > 0; i--) {
        heapify(v, i, compare);
    }

    cout << "Min heap: ";
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}