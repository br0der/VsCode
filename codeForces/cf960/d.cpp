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

int n;
vint lis;
int dp[200000][3];

int func(int idx, int last) {
    if (idx >= n) {
        return 0;
    }
    if (dp[idx][last]==-1) {
        dp[idx][last] = func(idx+1, 0) + 1;
        if (idx==3 && last == 1) {

        }
        if (lis[idx]==0 || (last==1 && lis[idx]<=2)) {
            dp[idx][last] = func(idx+1, 0);
            return dp[idx][last];
        }
        int curr = lis[idx];
        if (curr >= 5) {
            return dp[idx][last];
        }
        if (last==2) {
            curr = max(2, curr-2);
        }
        if (last==1) {
            if (curr <= 2) {
                dp[idx][last] = min(func(idx+1, 0), dp[idx][last]);
            }
            else {
                dp[idx][last] = min(func(idx+1, 2) + 1, dp[idx][last]);
            }
        }
        if (curr<=2) {
            dp[idx][last] = min(dp[idx][last], func(idx+1, 1) + 1);
        }
        if (curr<=4) {
            dp[idx][last] = min(dp[idx][last], func(idx+2, 0) + 2);
        }
    }
    return dp[idx][last];
}

void solve()
{
    cin >> n;
    lis = vint(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    for(int i = 0; i < n; i++){
        dp[i][0] = -1;
        dp[i][1] = -1;
        dp[i][2] = -1;
    }
    
    cout << func(0, 0) << ln;
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << dp[j][i] << ' ';
    //     }
    //     cout << ln;
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