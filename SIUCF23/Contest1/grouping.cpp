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
 

void solve()
{
    int n;
    cin >> n;
    map<ll, ll> cows;
    ll total = 0;
    for(int i = 0; i < n; i++){
       ll f;
       cin >> f;
       ll m;
       cin >> m;
       cows[m]+=f;
       total+=f;
    }
    ll lower = ceil((3.0/10.0)*total);
    ll A = 0;
    ll a = 0;
    for(auto i = cows.begin(); i!=cows.end(); i++){
        A+=i->second;
        a = i->first;
        if(A >= lower){
            
            break;
        }
    }
    ll C = 0;
    ll b = 0;
    for(auto i = cows.crbegin(); i!=cows.crend(); i++){
        C+=i->second;
        b = i->first;
        if(C >= lower){
            break;
        }
    }
    if(total - (A + C) < lower){
        cout << -1 << endl;
    }
    else{
        cout << a << ' ' << b-1 << endl;
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}