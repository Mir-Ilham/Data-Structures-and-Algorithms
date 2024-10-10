#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

void generateSubsets(int idx, vector<int> &arr, vector<int> &subset, vector<vector<int>> &power_set) {
    if (idx == arr.size()) {
        power_set.push_back(subset);
        return;
    }

    // Don't take arr[idx] in subset
    generateSubsets(idx + 1, arr, subset, power_set);

    // Take arr[idx] in subset
    subset.push_back(arr[idx]);
    generateSubsets(idx + 1, arr, subset, power_set);

    subset.pop_back(); // Backtracking
}

int main() {
    file();

    /*
        Problem Description:

        Given an array of size N, generate the power set of the array.
        A set containing all of the possible subsets of an array is called a powerset.

        Constraints:
        1 <= N <= 26

        Time Complexity: O(2^N * N)
        
        Space Complexity: O(2^N * N)

    */

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    vector<vector<int>> power_set;

    vector<int> subset;

    generateSubsets(0, arr, subset, power_set);

    for (auto vec : power_set) {
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}