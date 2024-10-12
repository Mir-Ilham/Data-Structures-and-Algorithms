#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree< int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int main() {
    file();

    /*
        Windows setup
            1. Go to the directory where MinGW is installed.
            2. Navigate to \lib\gcc\mingw32\8.2.0\include\c++\ext\pb_ds\detail\resize_policy
            3. Rename “hash_standard_resize_policy_imp.hpp0000644” to “hash_standard_resize_policy_imp.hpp”

        Declaration
            ❖ Data type: change int to any other data type
            ❖ Multiset increasing order: less_equal
            ❖ Set increasing order: less
            ❖ Multiset decreasing order: greater_equal
            ❖ Set decreasing order: greater
            ❖ Example: ordered_set ost

        Methods
            ❖ Access element at ith position, returns iterator to it: *ost.find_by_order(i)
            ❖ Index of first occurrence of value: ost.order_of_key(value)

    */

    int n;
    cin >> n;

    ordered_set ost;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ost.insert(x);
    }

    cout << "order_of_key method calls:\n";
    cout << ost.order_of_key(2) << endl;
    cout << ost.order_of_key(56) << endl;
    cout << ost.order_of_key(14) << endl; // Returns array-end index if item not found

    cout << "find_by_order method calls:\n";
    cout << *ost.find_by_order(0) << endl;
    cout << *ost.find_by_order(8) << endl;
    cout << *ost.find_by_order(9) << endl;

    return 0;
}