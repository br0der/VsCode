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
 
vlong parent, sze;

ll get(ll a){
    if (parent[a] != a){
        parent[a] = get(parent[a]);
    }
    return parent[a];
}

void merge(ll a, ll b){

    a = get(a);
    b = get(b);
    if(a==b) return;
    if(sze[a] > sze[b]){
        swap(a, b);
    }
    parent[a] = b; 
    sze[b] += sze[a];
}

void solve()
{
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    parent = vlong(n*m);
    for(ll i = 0; i < n*m; i++) parent[i] = i;
    sze = vlong(n*m);
    for(ll i = 0; i < n*m; i++) sze[i] = 1;
    vector<string> grid(n);
    for(ll i = 0; i < n; i++){
        cin >> grid[i];
    }
    pair<ll, ll> offs[] = {make_pair(0,1), make_pair(0,-1), make_pair(1, 0), make_pair(-1, 0)};
    for(ll row = 0; row < n; row++){
        for(ll col = 0; col < m; col++){
            if(grid[row][col]=='#') continue;
            ll key = m*row + col;
            for(pair<ll, ll> off : offs){
                ll newRow = row+off.first, newCol = col+off.second;
                if(newRow<0 or newRow>=n or newCol<0 or newCol>=m) continue;
                if(grid[newRow][newCol]=='#') continue;
                // cout << newRow << ' ' << newCol << ' ' <<  key << endl;
                merge(m*newRow + newCol, key);
            }
        }
    }
    ll out = 1;
    for(ll row = 0; row < n; row++){
        for(ll col = 0; col < m; col++){
            ll key = m*row + col;
            if(grid[row][col]=='.'){
                out = max(out, sze[get(key)]);
                continue;
            }
            ll temp = 1;
            set<ll> added;
            for(pair<ll, ll> off : offs){
                ll newRow = row+off.first, newCol = col+off.second;
                // cout << newRow << ' ' << newCol << endl;
                if(newRow<0 or newRow>=n or newCol<0 or newCol>=m) continue;
                if(grid[newRow][newCol]=='#') continue;
                // cout << newRow << ' ' << newCol << endl;
                ll key1 = m*newRow + newCol;
                if(added.count(get(key1))==0){
                    temp += sze[get(key1)];
                    added.insert(get(key1));
                }
            }
            out = max(out, temp);
        }
    }
    // for(ll i = 0; i < n*m; i++){
    //     cout << parent[i] << ' ';
    // }
    // cout << endl;
    // for(ll i = 0; i < n*m; i++){
    //     cout << sze[i] << ' ';
    // }
    cout << out << endl;
}
int main()
{
    fast_cin();
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    ll t;
    cin >> t;
    for(ll it=1;it<=t;it++) {
        solve();
    }
    return 0;
}