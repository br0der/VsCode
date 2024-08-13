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

ll ten(int k) {
    ll out = 1;
    while (k>0){
        out*=10;
        k--;
    }
    return out;
}

void solve()
{
    int n; cin >> n;
    int l = sz(to_string(n));
    string s = "";
    for(int i = 0; i < 5; i++){
        s+=to_string(n);
    }
    vector<pll> out;
    for(int a = 1; a <= 10000; a++){
        string s1 = "";
        int nxt = 0;
        for(int b = l*a-1; b >= l*a-15; b--){
            s1+=s[nxt];
            nxt++;
            if(b <= 0 || b > 10000) continue;
            string prod = to_string((n*a)-b);
            // if (a == 1262 && b == 2519) {
            //     cout << a << ' ' << b << ' ' << prod << ' ' << s1 << ln;
            // }
            // cout << a << ' ' << b << ' ' << prod << ' ' << s1 << ln;
            if (sz(prod)==sz(s1) && sz(prod)==l*a-b) {
                bool good = true;
                for(int i = 0; i < sz(prod); i++){
                    if(prod[i]!=s1[i]) {
                        good = false;
                    }
                }
                if (good) {
                    out.emplace_back(a, b);
                    // cout << a << ' ' << b << ' ' << prod << ' ' << s1 << ln;
                }
            }
        }
    }
    cout << sz(out) << ln;
    for(int i = 0; i < sz(out); i++) cout << out[i].first << ' ' << out[i].second << ln;
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