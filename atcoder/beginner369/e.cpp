//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>

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


void solve()
{
    int n; cin >> n;
    int m; cin >> m;
    vvlong bridges;
    vvlong adj(n, vlong(n, (2e18)));
    for(int i = 0; i < n; i++){
        adj[i][i]=0;
    }
    for(int i = 0; i < m; i++){
        int a; cin >> a;
        int b; cin >> b;
        ll t; cin >> t;
        
        bridges.pb({a-1, b-1,t});
        adj[a-1][b-1] = min(adj[a-1][b-1], t);
        adj[b-1][a-1] = min(adj[b-1][a-1], t);
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int k; cin >> k;

        vint b(k); 
        for(int j = 0; j < k; j++){
            cin >> b[j];
            b[j]--;
        }
        ll best = INF;
        do {
            for(int key = 0; key < 1<<k; key++){
                ll total = 0;
                int last = 0;
                for(int j = 0; j < k; j++){
                    vlong bridge = bridges[b[j]];
                    if (key&1<<j) total+=adj[last][bridge[0]], last = bridge[1];
                    else total+=adj[last][bridge[1]], last = bridge[0];
                    total+=bridge[2];
                }
                total+=adj[last][n-1];
                // cout << total << ln;
                best = min(best, total);
            }
            
        } while(next_permutation(all(b)));
        cout << best << ln;
    }
    
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}