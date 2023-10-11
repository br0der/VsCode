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

    
    if(n%3==1){
        if(n<7) cout << "NO" << ln;
        else cout << "YES" << ln << 1+((n-7)/9)*3 << ' ' << 2+((n-4)/9)*3 << ' ' << 4+((n-1)/9)*3 << ln;
    }
    if(n%3==0){
        if(n<12) cout << "NO" << ln;
        else cout << "YES" << ln << 1+((n-12)/9)*3 << ' ' << 4+((n-9)/9)*3 << ' ' << 7+((n-6)/9)*3 << ln;
    }
    if(n%3==2){
        if(n<8) cout << "NO" << ln;
        
        else cout << "YES" << ln << 1+((n-8)/9)*3 << ' ' << 2+((n-5)/9)*3 << ' ' << 5+((n-2)/9)*3 << ln;
    }
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