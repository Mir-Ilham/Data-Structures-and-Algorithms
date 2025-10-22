#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

class Heap {
private:
    vector<int> nodes;
    // Default max heap comparator - Swap if child greater than parent
    function<bool(int, int)> compare = [](int a, int b) { return a > b; };
public:
    Heap(bool isMin=false) {
        nodes.push_back(0);
        // Min heap comparator - Swap if child lesser than parent
        if (isMin)
            compare = [](int a, int b) { return a < b; };
    }

    void insert(int val) {
        nodes.push_back(val);
        int cur = nodes.size() - 1;
        int parent = cur / 2;
        while (parent != 0) {
            if (compare(nodes[cur], nodes[parent])) {
                swap(nodes[cur], nodes[parent]);
                cur = parent;
                parent = cur / 2;
            } else {
                break;
            }
        }
    }

    int pop() {
        if (nodes.size() == 1) {
            return -1;
        }

        int ret = nodes[1];
        nodes[1] = nodes.back();
        nodes.pop_back();

        int cur = 1;
        int size = nodes.size();

        while (cur < size) {
            int left = 2*cur;
            int right = 2*cur + 1;

            int best = cur;
            
            if (left < size and compare(nodes[left], nodes[best]))
                best = left;
            if (right < size and compare(nodes[right], nodes[best]))
                best = right;
            
            if (best == cur) break;

            swap(nodes[best], nodes[cur]);
            cur = best;
        }

        return ret;
    }

    void printNodes() {
        for (int &x : nodes)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    file();

    /*
        Problem Description: Implementation of min heap and max heap.

        Input:
        The first line of input includes the number of nodes n.
        The next line contains values for n nodes.
    */

    Heap maxHeap, minHeap(true); 
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        maxHeap.insert(x);
        minHeap.insert(x);
    }

    cout << "Max heap: ";
    maxHeap.printNodes();

    cout << "Min heap: ";
    minHeap.printNodes();

    for (int i = 0; i < n; i++) {
        cout << maxHeap.pop() << endl;
        maxHeap.printNodes();
    }

    for (int i = 0; i < n; i++) {
        cout << minHeap.pop() << endl;
        minHeap.printNodes();
    }

    return 0;
}