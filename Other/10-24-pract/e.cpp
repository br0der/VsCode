// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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
    ll m; cin >> m;
    ll n; cin >> n;
    ll p; cin >> p;
    ll q; cin >> q;
    string b = "";
    string pq = to_string(p*q);
    reverse(all(pq));
    ll mn = m - n;
    ll lp = sz(to_string(p));
    ll lpq = sz(pq);
    for(int i = 0; i < lp; i++){
        b+=pq[i];
    }
    ll rem = 0;
    for(int i = lp; i < m-n+lp; i++){
        ll x = 0;
        if(i<lpq){
            x+=int(pq[i]-'0');
        }
        x+=q*int(b[i-lp]-'0');
        x+=rem;
        // if(x>(LLONG_MAX/10)) cout << 1/(1-1) << ln;
        b += to_string(x%10);
        rem = x/10;
    }
    for(int i = m-n+lp; i < lpq; i++){
        ll x = 0;
        x+=int(pq[i]-'0');
        x+=rem;
        // if(x>(LLONG_MAX/10)) cout << 1/(1-1) << ln;
        b += to_string(x%10);
        rem = x/10;
    }
    reverse(all(b));
    string c = to_string(rem)+b;
    if(sz(c)!=m or c[n]=='0'){
        cout << "IMPOSSIBLE" << ln;
        // cout << c << ln;
    }
    else{
        cout << c << ln;
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