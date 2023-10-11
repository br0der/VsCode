// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvlong;
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds ;

struct segTreeNode {
    int lo, md, hi;
    int lazy = 0;
    int mx = 0;
    segTreeNode *left, *right;

    // Constructor
    segTreeNode(int L, int R) {
        lo = L, hi = R;
        md = (lo + hi) / 2;
        if(lo == hi) return;
        left = new segTreeNode(L, md);
        right = new segTreeNode(md+1, R);
    }

    // update sum for lazy prop
    void lazyUpdate(int dif) {
        lazy += dif;
        mx += dif;
    }

    // propagate function
    void prop() {
        if(!lazy) return;
        left->lazyUpdate(lazy);
        right->lazyUpdate(lazy);
        lazy = 0;
    }

    // Merge function: updates current node's sum
    // Mainly helpful for segTrees with intrecate merging
    void merge() {
        mx = max(left->mx, right->mx);
    }

    // Range update
    void update(int L, int R, int val) {

        // Full cover
        if(L <= lo && R >= hi) {
            // sum += val * (hi - lo + 1);
            mx+=val;
            lazy += val;
            return;
        }

        // No cover
        if(L > hi || R < lo) return;

        prop();

        left->update(L, R, val);
        right->update(L, R, val);

        merge();

        return;
    }

    // Range Query
    int query(int L, int R) {
        // Full Cover
        if(L <= lo && R >= hi) return mx;
        
        // No cover
        if(L > hi || R < lo) return 0;

        // Partial cover
        prop();

        return max(left->query(L, R), right->query(L, R));
    }
};

int solve()
{
    int n; cin >> n;
    vector<vector<int>> events;
    for(int i = 0; i < n; i++){
        int x, y, r;
        cin >> x >> y >> r;
        // x+=100000;
        // y+=100000;
        int centerline = y-x;
        events.push_back({centerline-r, -1, x+r+y+100000, x+y-r+100000}); // (line, top, bottom, increase/decrease)
        events.push_back({centerline+r, 1, x+r+y+100000, x+y-r+100000});
    }
    sort(all(events));
    segTreeNode *Node = new segTreeNode(0, 200000);
    int ans = 0;
    for(int i = 0; i < sz(events); i++){
        // cout << events[i][0] << ' ' << events[i][2] << ' ' << events[i][3] << ' ' << events[i][1] << endl;
        Node->update(events[i][3], events[i][2], -events[i][1]);
        // if(i!=sz(events)-1 and events[i+1][0]!=events[i][0]){
        ans = max(ans, Node->query(0, 200000));
        // }
    }
    return ans;
}
void solve_print()
{
    cout << solve() << endl;
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve_print();
    }
    return 0;
}