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

int dis(pii p1, pii p2){
    return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

void solve()
{
    string s; cin >> s;
    vector<string> grid;
    vector<pii> pts;
    
    while(s!="."){
        for(int i = 0; i < sz(s); i++){
            if(s[i]=='#') pts.pb({sz(grid), i});
        }
        grid.pb(s);
        cin >> s;
    }
    ll out = 0;
    for(int i = 0; i < sz(pts); i++){
        for(int j = i+1; j < sz(pts); j++){
            out+=dis(pts[i], pts[j]);
        }
    }
    ll cnt = 0;
    ll a = 1000000;
    a--;
    for(int i = 0; i < sz(grid); i++){
        bool seen = false;
        for(int j = 0; j < sz(grid[0]); j++){
            if(grid[i][j]=='#') seen = true, cnt++;
        }
        if(not seen) out+=a*cnt*(sz(pts)-cnt);
    }
    cnt = 0;
    for(int i = 0; i < sz(grid[0]); i++){
        bool seen = false;
        for(int j = 0; j < sz(grid); j++){
            if(grid[j][i]=='#') seen = true, cnt++;
        }
        if(not seen) out+=a*cnt*(sz(pts)-cnt);
    }
    cout << out << ln;
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../data/input.txt","r", stdin);
        freopen("../data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}