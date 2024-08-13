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

vvint seplis;
vvint dp;

int func(int i, int j, int val) {
    if (i >= sz(dp)) return 0;
    if (j >= sz(dp[0])) return 0;
    if (dp[i][j]==-1) {
        int bottom = func(i+1, j, val);
        int right = func(i, j+1, val);
        if (seplis[i][j] >= val) {
            right++;
        }
        dp[i][j] = max(bottom, right);
        
    }
    return dp[i][j];
}

bool works(int median, int geqReq) {
    dp = vvint(sz(seplis), vint(sz(seplis[0]), -1));
    int f = func(0, 0, median);
    
    if (f >= geqReq) return true;
    else return false;
}

void solve()
{
    int n; cin >> n;
    int k; cin >> k;
    vint lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    seplis = vvint();
    int end = (n-1)%k+1;
    for(int i = 0; i < n; i++) {
        if (i%k==0) seplis.pb(vint());
        if(sz(seplis[sz(seplis)-1]) < end) seplis[sz(seplis)-1].pb(lis[i]);
    }
    sort(all(lis));
    int lo = 0, hi = sz(lis)-1, ans = -1;
    while (lo<=hi) {
        int mid = (lo+hi)/2;
        // cout << end/2+1 << ' ' << lis[mid] << ln;
        if (works(lis[mid], end/2+1)) {
            ans = mid;
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    cout << lis[ans] << ln;
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