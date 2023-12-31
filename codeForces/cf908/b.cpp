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


void solve()
{
    int n; cin >> n;
    vint lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    set<int> seen;
    int cnt = 0;
    vint out;
    int first = -1;
    for(int i = 0; i < n; i++){
        if(not seen.count(lis[i])) out.pb(1), seen.insert(lis[i]);
        else if(cnt==2) out.pb(1);
        else if(cnt==1 and first!=lis[i]) out.pb(3), cnt++;
        else if(cnt==0) cnt++, out.pb(2), first = lis[i];
        else out.pb(1);
    }
    if(cnt!=2) cout << -1 << ln;
    else{
        for(int i = 0; i < sz(out); i++) cout << out[i] << ' ';
        cout << ln;
    }
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