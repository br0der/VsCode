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
typedef double ld;
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

// bool contains[256];
// int dp[256][256];
// int func(int idx, int mask){
//     if(idx >= 256){
//         return mask;
//     }
//     // cout << "got here " << idx << " " << contains[idx] << endl;

//     if(!contains[idx]){
//         return func(idx+1, mask);
//     }

//     if(dp[idx][mask]!=-1){
//         return dp[idx][mask];
//     }
//     dp[idx][mask] = max(func(idx+1, mask), func(idx+2, mask^idx));
//     return dp[idx][mask];
// }

vint nums;
vint xSum;
int dp[100000][256];
int func(int idx, int total){
    // cout << idx << ' ' << total << ' ' << dp[idx][total] << endl;
    if(idx==sz(nums)){
        return total;
    }
    if(dp[idx][total]==-1){
        dp[idx][total] = max(total, func(idx+1, total^nums[idx]));
        if(total==0){
            dp[idx][total] = max(dp[idx][total], func(idx+1, total));
        }
    }
    
    return dp[idx][total];
}

int solve()
{
    int n;
    cin >> n;
    nums.clear();
    for (size_t i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < 256; j++)
        {
            dp[i][j] = -1;
        }
    }
    return func(0, 0);
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