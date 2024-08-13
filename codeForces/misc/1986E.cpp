//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>
#include <map>

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


void solve()
{
    int n; cin >> n;
    int k; cin >> k;
    map<int, vint> cnt;

    vint lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    for(int i = 0; i < n; i++){
        cnt[lis[i]%k].pb(lis[i]/k);
    }
    ll out = 0;
    int bad = 0;
    for (auto elem : cnt) {
        sort(all(elem.second));
        if (sz(elem.second)%2!=0) {
            bad++;
            if (sz(elem.second)==1) continue;
            vint a, b;
            for(int i = 0; i < sz(elem.second)-1; i+=2){
                a.pb((sz(a)==0?0:a[sz(a)-1]) + elem.second[i+1] - elem.second[i]);
            }
            for(int i = sz(elem.second)-2; i >= 0; i-=2){
                b.pb((sz(b)==0?0:b[sz(b)-1]) + elem.second[i+1] - elem.second[i]);
            }
            
            reverse(all(b));
            int mn = min(b[0], a[sz(a)-1]);
            assert(sz(a) == sz(b));
            // for(int i = 0; i < sz(a); i++) cout << a[i] << ' ';
            // cout << ln;
            // for(int i = 0; i < sz(b); i++) cout << b[i] << ' ';
            // cout << ln;
            for(int i = 0; i < sz(a)-1; i++){
                mn = min(mn, a[i] + b[i+1]);
            }
            out+=mn;
        }
        else{
            for(int i = 0; i < sz(elem.second); i+=2){
                out += elem.second[i+1] - elem.second[i];
            }
        }
        
    }
    if (bad>n%2) {
        cout << -1 << ln;
    }
    else {
        cout << out << ln;
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