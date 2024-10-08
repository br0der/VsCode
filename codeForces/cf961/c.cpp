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
    vint lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    bool one = true;
    for(int i = 0; i < n; i++){
        if (lis[i]==1 && !one) {
            cout << -1 << ln;
            return;
        }
        if (lis[i]!=1) one = false;
    }
    ll out = 0;
    ll last = 0;
    for(int i = 1; i < n; i++){
        if (lis[i-1]==1) continue;
        ll temp = lis[i];
        while (temp < lis[i-1]) {
            temp *= temp;
            last++;
        }
        ll temp2 = lis[i-1];
        while (temp2*temp2 <= temp && last > 0) {
            temp2 *= temp2;
            last--;
        }
        out+=last;
        // cout << last << ' ' << i << ln;
    }
    cout << out << ln;
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