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
ll MOD = 1000000007;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

ll inv(ll a) {
    ll expo = MOD-2;
    ll b = a;
    ll out = 1;
    while (expo > 0) {
        if (expo&1) out*=b, out%=MOD;
        b*=b;
        b%=MOD;
        expo >>= 1;
    }
    return out;
}

vlong factorials;
vlong inverseFac;

void solve()
{
    int n; cin >> n;
    int k; cin >> k;
    int ones = 0, zeros = 0;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        if (temp==1) ones++;
        else zeros++;
    }
    
    
    ll out = 0;
    for(int i = (k+1)/2; i <= k; i++){
        if (i>ones or k-i>zeros) continue;
        ll o = factorials[ones];
        o*=inverseFac[i];
        o%=MOD;
        o*=inverseFac[ones-i];
        o%=MOD;
        ll z = factorials[zeros];
        z*=inverseFac[k-i];
        z%=MOD;
        z*=inverseFac[zeros-(k-i)];
        z%=MOD;
        ll add = (o*z)%MOD;
        out+=add;
        out%=MOD;
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
    ll curr = 1;
    factorials.pb(1);
    inverseFac.pb(1);
    for(int i = 1; i < 200001; i++){
        factorials.pb(curr);
        inverseFac.pb(inv(curr)%MOD);
        curr*=i+1;
        curr%=MOD;
    }
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}