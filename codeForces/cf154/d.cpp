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

// vint dp;
vint lis;

// int func(int idx){
//     if(idx>=sz(lis)-1) return 0;
//     if(dp[idx]==-1){
//         if(lis[idx]<lis[idx+1]){
//             dp[idx] = func(idx+1);
//         }
//     }
//     return dp[idx];
// }

void solve()
{
    int n; cin >> n;
    lis = vint(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    // dp = vint(n, -1);
    vint psum(n, 0), psumback(n, 0);
    for(int i = n-2; i >= 0; i--){
        if(lis[i+1]<=lis[i])psum[i]++;
        psum[i]+=psum[i+1];
    }
    for(int i = 1; i < n; i++){
        if(lis[i-1]<=lis[i])psumback[i]++;
        psumback[i]+=psumback[i-1];
    }
    // for(int i = 0; i < n; i++) cout << psum[i] << ' ';
    // cout << endl;
    // for(int i = 0; i < n; i++) cout << psumback[i] << ' ';
    // cout << endl;
    int out = psum[0];
    for(int i = 0; i < n-1; i++){
        out = min(out, psumback[i]+psum[i+1]+1);
    }
    out = min(out, psumback[n-1]+1);
    cout << out << ln;
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