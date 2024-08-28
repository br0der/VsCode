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
#define rep(i,j,n)  for(int i=(j);i<=(n);i++)
string ln = "\n";


void solve()
{
    int n; cin >> n;
    int m; cin >> m;
    vector<int> ends;
    for(int i = 0; i < m; i++){
        int a; cin >> a;
        int b; cin >> b;
        ends.emplace_back(b-1);
    }
    vint out(n, -1);
    int j = m-1;
    int cnt = 1;
    rep(i, 0, n-1) {
        int ii = n-1-i;
        if (j >= 0 and ii==ends[j]) j--;
        else out[ii] = cnt++;
    }
    rep(i, 0, n-1) {
        int ii = n-1-i;
        if (out[ii]==-1) out[ii] = cnt++;
    }

    for(int i = 0; i < sz(out); i++) cout << out[i] << ' ';
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