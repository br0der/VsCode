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

ll MOD = 998244353;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";


void solve()
{
    int n; cin >> n;
    vlong start, newLoc, on;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        ll y; cin >> y;
        ll o; cin >> o;
        start.pb(x);
        newLoc.pb(y);
        on.pb(o);
    }
    vlong pSums;
    vlong ans(n, -10000);
    ll out = 0;
    for(int i = 0; i < n; i++){
        ll nxtPortal = lower_bound(all(start), newLoc[i])-start.begin();
        if(nxtPortal==i){
            ans[i] = start[i]-newLoc[i];
        }
        else{
            ans[i] = pSums[i-1]-(nxtPortal==0 ? 0 : pSums[nxtPortal-1]) + start[i]-newLoc[i];
        }
        pSums.pb(ans[i]+(i==0?0 : pSums[i-1]));
        if(on[i]){
            out+=ans[i];
        }
        ans[i]+=MOD;
        ans[i]%=MOD;
        pSums[i]+=MOD;
        pSums[i]%=MOD;
        out+=MOD;
        out%=MOD;
    }
    // for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    // cout << endl;
    cout << (out + start[sz(start)-1]+1)%MOD << endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../data/input.txt","r", stdin);
        freopen("../data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}