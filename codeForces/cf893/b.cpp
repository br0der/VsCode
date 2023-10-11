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
    int m; cin >> m;
    int d; cin >> d;
    vint lis(m); for(int _ = 0; _ < m; _++) cin >> lis[_];
    int can = 0;
    int last = 1;
    for(int i = 0; i < m; i++){
        if(lis[i]==1) continue;
        int n1 = (lis[i]-last-1)/d + ((i==m-1? n+1 : lis[i+1])-lis[i]-1)/d + 1;
        int n2 = ((i==m-1? n+1 : lis[i+1])-last-1)/d;
        if(n1>n2) can++;
        last = lis[i];
    }
    // cout << can << ln;
    // int dist = (lis[sz(lis)-1]-lis[sz(lis)-2])%d;
    // dist = d-dist;
    // int dist2 = (n-lis[sz(lis)-2])%d;
    // if(dist>=dist2) can++;
    int eaten = lis[0]!=1;
    int las = 1;
    for(int i = 0; i < m; i++){
        int diff = lis[i]-las-1;
        // if(diff==-1) continue;
        eaten+=diff/d;
        eaten++;
        las = lis[i];
    }
    eaten+=(n-lis[sz(lis)-1])/d;
    if(can){
        cout << eaten-1 << ' ' << can << ln;
        return;
    }
    cout << eaten << ' ' << m << ln;
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