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

vvint dp;
vint cnt;

int func(int idx, int ahead) {
    if (idx >= sz(cnt)) return 0;
    if (ahead >= sz(cnt)) return 0;
    if (dp[idx][ahead] == -1){
        dp[idx][ahead] = func(idx + 1, ahead + 1);
        if (cnt[idx] <= ahead) {
            dp[idx][ahead] = max(dp[idx][ahead], func(idx + 1, ahead - cnt[idx]) + 1);
        }
    }
    return dp[idx][ahead];
}

void solve()
{
    int n; cin >> n;
    vint lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    sort(all(lis));
    cnt = vint();
    cnt.pb(1);
    for(int i = 1; i < n; i++){
        if (lis[i] == lis[i-1]) {
            cnt[sz(cnt)-1]++;
        }
        else {
            cnt.pb(1);
        }
    }
    // for(int i = 0; i < sz(cnt); i++) cout << cnt[i] << ' ';
    // cout << ln;
    dp = vvint(sz(cnt), vint(sz(cnt), -1));

    cout << sz(cnt) - func(0, 0) << ln;
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