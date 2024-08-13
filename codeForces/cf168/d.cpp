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


void solve()
{
    int n; cin >> n;
    vlong a(n); for(int _ = 0; _ < n; _++) cin >> a[_];
    vint pars(n, 0); for(int _ = 1; _ < n; _++) cin >> pars[_];

    vint indeg(n, 0);
    for(int i = 1; i < n; i++){
        pars[i]--;
        indeg[pars[i]]++;
    }
    // for(int i = 0; i < sz(indeg); i++) cout << indeg[i] << ' ';
    // cout << ln;
    queue<int> q;
    vlong mins(n, 2*1e9);
    // vlong weight(n, 0);
    for(int i = 0; i < n; i++){
        if(indeg[i]==0) q.push(i), mins[i] = a[i];
    }

    while(sz(q)!=0) {
        int curr = q.front();
        q.pop();
        if (curr==0) {
            if (mins[curr]==INF) cout << 0 << ln;
            else cout << mins[curr] + a[0] << ln;
            break;
        }
        if (a[curr] < mins[curr]) {
            ll makeup = mins[curr]-a[curr];
            mins[curr] = a[curr] + makeup/2;
        }
        else {
            mins[curr] = min(mins[curr], (ll)a[curr]);
        }

        indeg[pars[curr]]--;
        // weight[pars[curr]]+=weight[curr]+1;
        mins[pars[curr]] = min(mins[pars[curr]], mins[curr]);
        if (indeg[pars[curr]]==0) q.push(pars[curr]);
    }
    // for(int i = 0; i < sz(mins); i++) cout << mins[i] << ' ';
    // cout << ln;
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