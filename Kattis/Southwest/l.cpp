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
    vint lis(m); for(int _ = 0; _ < m; _++) cin >> lis[_];
    vint out(m, 0);
    while(n>0){
        int idx = 0;
        bool good = false;
        for(int i = 0; i < m; i++){
            if(out[i]!=lis[i]) good = true;
        }
        if(not good) break;
        while(n>0 and idx<m){
            idx++;
            if(out[idx-1]==lis[idx-1]) continue;
            out[idx-1]++, n--;
        }
    }
    for(int i = 0; i < m; i++) cout << out[i] << ln;
}
int main()
{
    fast_cin();
    // #ifndef ONLINE_JUDGE
    //     freopen("../../data/input.txt","r", stdin);
    //     freopen("../../data/output.txt","w", stdout);
    // #endif
    solve();
    return 0;
}