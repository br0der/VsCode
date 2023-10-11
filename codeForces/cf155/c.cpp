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
ll MOD = 998244353;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

ll fact(ll num){
    ll o = 1;
    for(ll i = num; i >= 1; i--){
        o*=i;
        o%=MOD;
    }
    return o;
}

void solve()
{
    string s; cin >> s;
    int n = sz(s);
    vlong runs;
    ll l = 1;
    for(int i = 1; i < n; i++){
        if(s[i]!=s[i-1]) runs.pb(l), l = 0;
        l++;
    }
    runs.pb(l);
    // for(int i = 0; i < sz(runs); i++) cout << runs[i] << ' ';
    // cout << endl;
    ll out = 1;
    int out2 = 0;
    for(int i = 0; i < sz(runs); i++){
        out2+=runs[i]-1;
        out*=runs[i];
        out%=MOD;
    }
    cout << out2 << ' ' << (out*fact(out2))%MOD << ln;
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}