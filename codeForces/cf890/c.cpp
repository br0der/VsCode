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



void solve()
{
    int n; cin >> n;
    int k; cin >> k;
    
    vint lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    
    ll out = 0;
    for(ll i = 0; i < n; i++){
        ll cost = 0;
        ll curr = lis[i];
        for(ll j = 1; j < n-i; j++){
            if(lis[i+j]==curr-j) continue;
            if(lis[i+j]<curr-j){
                if(cost+(curr-j - lis[i+j]) >= k) break;
                cost+=(curr-j - lis[i+j]);
            }
            else{
                if((lis[i+j]-(curr-j))*j+cost<k){
                    cost += (lis[i+j]-(curr-j))*j;
                    curr = lis[i+j]+j;
                    continue;
                }
                else{
                    ll space = k-cost;
                    curr+=space/j;
                    // out = max(curr, out);
                    break;
                }
            }
        }
        // ll space = k-cost;
        // curr+=space/(n-i);
        out = max(out, curr);
        // cout << i << ' ' << curr << endl;
    }
    cout << out << endl;
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