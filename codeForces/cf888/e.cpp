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
    int k; cin >> k;
    vlong costs(n); for(int _ = 0; _ < n; _++) cin >> costs[_];
    vint inDegree(n, 0);
    vlong childrenCosts(n, LLONG_MAX);
    queue<ll> q;
    set<ll> supply; 
    for(int _ = 0; _ < k; _++){
        ll temp; cin >> temp;
        supply.insert(temp-1);
        // q.push(temp-1);
    }
    vvint pars = vvint(n, vint());
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        inDegree[i]=m;
        if(m!=0){
            childrenCosts[i] = 0;
        }
        for(int j = 0; j < m; j++){
            int temp; cin >> temp;
            pars[temp-1].push_back(i);
        }
    }
    for(int i = 0; i < n; i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    
    while(sz(q)>0){
        ll curr = q.front();
        q.pop();
        if(supply.count(curr)){
            costs[curr] = 0;
            for(ll parent : pars[curr]){
                inDegree[parent]--;
                if(inDegree[parent]==0) q.push(parent);
            }
            continue;
        }
        costs[curr] = min(costs[curr], childrenCosts[curr]);
        for(ll parent : pars[curr]){
            childrenCosts[parent]+=costs[curr];
            inDegree[parent]--;
            if(inDegree[parent]==0) q.push(parent);
        }
    }
    for(int i = 0; i < n; i++){
        cout << costs[i] << ' ';
    }
    cout << endl;
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