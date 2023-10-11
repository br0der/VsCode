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

ll n, x;
vint lis;
bool test(int h){
    ll total = 0;
    for(int i = 0; i < n; i++){
        total+=max(0, h-lis[i]);
    }
    return total>x;
}

void solve()
{
    cin >> n;
    cin >> x;
    lis = vint(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    ll lo = 0, hi = 2e9, ans = -1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        // cout << mid << ' ' << test(mid) << ln;
        if(test(mid)) hi = mid-1;
        else ans = mid, lo = mid+1;
    }
    cout << ans << ln;
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