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

struct segTreeNode {
    int lo, md, hi;
    int sum = 0, lazy = 0; // Change
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
        sum += dif * (hi - lo + 1); 				// Change
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
        sum = left->sum + right->sum; 			// Change
    }
    // Range update
    void update(int L) {
        // Full cover
        if(L <= lo) {
            sum += (hi - lo + 1); 			// Change
            lazy += 1;
            return;
        }
        // No cover
        if(L > hi) return;
        prop();
        left->update(L);
        right->update(L);
        merge();
        return;
    }
    // Range Query
    int query(int p) {
        // Full Cover
        if(p == lo && p == hi) return sum; 			// Change
        // No cover
        if(p > hi || p < lo) return 0; 			// Change
        prop();
        if(p<=md) return left->query(p);
        else return right->query(p);
    }
};

vint lis;

void solve()
{
    int n; cin >> n;
    int q; cin >> q;
    lis = vint(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    segTreeNode st(1, n);
    vector<vector<pair<int, int> > > queries(n);
    for(int i = 0; i < q; i++){
        int idx; cin >> idx;
        int x; cin >> x;
        queries[idx-1].pb({i, x});
    }
    vector<bool> out(q, -1);
    for(int i = 0; i < n; i++){
        for(pair<int, int> pr: queries[i]){
            out[pr.first] = (st.query(pr.second)/pr.second) + 1 <= lis[i];
        }
        // for(int i = 1; i <= n; i++) cout << st.query(i) << ' ';
        // cout << ln;
        int lo = 1, hi = n, ans = -1;
        while (lo <= hi) {
            int mid = (lo+hi)/2; // K
            int monstersFaught = st.query(mid);
            int level = (monstersFaught/mid)+1;
            // cout << mid << ' ' << level << ln;
            if (level > lis[i]) { // ran away
                // cout << "higher" << ln;
                lo = mid+1;
            }
            else {
                ans = mid;
                hi = mid-1;
            }
        }
        // cout << ans << ln;
        if (ans!=-1) st.update(ans);
        
        
    }
    for(int i = 0; i < q; i++){
        if (out[i]) cout << "YES" << ln;
        else cout << "NO" << ln;
    }
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}