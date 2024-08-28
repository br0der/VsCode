//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>
#include <random>

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
ll MOD1 = 1000000007;
ll MOD2 = 1000000207;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";


void solve()
{
    int n; cin >> n;
    int q; cin >> q;
    mt19937 rng;
    uniform_int_distribution<ll> dist(0, 1LL<<40);
    vlong hash1, hash2, ahash1, ahash2, bhash1, bhash2;
    vint a(n); for(int _ = 0; _ < n; _++) cin >> a[_];
    vint b(n); for(int _ = 0; _ < n; _++) cin >> b[_];
    vlong nums;
    for(int i = 0; i < n; i++){
        nums.pb(dist(rng));
    }
    // hash1.pb(1);
    // hash2.pb(1);
    ahash1.pb(0);
    // ahash2.pb(0);
    bhash1.pb(0);
    // bhash2.pb(0);
    for(int i = 0; i < n; i++){
        // hash1.pb(hash1[i] + nums[a[i]]);
        // hash2.pb(hash2[i] + nums[a[i]]);
        // cout << nums[a[i]] << ' ' << a[i] << ln;
        ahash1.pb(ahash1[i] + nums[a[i]-1]);
        // ahash2.pb((ahash2[i-1]*10+a[i])%MOD2);
        bhash1.pb(bhash1[i] + nums[b[i]-1]);
        // bhash2.pb((bhash2[i-1]*10+b[i])%MOD2);
    }
    for(int i = 0; i < q; i++){
        int l1; cin >> l1;
        int r1; cin >> r1;
        int l2; cin >> l2;
        int r2; cin >> r2;
        if (r2-l2 != r1-l1) cout << "No" << ln;
        else {
            ll ah1 = ahash1[r1]-ahash1[l1-1];
            // int ah2 = ahash2[r1-1];
            ll bh1 = bhash1[r2]-bhash1[l2-1];
            // int bh2 = bhash2[r2-1];
            if (ah1==bh1) {
                cout << "Yes" << ln;
            }
            else {
                cout << "No" << ln;
            }
        }
    }
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}