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
 
struct segTreeNode{
    int lo, md, hi;
	ll sum = 0;
    ll prefix[16], postfix[16];
    ll ans = 0;
	segTreeNode *left, *right;
	
	// Constructor
	segTreeNode(int L, int R) {
        prefix[0] = 1;
        postfix[0] = 1;
        for(int i = 1; i < 16; i++){
            prefix[i] = 0;
            postfix[i] = 0;
        }
		lo = L, hi = R;
		md = (lo + hi) / 2;
		if(lo == hi) return;
		left = new segTreeNode(L, md);
		right = new segTreeNode(md+1, R);
	}
	
	// Merge function: updates current node's sum
	// Mainly helpful for segTrees with intrecate merging
	void merge() {
        for(int i = 0; i < 16; i++) prefix[i] = 0;
        for(int i = 0; i < 16; i++) postfix[i] = 0;
        for(int i = 0; i < 16; i++){
            prefix[i] = left->prefix[i] + right->prefix[(left->sum)^(i)];
            postfix[i] = right->postfix[i] + left->postfix[(right->sum)^(i)];
        }
		sum = left->sum ^ right->sum;
	}
	
	// Point update
	void update(int idx, ll val) {
		if(lo == hi) {
            prefix[sum]--;
            postfix[sum]--;
			sum ^= val;
            prefix[sum]++;
            postfix[sum]++;
            if(sum==0){
                ans = 1;
            }
            else{
                ans = 0;
            }
			return;
		}
		if(idx <= md) left->update(idx, val);
		else right->update(idx, val);

		merge();
        ans = left->ans + right->ans;
        for(int i = 0; i < 16; i++){
            ans+=(left->postfix[i]*right->prefix[i]);
        }
        // ans = left->ans + right->ans + (left->postfix[0]*right->prefix[0]);
		return;
	}

	// Range Query
	ll query(int L, int R) {
		// Full Cover
		if(L <= lo && R >= hi) return ans;
		
		// No cover
		if(L > hi || R < lo) return 0;

		// Partial cover
		return left->query(L, R) + right->query(L, R);
	}
};

int solve()
{
    return 0;
}
void solve_print()
{
    cout << solve() << endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve_print();
    }
    return 0;
}