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
    vector<pair<ll, int>> lis(n); for(int _ = 0; _ < n; _++){
        int temp; cin >> temp;
        lis[_] = {temp, _};
    }
    sort(all(lis));
    ll sum = 0;
    for(int i = 0; i < n; i++) sum+=lis[i].first+1;
    // int j = 0;
    ll last = 0;
    vlong ans(n, -1);

    for(int i = 0; i < n; i++){
        sum-=(lis[i].first-last)*(n-i);
        sum+=(lis[i].first-last)*i;
        ans[lis[i].second] = sum;
        last = lis[i].first;
        // cout << sum << endl;
    }
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
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