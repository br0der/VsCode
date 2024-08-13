//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<double> vdouble;
typedef vector<vector<int> > vvint;
typedef vector<vector<ll> > vvlong;
typedef vector<vector<double> > vvdouble;
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
    ll e; cin >> e;
    vlong lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    vlong psum;
    lis[0]+=e;
    psum.pb(lis[0]);

    for(int i = 1; i < n; i++){
        psum.pb(psum[i-1]+lis[i]);
    }
    int mx = max_element(all(lis))-lis.begin();
    int mxSuff = -1;
    vint out(n, -1);
    for(int i = n-1; i >=0; i--){
        if (i==mx) {
            out[i] = 0;
        }
        else {
            out[i] = i;
            if ((i==0? 0 : psum[i - 1] ) + lis[i] < lis[mx]) {
                out[i]++;
            }
        }
    }
    for(int i = 0; i < sz(out); i++) cout << out[i] << ' ';
    cout << ln;
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