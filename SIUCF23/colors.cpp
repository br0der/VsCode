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
 
int n;
vint colors;
vvint edges;
vint sizes;

set<int>* merge(set<int> *A, set<int> *B){
    if(A->size()>B->size()){
        swap(A, B);
    }
    for(int i : *A){
        B->insert(i);
    }
    return B;
}

set<int>* dfs(int idx, int par){
    set<int> *out = new set<int>();

    out->insert(colors[idx]);

    for(int next : edges[idx]){
        if(next==par) continue;

        set<int> *get = dfs(next, idx);

        out = merge(out, get);
    }

    sizes[idx] = out->size();

    return out;
}

void solve()
{
    cin >> n;
    colors = vint(n);
    for(int i = 0; i < n; i++){
        cin >> colors[i];
    }
    edges = vvint(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    sizes = vint(n);
    
    dfs(0, -1);
    for(int i = 0; i < n; i++){
        cout << sizes[i] << ' ';
    }
    // return sizes[0];
}
int main()
{
    fast_cin();
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    solve();
    return 0;
}