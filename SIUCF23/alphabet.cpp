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

struct FFA{
    vector<vector<int>> residual;
    int n;
    FFA(int nodes){
        n = nodes;
        residual = vector<vector<int>>(n, vector<int>(n));
    }

    void insertEdge(int u, int v, int w){
        residual[u][v]+=w;
    }
    
    vector<bool> seen;

    int dfs(int cur, int t, int flow){
        if(cur==t) return flow;
        for(int nxt = 0; nxt < n; nxt++){
            if(residual[cur][nxt]==0 || seen[nxt]) continue;
            seen[nxt] = true;
            int f = dfs(nxt, t, min(flow, residual[cur][nxt]));
            if(f!=0){
                residual[cur][nxt]-=f;
                residual[nxt][cur]+=f;
                return f;
            }
        }
        return 0;
    }

    int calc(int s, int t){
        int flow = 0;
        while(true){
            seen = vector<bool>(n);
            seen[s] = true;
            int f = dfs(s, t, INT_MAX);
            if(f==0) break;
            flow+=f;
        }
        return flow;
    }
};

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    FFA *fl = new FFA(54);
    
    for(auto elem : s1) fl->insertEdge(52, elem-'a', 1);
    for(auto elem : s2) fl->insertEdge(elem-'a'+26, 53, 1);
    int i = 0;
    while(i<sz(s1)){
        int j = 0;
        while(j<sz(s2)){
            if(abs(s2[j]-s1[i])>=3){
                // cout << s2[j] << ' ' << s1[i] << endl;
                fl->insertEdge(s1[i]-'a', s2[j]-'a'+26, 1);
            }
            j++;
        }
        i++;
    }
    // start, end, weight
    cout << fl->calc(52, 53) << endl;
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