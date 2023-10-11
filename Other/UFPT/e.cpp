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
    vlong lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    vlong pre(1, lis[0]), preSort;
    for(int i = 1; i < n; i++){
        pre.pb(pre[i-1]+lis[i]);
    }
    sort(all(lis));
    preSort.pb(lis[0]);
    for(int i = 1; i < n; i++){
        preSort.pb(preSort[i-1]+lis[i]);
    }
    int nq; cin >> nq;
    for(int i = 0; i < nq; i++){
        int typ; cin >> typ;
        int a; cin >> a;
        int b; cin >> b;
        if(typ==1){
            cout << pre[b-1]-(a==1? 0 : pre[a-2]) << ln;
        }
        else{
            cout << preSort[b-1]-(a==1? 0 : preSort[a-2]) << ln;
        }
    }
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