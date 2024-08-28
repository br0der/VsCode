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
    int l1; cin >> l1;
    int r1; cin >> r1;
    int l2; cin >> l2;
    int r2; cin >> r2;
    if (l1 == r1 and l1 == l2 and l2 == r2) {
        cout << 0 << ln;
        return;
    }
    int out = 0;
    for(int i = 0; i < 101; i++){
        if (l1 <= i and i <= r1 and l2 <= (i + 1) and (i + 1) <= r2) {
            out++;
            // cout << i << ln;
        }
        else if (l2 <= i and i <= r2 and l1 <= (i + 1) and (i + 1) <= r1) {
            out++;
            // cout << i << ln;
        }
    }
    cout << max(1, out) << ln;
    // if (r1 > r2 and l1 < l2) {
    //     cout << r2-l2+2 << ln;
    // }
    // else if (r2 > r1 and l2 < l1) {
    //     cout << r1-l1+2 << ln;
    // }
    // else if (r1 >= l2 and l1 <= l2) {
    //     cout << r1-l2+1 << ln;
    // }
    // else if (r1 >= r2 and l1 >= l2) {
    //     cout << r2-l1+1 << ln;
    // }
    // else {
    //     cout << 1 << ln;
    // }
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