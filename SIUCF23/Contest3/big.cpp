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
ll MOD = 1000000007;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
vlong mods;

struct segTreeNode{
    int lo, md, hi;
	ll sum = 0;
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
        // cout << mods[right->lo-left->hi] << endl;
		sum = (left->sum*mods[hi - left->hi] + right->sum)%MOD;
	}
	
	// Point update
	void update(int idx, int val) {
		if(idx<lo or idx>hi) return;
		if(lo == hi) {
			sum = val;
            sum%=MOD;
			return;
		}

		if(idx <= md) left->update(idx, val);
		else right->update(idx, val);

		merge();
        // cout << left->sum << ' ' << right->sum << ' ' << sum << endl;
		return;
	}

	// Range Query
	ll query(int L, int R) {
		// Full Cover
		if(L <= lo && R >= hi) return sum;
		
		// No cover
		if(L > hi || R < lo) return 0;

		// Partial cover
		// cout << left->query(L, R) << ' ' << right->query(L, R) << endl;
		return (left->query(L, R)*mods[max(0,min(R, right->hi)-left->hi)] + right->query(L, R))%MOD;
	}
};

void solve()
{
    
    string big = "";
    cin >> big;
    segTreeNode *root = new segTreeNode(0, sz(big)-1);
    for(int i = 0; i < sz(big); i++){
        root->update(i, big[i]-'0');
    }
	// for(int i = 1; i < sz(big); i++){
	// 	cout << root->query(0, i) << endl;
	// }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
		int type;
		cin >> type;
		int idx1;
		cin >> idx1;
		int idx2;
		cin >> idx2;
		if(type==1){
			cout << root->query(idx1-1, idx2-1) << endl;
		}
		else{
			root->update(idx1-1, idx2);
		}
    }
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    
    ll num = 1;
    for(int i = 0; i <= int(1e5); i++){
        mods.push_back(num);
        num*=10;
        num%=MOD;
    }
    ll t;
    cin >> t;
    
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}