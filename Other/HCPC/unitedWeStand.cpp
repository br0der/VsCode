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
    sort(all(lis));
    if(lis[0]==lis[sz(lis)-1]){
        cout << -1 << ln;
    }
    else{
        vint la, lb;
        int i = 0;
        for( ; i < n-1; i++){
            la.pb(lis[i]);
            if(lis[i]!=lis[i+1]) break;
        }
        
        for(int j = i+1; j < n; j++){
            lb.pb(lis[j]);
        }
        cout << sz(la) << ' ' << sz(lb) << ln;
        for(int i = 0; i < sz(la); i++) cout << la[i] << ' ';
        cout << ln; 
        for(int i = 0; i < sz(lb); i++) cout << lb[i] << ' ';
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