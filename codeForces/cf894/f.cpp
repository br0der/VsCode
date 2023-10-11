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

int w, f;
int sum;
vint lis;
vvint dp;

int func(int idx, int water){
    if(idx>=sz(lis)){
        return max(ceil((double)water/(double)w), ceil((double)(sum-water)/(double)f));
    }
    if(water>=sz(dp[0])) return 1e9;
    if(dp[idx][water]==-1) dp[idx][water] = min(func(idx+1, water+lis[idx]), func(idx+1, water));
    // cout << idx << ' ' << water << ' ' << dp[idx][water] << ln;
    return dp[idx][water];
}

void solve()
{
    cin >> w >> f;
    if(w>f) swap(w, f);
    int n; cin >> n;
    lis = vint(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    sum = 0;
    for(int i : lis) sum+=i;
    dp = vvint(n, vint(sum/2+*max_element(all(lis)), -1));
    // for(int i = 0; i < n; i++) cout << lis[i] << ' ';
    // cout << endl;
    cout << func(0, 0) << ln;
}
int main()
{
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