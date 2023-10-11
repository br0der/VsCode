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

double dp[301][301][301];

double func(int n1, int n2, int n3, int n){
    if(dp[n1][n2][n3]==-1){
        double total = n1+n2+n3;
        if(total==0){
            return 0;
        }
        double out = n/total;
        if(n1){
            out+=((double)n1/(double)total)*func(n1-1, n2, n3, n);
        }
        if(n2){
            out+=((double)n2/(double)total)*func(n1+1, n2-1, n3, n);
        }
        if(n3){
            out+=((double)n3/(double)total)*func(n1, n2+1, n3-1, n);
        }
        dp[n1][n2][n3] = out;
    }
    // cout << n1 << n2 << /n3 << dp[n1][n2][n3] << endl;
    return dp[n1][n2][n3];
}

double solve()
{
    int n;
    cin >> n;
    int nums[3];
    memset(nums, 0, sizeof(nums));
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        nums[temp-1]++;
    }
    memset(dp, -1.0, sizeof(dp));
    // cout << dp[0][0][0] << ' ' << nums[0] << ' ' << nums[1] << ' ' << nums[2] << endl;
    return func(nums[0], nums[1], nums[2], n);
}
void solve_print()
{
    cout << setprecision(10) << fixed << solve() << endl;
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