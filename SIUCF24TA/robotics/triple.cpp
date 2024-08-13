// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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
    int tr; cin >> tr;
    int th; cin >> th;
    int ty; cin >> ty;
    int r; cin >> r;
    vint l1(tr); for(int _ = 0; _ < tr; _++) cin >> l1[_];
    vint l2(th); for(int _ = 0; _ < th; _++) cin >> l2[_];
    vint l3(ty); for(int _ = 0; _ < ty; _++) cin >> l3[_];
    int best = -1;
    for(int i = 0; i < tr; i++){
        for(int j = 0; j < th; j++){
            for(int k = 0; k < ty; k++){
                if (l1[i]*l2[j]*l3[k] <= r) {
                    best = max(best, l1[i]*l2[j]*l3[k]);
                }
            }
        }
    }
    if(best==-1) cout << "DISQUALIFIED!" << ln;
    else cout << best << ln;
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("robotics_large.in","r", stdin);
        freopen("myout.out","w", stdout);
    #endif
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}