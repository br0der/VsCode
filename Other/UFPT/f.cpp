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

struct segTreeNode{
    int lo, md, hi;
	int sum = 0; // Change
	segTreeNode *left, *right;
	
	// Constructor
	segTreeNode(int L, int R) {
		lo = L, hi = R;
		md = (lo + hi) / 2;
		if(lo == hi) return;
		left = new segTreeNode(L, md);
		right = new segTreeNode(md+1, R);
	}
	
	// Merge function: updates current node's sum
	// Mainly helpful for segTrees with intrecate merging
	void merge() {
		sum = left->sum + right->sum; // Change
	}
	
	// Point update
	void update(int idx, int val) {
		if(lo == hi) {
			sum += val; // Change
			return;
		}

		if(idx <= md) left->update(idx, val);
		else right->update(idx, val);

		merge();

		return;
	}

	// Range Query
	ll query(int L, int R) {
		// Full Cover
		if(L <= lo && R >= hi) return sum; // Change
		
		// No cover
		if(L > hi || R < lo) return 0; // Change

		// Partial cover
		return left->query(L, R) + right->query(L, R); // Change
	}
};

void solve()
{
    int n; cin >> n;
    vint lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    segTreeNode *l = new segTreeNode(0, n), *r = new segTreeNode(0, n);
    vlong ans = vlong(n, -1);
    ll out = 0;
    for(int i = 0; i < n; i++){
        ans[i] = l->query(lis[i]+1, n);
        // cout << i << l->query(lis[i]+1, n) << ln;
        l->update(lis[i], 1);
    }
    for(int i = n-1; i >= 0; i--){
        out+=ans[i]*r->query(0, lis[i]-1);
        // cout << i << r->query(0, lis[i]-1) << ln;
        r->update(lis[i], 1);
    }
    cout << out << ln;
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