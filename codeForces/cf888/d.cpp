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



void solve()
{
    int n; cin >> n;
    vlong lis(n-1); for(int _ = 0; _ < n-1; _++) cin >> lis[_];
    vlong diffs(n+1, 0);
    ll duplicate = -1;
    ll last = 0;
    for(int i = 0; i < n-1; i++){
        if(lis[i]-last>(2*n+1)){
            cout << "NO" << endl;
            return;
        }
        if((lis[i]-last)>n or diffs[lis[i]-last]==1){
            if(duplicate!=-1){
                cout << "NO" << endl;
                return;
            }
            duplicate = lis[i]-last;
        }
        else{
            diffs[lis[i]-last]++;
        }
        last = lis[i];
    }
    vlong missing;
    for(ll i = 1; i <= n; i++){
        if(diffs[i]==0){
            missing.push_back(i);
        }
    }
    if(sz(missing)>2){
        cout << "NO" << endl;
        return;
    }
    if(sz(missing)==1){
        cout << "YES" << endl;
        return;
    }
    if(duplicate==missing[0]+missing[1]){
        cout << "YES" << endl;
        return;
    }
    else{
        cout << "NO" << endl;
        return;
    }
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
        solve();
    }
    return 0;
}