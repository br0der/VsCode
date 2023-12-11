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


ll q, s, n;
vlong scrap;
vvlong dp;

ll p(ll n){
    if(n==0) return 1;
    return (p(n-1)*2)%MOD;
}

ll countWaysUtil(ll idx, ll leftToMake) {

    // base case here:
    if (leftToMake <= 0) return p(n-idx) % MOD; // this is badass wtf
    if (idx==n) return 0;
   
   
    if (dp[idx][leftToMake] != -1)
        return dp[idx][leftToMake];
    ll ways = 0;
    ways = (countWaysUtil(idx+1, leftToMake) % MOD + countWaysUtil(idx+1, leftToMake-scrap[idx]) % MOD) % MOD;
    dp[idx][leftToMake] = ways % MOD;
    return ways;
}


void solve() {
    cin >> q >> s >> n;
    scrap = vlong(n);
    for (ll i = 0; i < n; ++i)
        cin >> scrap[i];


    ll leftToMake = q - s;

    dp = vvlong(n, vlong(leftToMake + 1, -1));
    cout << (ll)countWaysUtil(0, leftToMake) << endl;
    // return countWaysUtil(0, leftToMake) % MOD;
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}