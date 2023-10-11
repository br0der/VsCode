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
    vvint nextOff(31, vint());
    for(int i = 0; i < 31; i++){
        for(int j = 0; j < n; j++){
            if((lis[j]&(1<<i))==0) nextOff[i].pb(j);
        }
    }
    int q; cin >> q;
    vint ans(q, -1);
    for(int i = 0; i < q; i++){
        int l; cin >> l;
        int k; cin >> k;
        vector<pii> decr;
        for(int j = 0; j < 31; j++){
            if((lis[l-1]&(1<<j))==0) continue;
            int end = lower_bound(all(nextOff[j]), l-1)-nextOff[j].begin();
            if(end>=sz(nextOff[j])) continue;
            decr.pb({nextOff[j][end], 1<<j});
        }
        int start = lis[l-1];
        if(start<k){
            continue;
        }
        // cout << start << ln;
        sort(all(decr));
        for(int j = 0; j < sz(decr); j++){
            start-=decr[j].second;
            // cout << start << ' ' << decr[j].first << ' ' <<  decr[j].second <<  ln;
            if(start<k){
                ans[i] = decr[j].first;
                break;
            }
        }
        if(ans[i]==-1) ans[i] = n;
    }
    for(int i = 0; i < q; i++) cout << ans[i] << ' ';
    cout << endl;
}
int main()
{
    fast_cin();
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