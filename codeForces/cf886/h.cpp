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



bool solve()
{
    int n; cin >> n;
    int c; cin >> c;
    // cout << n << ' ' << c << endl;
    vlong locations(n, LLONG_MAX);
    vector<vector<pair<int, int>>> dependencies(n, vector<pair<int, int>>());
    for(int i = 0; i < c; i++){
        int a; cin >> a;
        int b; cin >> b;
        int d; cin >> d;
        dependencies[a-1].push_back({b-1,-d});
        dependencies[b-1].push_back({a-1,d});
    }
    // vector<bool> visited(n, false);
    for(int i = 0; i < n; i++){
        if(locations[i]!=LLONG_MAX) continue;
        locations[i] = 0;
        queue<int> q;
        q.push(i);
        while(sz(q)>0){
            int curr = q.front();
            // cout << curr << endl;
            q.pop();
            for(int i = 0; i < sz(dependencies[curr]); i++){
                int nxtIdx = dependencies[curr][i].first;
                int dist = dependencies[curr][i].second;
                if(locations[nxtIdx]!=LLONG_MAX){
                    if(locations[nxtIdx]!=locations[curr]+dist) return false;
                }
                else{
                    locations[nxtIdx] = locations[curr]+dist;
                    q.push(nxtIdx);
                }
            }
        }
    }
    return true;
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
        if(solve()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}