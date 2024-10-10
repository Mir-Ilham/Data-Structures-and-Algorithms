#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int main() {
    file();

    /*
        Problem Description:

        Given an array of size N, generate the power set of the array.
        A set containing all of the possible subsets of an array is called a powerset.
        Solve using bitmasking technique.

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

    int subset_ct = (1 << n);

    for (int mask = 0; mask < subset_ct; mask++) {
        vector<int> subset;

        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0)
                subset.push_back(arr[i]);
        }

        power_set.push_back(subset);
    }

    for (auto vec : power_set) {
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}