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
    vint lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    vint one;
    vint cnt(n+1, 0);
    ll s = lis[0];
    cnt[lis[0]]++;
    one.pb(0);
    for(int i = 1; i < n; i++){
        s+=lis[i];
        cnt[lis[i]]++;
        if (cnt[lis[i]]>=2) one.pb(max(one[i-1], lis[i]));
        else one.pb(one[i-1]);
    }
    // for(int i = 0; i < sz(one); i++) cout << one[i] << ' ';
    // cout << ln;
    for(int i = 1; i < sz(one); i++){
        s+=one[i];
    }
    vlong two;
    two.pb(0);
    cnt = vint(n+1, 0);
    for(int i = 1; i < sz(one); i++){
        cnt[one[i]]++;
        if (cnt[one[i]]>=2) two.pb(max(two[i-1], (ll)one[i]));
        else two.pb(two[i-1]);
    }
    // for(int i = 0; i < sz(two); i++) cout << two[i] << ' ';
    // cout << ln;
    for(ll i = 0; i < n; i++){
        s+=two[i]*(n-i);
    }
    cout << s << ln;
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