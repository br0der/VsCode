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
typedef vector<double> vdouble;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvlong;
typedef vector<vector<double>> vvdouble;
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb(x) (push_back(x))



ll solve()
{
    ll n; cin >> n;
    ll k; cin >> k;
    vint lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    if(lis[0]!=1) return 1;
    ll j = 1;
    ll iterations = 0;
    ll nxt = 1;
    while(iterations<k and j<n){
        nxt+=j;
        while(j<n and lis[j]<=nxt){
            j++;
            nxt++;
        }
        iterations++;
    }
    if(iterations==k) return nxt;
    // cout << k << ' ' << iterations << ' ' << n << ' ' << nxt << endl;
    return (k-iterations)*n + nxt;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        cout << solve() << endl;
    }
    return 0;
}