//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>
#include <iomanip>

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
    vector<pll> a, b;
    
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        ll y; cin >> y;
        a.emplace_back(x,y);
    }

    int m; cin >> m;
    for(int i = 0; i < m; i++){
        ll x; cin >> x;
        ll y; cin >> y;
        b.emplace_back(x,y);
    }

    ll mx = 0;
    // In order to find the maximum distance between any part of the lightning bolts,
    // all we have to do is compare the maximum distance between endpoints between segments.

    // Because of the restriction that n*m <= 10^5, we can go through all 
    // of the possible pairs of endpoints, to find which distance is maximal.
    // This takes O(m*n) time, which is fast enough given the bounds.
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ll dx = a[i].first-b[j].first;
            ll dy = a[i].second-b[j].second;
            mx = max(mx, dx*dx + dy*dy);
        }
    }

    cout << fixed << setprecision(15) << sqrt(mx) << ln;
}
int main()
{
    fast_cin();
    // #ifndef ONLINE_JUDGE
    //     freopen("lightning_large.in","r", stdin);
    //     freopen("lightning_large.out","w", stdout);
    // #endif
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}