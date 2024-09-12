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

int euclid(int a, int b) {
    if (b==0) return a;
    return euclid(b, a%b);
}

void solve()
{
    int n; cin >> n;
    int a; cin >> a;
    int b; cin >> b;
    vint lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    int md = euclid(a, b);
    for(int i = 0; i < n; i++){
        lis[i]%=md;
    }
    sort(all(lis));
    if (n==1) {
        cout << 0 << ln;
        return;
    }
    int out = lis[n-1]-lis[0];
    for(int i = 0; i < n-1; i++){
        out = min(out, lis[i]+md - lis[i+1]);
    }
    cout << out << ln;
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