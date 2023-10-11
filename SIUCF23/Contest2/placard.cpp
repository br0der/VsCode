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

struct segTreeNode {
    int lo, md, hi;
    ll mn = 0, lazy = 0;
    ll count;
    segTreeNode *left, *right;

    // Constructor
    segTreeNode(int L, int R) {
        lo = L, hi = R;
        md = (lo + hi) / 2;
        count = hi-lo+1;
        if(lo == hi) return;
        left = new segTreeNode(L, md);
        right = new segTreeNode(md+1, R);
    }

    // update sum for lazy prop
    void lazyUpdate(ll dif) {
        lazy += dif;
        mn += dif;
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
        mn = min(left->mn, right->mn);
        
        if(left->mn<right->mn) count = left->count;
        if(left->mn>right->mn) count = right->count;
        if(left->mn==right->mn) count = left->count + right->count;
    }

    // Range update
    void update(int L, int R, int val) {

        // Full cover
        if(L <= lo && R >= hi) {
            mn+=val;
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
    ll query(int L, int R) {
        // Full Cover
        if(L <= lo && R >= hi) return mn==0 ? count : 0;
        
        // No cover
        if(L > hi || R < lo) return 0;

        // Partial cover
        prop();

        return left->query(L, R) + right->query(L, R);
    }
};

ll solve()
{
    int t;
    cin >> t;
    ll l;
    cin >> l;
    ll h;
    cin >> h;
    ll lp;
    cin >> lp;
    ll hp;
    cin >> hp;
    vector<vector<pair<int,int>>> adds;
    vector<vector<pair<int,int>>> subt;
    for(int i = 0; i < l; i++){
        vector<pair<int, int>> temp;
        adds.push_back(temp);
        vector<pair<int,int>> temp2;
        subt.push_back(temp2);
    }
    for(int i = 0; i < t; i++){
        ll left;
        cin >> left;
        ll bottom;
        cin >> bottom;
        ll li;
        cin >> li;
        ll hi;
        cin >> hi;
        bottom = h-bottom-1;
        ll top = bottom-hi+1;
        ll right = left+li-1;
        // cout << left << ' ' << right << ' ' << top << ' ' << bottom << endl;
        adds[max((ll)0, left-lp+1)].push_back(make_pair(top-hp+1, bottom));
        if(right+1<l){
            subt[right+1].push_back(make_pair(top-hp+1, bottom));
        }
    }

    ll ans = 0;
    segTreeNode *root = new segTreeNode(0, h-1);
    for(int i = 0; i < l-lp+1; i++){
        for(auto it : subt[i]){
            root->update(max(0,it.first), it.second, -1);
        }
        for(auto it : adds[i]){
            root->update(max(0,it.first), it.second, 1);
        }
        // cout << root->count << endl;
        ans += root->query(0, h-hp);
    }
    return ans;
}
void solve_print()
{
    // cout << 1 << endl;

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