#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int ternarySearch(vector<int> &v, int n)
{
    int l = -1, r = n;

    while (r - l > 1) {
        int mid1 = (2*l + r) / 3; // mid1 = l + (r - l) / 3
        int mid2 = (l + 2*r) / 3; // mid2 = r - (r - l) / 3

        if (v[mid1] < 0 and v[mid2] < 0) {
          l = mid2;
        } else if (v[mid1] >= 0 and v[mid2] >= 0) {
          r = mid1;
        } else {
          l = mid1;
          r = mid2;
        }
    }

    return v[r];
}

int32_t main()
{
    file();

    /*
        Problem Description:
        Find the first non-negative number in an array of sorted integers in O(log3(n)) TC

        Constraints:
        1 <= N <= 1e7
    */

    int n;
    cin >> n;

    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    cout << ternarySearch(v, n) << endl;
}