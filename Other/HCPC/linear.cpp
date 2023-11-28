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
ll MOD = 1e9+7;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

vvlong mult(vvlong a, vvlong b){
    vvlong out = vvlong(int(sz(a)), vlong(int(sz(b[0])), 0));
    for(int i = 0; i < sz(a); i++){
        for(int j = 0; j < sz(b[0]); j++){
            for(int k = 0; k < sz(a[0]); k++){
                out[i][j] +=
                 a[i][k] * 
                 b[k][j];
                if(out[i][j]<0) cout << "fuck" << endl;
                out[i][j]%=MOD;
            }
        }
    }
    return out;
}

vvlong expo(vvlong base, vvlong start, ll times){
    for(ll i = 0; i < 63; i++){
        if(times&((ll)1<<i)){
            // cout << 'a' << ln;
            start = mult(base, start);
        }
        else{
            if(((ll)1<<i) > times) break;
        }
        base = mult(base, base);
    }
    return start;
}

void solve()
{
    ll a; cin >> a;
    ll b; cin >> b;
    ll n; cin >> n;
    ll x; cin >> x;
    // cout << 'a' << ln;
    cout << expo({{a, b}, {0, 1}}, {{x, 1}}, n)[0][0] << ln; 
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