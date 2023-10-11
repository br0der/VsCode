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
ll MOD = 1e9 + 7;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

vvlong mult(vvlong a, vvlong b){
    vvlong out = vvlong(sz(a), vlong(sz(b[0]), 0));
    for(int i = 0; i < sz(a); i++){
        for(int j = 0; j < sz(b[0]); j++){
            for(int k = 0; k < sz(a[0]); k++){
                // cout << sz(a[i]) << endl;
                // cout << i << ' ' << j << ' ' << k << a[i][k] * b[k][j] << endl;
                out[i][j] +=
                 a[i][k] * 
                 b[k][j];
                out[i][j]%=MOD;
            }
        }
    }
    return out;
}

vvlong expo(vvlong base, vvlong a, ll pow){
    if(pow==0) return a;
    if(pow%2==1){
        a = mult(base, a);
    }
    return expo(mult(base, base), a, pow/2);
}

void solve()
{
    int n; cin >> n;
    int d; cin >> d;
    int k; cin >> k;
    int s; cin >> s;
    vvlong big;
    vvlong identity;
    for(int i = 0; i < n+1; i++){
        vlong curr;
        for(int j = 0; j < n+1; j++){
            if (j==n) curr.pb(1);
            else if(i==n) curr.pb(0);
            else if(abs(j-i)<=d or j+(n-i)<=d or i+(n-j)<=d) curr.pb(1);
            else curr.pb(0);
        }
        big.pb(curr);
    }
    for(int i = 0; i < n+1; i++){
        vlong curr;
        for(int j = 0; j < n+1; j++){
            if(j==i) curr.pb(1);
            else curr.pb(0);
        }
        identity.pb(curr);
    }
    big = expo(big, identity, k);

    for(int i = 0; i < sz(big); i++){
        for(int j = 0; j < sz(big[0]); j++){
            cout << big[i][j] << ' ';
        }
        cout << ln;
    }

    // vvlong start;
    // for(int i = 0; i < n; i++){
    //     start.pb({i==s-1? 1 : 0});
    // }
    // start.pb({0});

    // if(k!=1) start = mult(big, start);
    
    // ll sum = 0;
    // for(int i = 0; i < n; i++){
    //     cout << start[i][0] << endl;
    //     sum+=start[i][0];
    //     sum%=MOD;
    // }
    cout << big[0][n] << endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}