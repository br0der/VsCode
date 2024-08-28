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


void solve()
{
    int n; cin >> n;
    ll m; cin >> m;
    ll mx = 0;
    for(int i = 0; i < n; i++){
        int l; cin >> l;
        vint lis(l); for(int _ = 0; _ < l; _++) cin >> lis[_];
        set<int> s;
        for(int j = 0; j < l; j++){
            s.insert(lis[j]);
        }
        bool missing = false;
        for(ll j = 0; j < l+2; j++){
            if (!s.count(j) and missing) {
                mx = max(mx, j); 
                break;
            }
            if (!s.count(j) and !missing) missing = true;
        }
    }
    // cout << mx << ln;
    if (m <= mx) {
        cout << (m+1)*mx << ln;
    }
    else {
        cout << ((mx+1)*mx)+((m+1)*m)/2 - ((mx+1)*mx)/2 << ln;
    }
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