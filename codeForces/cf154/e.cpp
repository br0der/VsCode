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

#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

ll MOD = 998244353;

int n, k;
vector<pair<ll, ll>> dp;
ll permSize;

pair<ll, ll> func(int idx){
    if(idx>=n) return {1, 0}; // perm, cost
    if(dp[idx].first==-1){
        dp[idx] = {0, 0};
        pair<ll, ll> res = func(idx+1);
        dp[idx].first = res.first*k;
        dp[idx].first%=MOD;
        dp[idx].second = res.second;
        if(idx<=n-k){
            ll num = permSize*func(idx+k).first;
            num-=min(n-idx-k, k-1)*permSize;
            dp[idx].second+=num;
            dp[idx].second%=MOD;
        }
    }
    return dp[idx];
}

void solve()
{
    cin >> n >> k;
    permSize = 1;
    for(int i = 2; i <= k; i++){
        permSize*=i;
        permSize%=MOD;
    }
    dp = vector<pair<ll, ll>>(n, {-1, -1});
    cout << func(0).first << ' ' << func(0).second << ln;
    for(int i = 0; i < n; i++) cout << dp[i].first << ' ' << dp[i].second << ln;
    cout << endl;
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