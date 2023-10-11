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
 
ll IDEMPOTENT_VALUE = 0; 

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
	int query(int L, int R) {
		// Full Cover
		if(L <= lo && R >= hi) return sum; // Change
		
		// No cover
		if(L > hi || R < lo) return 0; // Change

		// Partial cover
		return left->query(L, R) + right->query(L, R); // Change
	}
};

void solve(){
    vint a;
    int n;
    cin >> n;
    a.reserve(n);
    
    segTreeNode* root = new segTreeNode(0, n-1);
	for(int _ = 0; _ < n; _++){
		cin >> a[_];
		root->update(_, a[_]);
	}
    cout << root->query(1,4) << endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    solve();
    return 0;
}