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
#define pb(x) (push_back(x))
string ln = "\n";

void solve()
{
    int n, m; cin >> n >> m;
    vvint g(n, vint(m, -1));
    vint a;
    vvint SWNE(m+n-1), SENW(m+n-1);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> g[i][j];
            if(g[i][j]!=-1){
                a.push_back(g[i][j]);
                SWNE[i+j].push_back(g[i][j]);
                SENW[i-j+m-1].push_back(g[i][j]);
            }
        }
    }
    
    sort(all(a));
    int TL = 0, TR = 0, BL = 0, BR = 0;
    int last = 0;
    for(int i = 0; i<sz(SENW); i++){
        for(int j : SENW[i]){
            bool seen = false;
            for(int k = last; k<last+sz(SENW[i]); k++) {
                if(a[k]==j) 
                    seen = true;
            }
            if(not seen) TR++;
        }
        last+=sz(SENW[i]);
    }
    last = 0;
    for(int i = 0; i<sz(SWNE); i++){
        for(int j : SWNE[i]){
            bool seen = false;
            for(int k = last; k<last+sz(SWNE[i]); k++) {
                if(a[k]==j) 
                    seen = true;
            }
            if(not seen) TL++;
        }
        last+=sz(SWNE[i]);
    }
    last = 0;
    for(int i = sz(SENW)-1; i>=0; i--){
        for(int j : SENW[i]){
            bool seen = false;
            for(int k = last; k<last+sz(SENW[i]); k++) {
                if(a[k]==j) 
                    seen = true;
            }
            // cout << i << ' ' << seen << ' ' << last << ln;
            if(not seen) BR++;
        }
        last+=sz(SENW[i]);
    }
    last = 0;
    for(int i = sz(SWNE)-1; i>=0; i--){
        for(int j : SWNE[i]){
            bool seen = false;
            for(int k = last; k<last+sz(SWNE[i]); k++) {
                if(a[k]==j) 
                    seen = true;
            }
            
            if(not seen) BL++;
        }
        last+=sz(SWNE[i]);
    }
    // cout << TL << ' ' << TR << ' ' << BL << ' ' << BR << ln;
    cout << min({TL, TR, BL, BR}) << ln;
    int curr = 0;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}