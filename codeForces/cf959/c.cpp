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
    ll n; cin >> n;
    ll x; cin >> x;
    vlong lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    int l = 0;
    int r = 0;
    ll s = lis[0];
    vlong bonus = vlong(n+1, 1);
    ll out = 0;
    while(l < n ){
        if (s > x) {
            bonus[r+1]+=bonus[l];
            out+=bonus[l];
            // cout << l << ' ' << r << ' ' << bonus[l] + 1<< ln;
            s-=lis[l];
            l++;
            if (l>r) {
                r++;
                if (r<n) s += lis[r];
            }
        }
        else {
            if (r==n) break;
            r++;
            if (r<n) s += lis[r];   
        }
    }
    cout << (n*(n+1))/2 - out << ln;
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