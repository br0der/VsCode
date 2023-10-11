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
    ll n; cin >> n;
    ll m; cin >> m;
    ll d; cin >> d;
    multiset<ll> ms;
    ll best = 0;
    ll sum = 0;
    vlong lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    for(int i = 0; i < n; i++){
        if(lis[i]<0) continue;
        if(sz(ms)<m){
            ms.insert(lis[i]);
            sum+=lis[i];
        }
        else if(*ms.begin()<lis[i]){
            sum-=*ms.begin();
            ms.erase(ms.begin());
            sum+=lis[i];
            ms.insert(lis[i]);
        }
        best = max(best, sum-((ll)i+1)*d);
    }
    cout << best << ln;
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