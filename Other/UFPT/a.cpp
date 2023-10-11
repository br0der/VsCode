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
ll MOD = 1e9+7;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

int n, k, d;

vint dp;

ll func(int currWeight, bool fulfilled){
    if(currWeight==n) return fulfilled? 1 : 0;
    if(dp[currWeight+(fulfilled? n : 0)]==-1){
        ll ways = 0;
        for(int i = 1; i <= min(k, n-currWeight); i++){
            ways+=func(currWeight+i, fulfilled|(i>=d));
            ways%=MOD;
        }
        dp[currWeight+(fulfilled? n : 0)] = ways;
    }
    return dp[currWeight+(fulfilled? n : 0)];
}

void solve()
{
    cin >> n >> k >> d;
    dp = vint(2*n, -1);
    cout << func(0, false) << ln;
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}