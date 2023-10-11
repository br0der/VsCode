//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<double> vdouble;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvlong;
typedef vector<vector<double>> vvdouble;
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

struct segTreeNode {
    int lo, md, hi;
    int sum = 0, lazy = 0;
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
        sum += dif * (hi - lo + 1);
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
        sum = left->sum + right->sum;
    }

    // Range update
    void update(int L, int R, int val) {

        // Full cover
        if(L <= lo && R >= hi) {
            sum += val * (hi - lo + 1);
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
        if(L <= lo && R >= hi) return sum;
        
        // No cover
        if(L > hi || R < lo) return 0;

        // Partial cover
        prop();

        return left->query(L, R) + right->query(L, R);
    }
};

void solve()
{
    int n; cin >> n;
    vint temp(n); for(int _ = 0; _ < n; _++) cin >> temp[_];
    vector<pair<int, int>> lis(n);
    for(int i = 0; i < n; i++){
        while(temp[i]%2==0) lis[i].first--, temp[i]/=2;
        lis[i].second = i;
    }
    sort(all(lis));
    segTreeNode *st = new segTreeNode(0, n-1);
    for(int i = 0; i < n; i++){
        st->update(i, i, i);
    }
    ll out = 0;
    for(int i = 0; i < n; i++){
        out+=st->query(lis[i].second, lis[i].second);
        st->update(lis[i].second, n-1, -1);
    }
    cout << out << ln;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}