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
ll MOD = 1e9+7;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int n;
vlong dp;
// ll func(int idx, bool start){
//     // cout << dp[idx][start] << endl;
//     // cout << idx << ' ' << start << endl;
//     if(idx>=n-1 and start) return 0;
//     if(idx>=n-1) return 1;
//     if(dp[idx][start]!=-1) return dp[idx][start];
    
//     if(start) {
//         dp[idx][start] = ((n-idx-1)*func(idx+1, false))%MOD;
//         return dp[idx][start];
//     }
//     dp[idx][start] = (func(idx+1, true) + (n-idx-1)*func(idx+1, false))%MOD;
//     return dp[idx][start];
// }

ll solve()
{
    // memset(dp, -1, sizeof(dp));
    cin >> n;
    return dp[n]%MOD;
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
    dp = vlong(1000001);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i <= 1000000; i++){
        dp[i] = ((i-1) * (dp[i-1]+dp[i-2]) )%(2*MOD);
    }
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve_print();
    }
    return 0;
}