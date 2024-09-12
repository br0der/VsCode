//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<double> vdouble;
typedef vector<vector<int> > vvint;
typedef vector<vector<ll> > vvlong;
typedef vector<vector<double> > vvdouble;
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

vint pars;
vector<set<int> > children;
vint maxBelow;
vint depth;
vvint jumps;

int dfs(int node, int d) {
    maxBelow[node] = node;
    depth[node] = d;
    for (int child : children[node]) {
        maxBelow[node] = max(maxBelow[node], dfs(child, d+1));
    }
    return maxBelow[node];
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    if (depth[a] > depth[b]) {
        int dist = depth[a]-depth[b];
        for(int i = 0; i < 20; i++){
            if (dist&(1<<i)) a = jumps[a][i];
        }
    }
    if (a==b) return a;
    for(int i = 19; i >= 0; i--){
        if (jumps[a][i]==jumps[b][i]) continue;
        a = jumps[a][i];
        b = jumps[b][i];
    }
    return jumps[a][0];
}

void solve()
{
    int n; cin >> n;
    ll w; cin >> w;
    depth = vint(n);
    pars = vint(n-1); for(int _ = 0; _ < n-1; _++) cin >> pars[_];
    children = vector<set<int> >(n);
    maxBelow = vint(n, -1);
    jumps = vvint(n, vint(20, -1));
    jumps[0][0] = 0;
    for(int i = 0; i < n-1; i++){
        pars[i]--;
        children[pars[i]].insert(i+1);
        jumps[i+1][0] = pars[i];
    }
    dfs(0, 0);
    // for(int i = 0; i < sz(maxBelow); i++) cout << maxBelow[i] << ' ';
    // cout << ln;
    
    for(int i = 0; i < n; i++){
        for(int pow = 1; pow < 20; pow++){
            jumps[i][pow] = jumps[jumps[i][pow-1]][pow-1];
        }
    }
    vint pathDist(n);

    for(int i = 0; i < n; i++){
        // cout << lca(i, (i+1)%n)+1 << ln;
        int l = lca(i, (i+1)%n);
        // cout << depth[i] << ' ' << depth[i+1] << ' ' << depth[l] << ' ' << abs(depth[i]-depth[l]) + abs(depth[i+1]-depth[l]) << ln;
        pathDist[i] = abs(depth[i]-depth[l]) + abs(depth[(i+1)%n]-depth[l]);
    }
    // for(int i = 0; i < sz(pathDist); i++) cout << pathDist[i] << ' ';
    // cout << ln;
    ll fixed = 0;
    ll paths = n;
    // for(int i = 0; i < sz(pathDist); i++) cout << pathDist[i] << ' ';
    // cout << ln;
    for(int i = 0; i < n-1; i++){

        int x; cin >> x;
        ll tx; cin >> tx;
        x--;
        // cout << lca(x, (x+1)%n) << ' ' << lca(x, (x+n-1)%n) << ln;
        
        
        if (depth[lca(x, (x+n-1)%n)] < depth[x]) {pathDist[(x+n-1)%n]--; if (pathDist[(x+n-1)%n]==0) paths--;}
        x = maxBelow[x];
        if (depth[lca(x, (x+1)%n)] < depth[x]) {pathDist[x]--; if (pathDist[x]==0) paths--;}
        
        
        fixed+=2*tx;
        w-=tx;
        // for(int i = 0; i < sz(pathDist); i++) cout << pathDist[i] << ' ';
        // cout << ln;
        // cout << paths << ln;
        cout << w*paths + fixed << ' ';
    }
    cout << ln;
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}