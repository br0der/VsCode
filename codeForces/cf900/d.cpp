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
    int k; cin >> k;
    string s; cin >> s;
    vint a(k); for(int _ = 0; _ < k; _++) cin >> a[_];
    vint b(k); for(int _ = 0; _ < k; _++) cin >> b[_];
    vint invert;
    int nq; cin >> nq;
    int curr = 0;
    vint q(nq); for(int _ = 0; _ < nq; _++) cin >> q[_];
    sort(all(q));
    for(int i = 0; i < nq; ){
        while(b[curr]<q[i])curr++;
        while(i<nq and q[i]<=b[curr]) {
            int l = min(q[i], b[curr]+a[curr]-q[i]), r = max(q[i], b[curr]+a[curr]-q[i])+1;
            invert.pb(l), invert.pb(r), i++;
        }
    }
    sort(all(invert));
    // for(int i = 0; i < sz(invert); i++) cout << invert[i] << ' ';
    // cout << endl;
    
    int idx = 0;
    bool flip = false;
    curr = 0;
    for(int i = 0; i < n; i++) {
        if(curr<k and b[curr]-1<i) curr++;
        
        while(idx<sz(invert) and invert[idx]-1==i) flip = !flip, idx++;
        int print = i;
        if(flip) print = b[curr]+a[curr]-print-2;
        // cout << print << ln;
        cout << s[print];
    }
    cout << ln;
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