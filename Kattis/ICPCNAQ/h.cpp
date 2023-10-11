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

vlong factor(ll num){
    
}


void solve()
{
    ll num; cin >> num;
    ll k; cin >> k;
    ll p; cin >> p;
    vlong facs;
    for(ll i = 1; i*i<=num; i++){
        if(num%i==0){
            if(num/i<=p and i<=k) facs.pb(i);
            if(i<=p and num/i<=k and i!=(num/i)) facs.pb(num/i);
        }
    }
    sort(all(facs));
    cout << sz(facs) << ln;
    for(int i = 0; i < sz(facs); i++) cout << facs[i] << ln;
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