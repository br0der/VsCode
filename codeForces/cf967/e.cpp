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

int dp[501][501];

ll func(int n, int k) {
    if (n == 0) return 1;
    if (k == 0) return 0;
    if (dp[n][k]==-1) {
        ll out = 0;
        for(int i = 0; i < k; i++){
            out+=(func(n-1, k-i)*func(n-1, i))%MOD;
            out%=MOD;
        }
        dp[n][k] = out;
    }
    return dp[n][k];
}

void solve()
{
    int n; cin >> n;
    int k; cin >> k;
    cin >> MOD;
    for(int i = 0; i < 501; i++){
        for(int j = 0; j < 501; j++){
            dp[i][j] = -1;
        }
    }
    cout << func(n-1, k) << ln;
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