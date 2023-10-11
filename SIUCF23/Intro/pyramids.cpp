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

vint nums;
int dp[400][400][401];
int func(int i, int j, int last){
    if(dp[i][j][last]==-1){
        if (i>=j-1) return 1;
        int out = func(i+1, j, last);
        for (int idx = j; idx>=i+1; idx--){
            // cout << i << ' ' << idx << endl;
            if(nums[idx]==nums[i] and nums[idx]>last){
                out = max(out, func(i+1, idx-1, nums[i])+2);
                break;
            }
        }
        dp[i][j][last] = out;
    }
    return dp[i][j][last];
}
int solve()
{
    int n;
    cin >> n;
    nums.clear();
    nums.reserve(n);
    memset(dp, -1, 400*400*401);
    for(int _ = 0; _ < n; _++) cin >> nums[_];
    int out = func(0, n-1, 0);
    return out < 3 ? 0 : out;
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
        cout << solve() << endl;
    }
    // cout << "Sad" << endl;
    return 0;
}