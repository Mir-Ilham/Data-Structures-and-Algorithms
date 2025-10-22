#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

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
        Problem Description: Implementation the heapify algorithm

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