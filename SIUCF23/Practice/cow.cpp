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

int solve()
{
    int lines; cin >> lines;
    vvlong horiz, vert;
    for(int i = 0; i < lines; i++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1==x2){
            vert.push_back({x1, y1, y2});
        }
        else{
            horiz.push_back({y1, x1, x2});
        }
    }
    FFA *fl = new FFA(lines+2);
    for(int i = 0; i < sz(horiz); i++){
        fl->insertEdge(lines, i, 1);
    }
    for(int i = 0; i < sz(vert); i++){
        fl->insertEdge(i+sz(horiz), lines+1, 1);
    }
    int edges = 0;
    for(int i = 0; i < sz(horiz); i++){
        for(int j = 0; j < sz(vert); j++){
            if( vert[j][0]<=horiz[i][2] and 
                vert[j][0]>=horiz[i][1] and
                vert[j][1]<=horiz[i][0] and 
                vert[j][2]>=horiz[i][0])
            {
                fl->insertEdge(i, j+sz(horiz), 1);
                edges++;
            }
        }
    }
    return lines - fl->calc(lines, lines+1);
}
void solve_print()
{
    cout << solve() << endl;
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
        solve_print();
    }
    return 0;
}