//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>
#include <queue>

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

int n;
vint parents;
vint subSz;
vint subD;
vvint adj;
int mxD;
int lastD;
int subtr(int curr) {
    int out = 1;
    int currMx = 0;
    for(int i = 0; i < sz(adj[curr]); i++){
        if(adj[curr][i]==parents[curr]) continue;
        parents[adj[curr][i]] = curr;
        out+=subtr(adj[curr][i]);
        currMx = max(currMx, lastD);
        mxD = max(mxD, lastD + 1);
    }
    subD[curr] = currMx;
    lastD = currMx + 1;
    mxD = max(mxD, lastD);
    subSz[curr] = out;
    return out;
}

void solve()
{
    cin >> n;
    parents = vint(n, -1);
    subSz = vint(n, -1);
    subD = vint(n, -1);
    adj = vvint(n);
    mxD = 0;
    lastD = 0;
    int left = 300;
    for(int i = 0; i < n-1; i++){
        int a; cin >> a;
        int b; cin >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    subtr(0);
    int root = 0;
    while (subD[root] >= left-1) {
        sort(all(adj[root]), [](const int & a, const int & b)
            { 
                return subD[a] < subD[b]; 
            });
        int nxtR = -1;
        for(int i = 0; i < sz(adj[root]); i++){
            if (subD[adj[root][i]] >= i) {
                cout << "? " << root << ln;
                cout.flush();
                int ans; cin >> ans;
                if (ans==1) {
                    cout << "! " << root << ln;
                }
                else {
                    cout << "WTF" << ln;
                }
                return;
            }
            cout << "? " << root << ln;
            cout.flush();
            int ans; cin >> ans;
            if (ans==1) {
                nxtR = 
            }
        }
    }
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        // freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}