// #include<debugger.h>
 
#include<bits/stdc++.h>
using namespace std;
 
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
 
#define int long long
// typedef long long ll;
// typedef tree< int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
#define endl '\n'
#define mem(a,b) memset(a, b, sizeof(a))
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
 
#define MOD 1000000007
const double PI = acos(-1);
const double eps = 1e-9;

const int MX = 2e5 + 10; 
int seg[MX*4], lazy[MX*4], a[MX]; 
 
void init(int id, int low, int high) { 
    if (low == high) { 
        seg[id] = a[low]; 
        return; 
    } 
    int mid = (low + high) / 2; 
    init(id*2, low, mid); 
    init(id*2+1, mid+1, high); 
 
    seg[id] = seg[id*2] + seg[id*2+1]; 
} 
 
int query(int id, int low, int high, int l, int r) { 
    if (low > r || high < l) return 0; 
 
    if (low >= l and high <= r) { 
        return seg[id]; 
    } 
 
    int mid = (low + high) / 2; 
    int left = query(id*2, low, mid, l, r); 
    int right = query(id*2+1, mid+1, high, l, r); 
 
    return left + right; 
} 
 
void update(int id, int low, int high, int i, int val) { 
    if (low > i || high < i) return; 
 
    if (low == i and high == i) { 
        seg[id] = val; 
        return; 
    } 
 
    int mid = (low + high) / 2; 
    update(id*2, low, mid, i, val); 
    update(id*2+1, mid+1, high, i, val); 
 
    seg[id] = seg[id*2] + seg[id*2+1]; 
} 

void rangeUpdate(int id, int low, int high, int l, int r, int val) {
    if (lazy[id] != 0) {
        seg[id] += (high - low + 1) * lazy[id];
        if (high != low) {
            lazy[2*id] += lazy[id];
            lazy[2*id + 1] += lazy[id];
        }
        lazy[id] = 0;
    }

    if (r < low or l > high or low > high) return;

    if (l <= low and high <= r) {
        seg[id] += (high - low + 1) * val;
        if (low != high) {
            lazy[2*id] += val;
            lazy[2*id + 1] += val;
        }
        return;
    }

    int mid = (low + high) / 2; 
    rangeUpdate(id*2, low, mid, l, r, val); 
    rangeUpdate(id*2+1, mid+1, high, l, r, val); 
 
    seg[id] = seg[id*2] + seg[id*2+1]; 
}

int queryLazy(int id, int low, int high, int l, int r) {
    if (lazy[id] != 0) {
        seg[id] += (high - low + 1) * lazy[id];
        if (high != low) {
            lazy[2*id] += lazy[id];
            lazy[2*id + 1] += lazy[id];
        }
        lazy[id] = 0;
    }

    if (r < low or l > high or low > high) return 0;

    if (low >= l and high <= r)
        return seg[id];

    int mid = (low + high) / 2;
    int left = queryLazy(id*2, low, mid, l, r); 
    int right = queryLazy(id*2+1, mid+1, high, l, r); 

    return left + right;
}

void solve(int ti)
{   
    mem(lazy, 0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    init(1, 1, n);

    while (q--) {
        int type, x, y, val;
        cin >> type;
        
        if (type == 2) {
            cin >> x >> y;
            cout << queryLazy(1, 1, n, x, y) << endl;
        } else {
            cin >> x >> y >> val;
            rangeUpdate(1, 1, n, x, y, val);
        }
    }
}
    
int tc = 0;
 
int32_t main()
{   

    
    optimize();
    // file();     
    if(tc){int t;cin>>t;for(int i=1;i<=t;i++)solve(i);} 
    else solve(1);
    return 0;
}