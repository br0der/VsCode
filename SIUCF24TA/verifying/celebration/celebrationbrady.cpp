//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<double> vdouble;
typedef vector<vector<int> > vvint;
typedef vector<vector<ll> > vvlong;
typedef vector<vector<double> > vvdouble;
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

// Written by Brady Aber
// UCF SI Camp 2024
// 7/16/24
// celebration.cpp

struct segTreeNode{
    int lo, md, hi;
    int sum ;
    segTreeNode *left, *right;
    segTreeNode(int L, int R) {
        sum = 0;
        lo = L, hi = R;
        md = (lo + hi) / 2;
        if(lo == hi) return;
        left = new segTreeNode(L, md);
        right = new segTreeNode(md+1, R);
    }
    void merge() {
        sum = left->sum + right->sum;
    }
    // Point update
    void update(int idx, int val) {
        if(lo == hi) {
            sum += val; 
            return;
        }
        if(idx <= md) left->update(idx, val);
        else right->update(idx, val);
        merge();
        return;
    }
    // Range Query
    int query(int L, int R) {
        // Full Cover
        if(L <= lo && R >= hi) return sum;
        // No cover
        if(L > hi || R < lo) return 0;
        // Partial cover
        return left->query(L, R) + right->query(L, R);
    }
};


void solve()
{
    int n; cin >> n;
    int m; cin >> m;
    int q; cin >> q;
    assert(1 <= n && n <= 100000);
    assert(1 <= m && m <= 100000);
    assert(1 <= q && q <= 100000);
    vint vals(n); for(int _ = 0; _ < n; _++) cin >> vals[_];
    segTreeNode st(0, m-1);
    for(int i = 0; i < n; i++){
        assert(1 <= vals[i] && vals[i] <= m);
        vals[i]--;
        st.update(vals[i], 1);
    }

    // We can solve this using a segment tree, where a range query from (a, b) represents
    // how many reels are showing the range (a, b). Our only problem is that if we shift 
    // all reels, its hard to rotate a segment tree.

    // Lets keep track of our rotations, and not let the segment tree know when we rotate all of them.
    int allRotations = 0;

    for(int i = 0; i < q; i++){
        int type; cin >> type;
        if (type == 1) {
            
            int idx; cin >> idx;
            idx--;
            int shift; cin >> shift;
            assert(1 <= shift && shift <= 1000000000);
            // Removing what it was showing before,
            st.update(vals[idx], -1);

            // shift it,
            vals[idx]+=shift;
            vals[idx]%=m;

            // and update what it is showing now.
            st.update(vals[idx], 1);
        }
        else if (type == 2) {
            // Add to our "total shift" variable.
            int shift; cin >> shift;
            assert(1 <= shift && shift <= 1000000000);
            allRotations+=shift;
            allRotations%=m;
        }
        else if (type == 3) {
            int a; cin >> a;
            int b; cin >> b;
            assert(1 <= a && a <= m);
            assert(1 <= b && b <= m);
            a--;
            b--;
            // Account for the global shift
            a += m - allRotations;
            b += m - allRotations;
            a%=m;
            b%=m;
            // If b is to the left of a, we need to loop around.
            // ---b......a----
            if (b < a) {
                cout << st.query(a, m-1) + st.query(0, b) << ln;
            }
            // Normal case
            // ....a-----b....
            else {
                cout << st.query(a, b) << ln;
            }
        }
        else {
            // Impossible case
            assert(1==0);
        }
    }
}
int main()
{
    fast_cin();
    ll t; cin >> t;
    assert(1 <= t && t <= 10);
    while(t--) solve();
    return 0;
}