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
 

int solve()
{
    ll n, m, h;
    cin >> n >> m >> h;
    vvlong rankings;
    for (int i = 0; i < n; i++)
    {
        vint problems;
        for(int _ = 0; _ < n; _++) cin >> problems[_];
        
        sort(all(problems));
        int idx = 0;
        ll len = 0;
        ll penalty = 0;
        int solved = 0;
        while(idx<m and len+problems[idx] <= h){
            len+=problems[idx];
            solved++;
            penalty+=len;
            idx++;
        }
        rankings.push_back({solved, -penalty, -i});
    }
    sort(all(rankings));
    int out = -1;
    for (int i = n-1; i >= 0; i--)
    {
        
        // cout << rankings[i][0] << ' ' << rankings[i][1] << ' ' << rankings[i][2] << "." << endl;
        if(rankings[i][2]==0){
            out = n-i;
        }
    }
    return out;
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