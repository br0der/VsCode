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

ll dp[100001];
vint lis;
ll func(int idx){
    if(idx>=sz(lis)-1) return 0;
    if(idx==sz(lis)-2) return abs(lis[idx]-lis[idx+1]);
    if(dp[idx]==-1){
        dp[idx] = func(idx+1)+abs(lis[idx]-lis[idx+1]);
        dp[idx] = min(dp[idx], func(idx+2)+abs(lis[idx]-lis[idx+2]));
    }
    return dp[idx];
}

ll solve()
{
    int n;
    cin >> n;
    lis = vint(n);
    for(int _ = 0; _ < n; _++) cin >> lis[_];
    memset(dp, -1, sizeof(dp));
    return func(0);
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
    solve_print();
    return 0;
}