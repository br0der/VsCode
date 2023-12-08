//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<double> vdouble;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvlong;
typedef vector<vector<double>> vvdouble;
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

ll func(ll n){
    return (n*(n+1))/2;
}

void solve()
{
    ll n; cin >> n;
    ll k; cin >> k;
    ll total = func(n);
    ll lo = 1, hi = n, ans = -1;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        ll a = n-mid+1;
        ll b = total-func(a-1);
        if(b>=k){
            hi = mid-1;
            ans = mid;
        }
        else{
            lo = mid+1;
        }
        // cout << mid << ' ' << b << ln;
    }
    cout << ans << ln;
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