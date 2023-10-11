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
const char ln = '\n';

vint depth;
vvint kthPar;

int getLca(int n1, int n2){
    if(depth[n2]>depth[n1]) swap(n1, n2);
    if(depth[n1]>depth[n2]){
        int diff = depth[n1]-depth[n2];
        for(int i = 0; i < 20; i++){
            // cout << n1 << ' ' << n2 << ln;
            if(diff&(1<<i)){
                n1 = kthPar[n1][i];
            }
        }
    }
    if(n1==n2) return n1;
    // cout << n1 << ' ' << n2 << ln;
    for(int i = 17; i >= 0; i--){
        if(kthPar[n1][i]==-1) continue;
        if(kthPar[n1][i]!=kthPar[n2][i]){
            n1 = kthPar[n1][i];
            n2 = kthPar[n2][i];
        }
    }
    n1 = kthPar[n1][0];
    return n1;
}

void solve()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<set<int>> adj(n);
    
    for(int i = 0; i < n-1; i++){
        int s, e;
        cin >> s >> e;
        adj[s-1].insert(e-1);
        adj[e-1].insert(s-1);
    }
    
    depth = vint(n, -1);
    kthPar = vvint(n, vint(18, -1));
    queue<int> que;
    vector<bool> visited(n, false);
    que.push(0);
    depth[0] = 0;
    visited[0] = true;
    
    while(!que.empty()){
        int curr = que.front();
        que.pop();
        for(int node : adj[curr]){
            if(visited[node]) continue;
            visited[node] = true;
            que.push(node);
            depth[node] = depth[curr]+1;
            kthPar[node][0] = curr;
            int i = 1;
            while(i<18 and kthPar[kthPar[node][i-1]][i-1]!=-1){
                kthPar[node][i] = kthPar[kthPar[node][i-1]][i-1];
                i++;
            }
        }
    }
    // for(int i = 0; i < n; i++) cout << depth[i] << endl;
    // cout << endl;
    for(int i = 0; i < q; i++){
        int s, e;
        cin >> s >> e;
        int n3 = getLca(s-1, e-1);
        // cout << n3 << ' ' << depth[s-1] << ' ' << depth[e-1] << ' ' << depth[n3] << ln;
        cout << depth[s-1] + depth[e-1] - 2*depth[n3] << ln;
    }

    return;
}
int main()
{
    // cin.tie(0)->sync_with_stdio(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif

    solve();
    return 0;
}