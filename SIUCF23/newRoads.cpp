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
 
int par[200000];
pair<int, int> edges[200000];
int ans[200000];
set<int>* qIdxs[200000];

int get(int a){
    if (par[a]!=a){
        par[a] = get(par[a]);
    }
    return par[a];
}

void merge(set<int> &a, set<int> &b, int step){
    vint er;

    for(int qi : a){
        if(b.count(qi)){
            ans[qi] = step;
            er.push_back(qi);
            
        }
        else b.insert(qi);
    }
    for(int x:er) b.erase(x);
}

void solve()
{
    int n, m, k; cin >> n >> m >> k;
    
    for(int i = 0; i<n; i++) par[i] = i;
    for(int i = 0; i < n; i++){
        ans[i] = -1;
    }

    for(int i = 0; i < n; i++){
        qIdxs[i] = new set<int>;
    }

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        edges[i] = {a-1, b-1};
    }
    
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        if(a==b) ans[i] = 0;
        else{
            qIdxs[a-1]->insert(i);
            qIdxs[b-1]->insert(i);
        }
    }

    for(int i = 0; i < m; i++){
        int a = get(edges[i].first), b = get(edges[i].second);
        if(qIdxs[a]->size()>qIdxs[b]->size()){
            swap(a, b);
        }
        par[a] = b;
        merge(*qIdxs[a], *qIdxs[b], i+1);
    }
    
    for(int i = 0; i < k; i++){
        cout << ans[i] << endl;
    }
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    solve();
    return 0;
}