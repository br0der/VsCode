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
    int n; cin >> n;
    vlong lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    ll dp[n][2];
    if (n==1) {
        cout << lis[0] << ln;
        return;
    }
    // for(int i = 0; i < sz(lis); i++) cout << lis[i] << ' ';
    // cout << ln;
    dp[0][0] = lis[0];
    dp[0][1] = 0;
    dp[1][0] = lis[1];
    dp[1][1] = lis[1]*2+lis[0];
    ll mx = lis[1]*2+lis[0];
    for(int i = 2; i < n; i++){
        dp[i][0] = max(dp[i-1][1], dp[i-2][1])+lis[i];
        dp[i][1] = max(dp[i-1][0], dp[i-2][0])+2*lis[i];
        mx = max(mx, max(dp[i][0], dp[i][1]));
    }
    cout << mx << ln;
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