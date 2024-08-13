//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>
#include <map>
#include <set>

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
    ll n; cin >> n;
    ll k; cin >> k;
    vlong lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    // vlong cnt(n); for(int _ = 0; _ < n; _++) cin >> cnt[_];
    
    map<ll, ll> flowers;
    set<ll> events;
    for(int i = 0; i < n; i++){
        flowers[lis[i]] += 1;
        events.insert(lis[i]);
        events.insert(lis[i]+1);
    }
    ll out = 0;
    for(ll event : events){
        ll n1 = min(flowers[event], k/event);
        ll k1 = k-n1*event;
        ll n2 = min(flowers[event+1], k1/(event+1));
        ll k2 = k1-n2*(event+1);
        ll canReplace = min(n1,flowers[event+1]-n2);
        ll k3 = max((ll)0, k2-canReplace);
        out = max(out, k-k3);
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