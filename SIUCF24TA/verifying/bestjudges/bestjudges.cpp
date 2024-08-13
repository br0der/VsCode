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

// Written by Brady Aber
// 7/8/24
// UCF SI Camp: Contest 2
// bestjudges.cpp

void solve()
{
    int n; cin >> n;
    assert(1 <= n && n <= 100000);
    vector<pair<int, string> > judges;

    // Taking in input. Very important that I order my pair in the order of 
    // importance to sort. First the score, then the name.
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        int p; cin >> p;
        int v; cin >> v;
        int a; cin >> a;
        int x; cin >> x;
        assert(0 <= p && p <= 100000);
        assert(0 <= v && v <= 100000);
        assert(0 <= a && a <= 100000);
        assert(0 <= x && x <= 100000);
        // C++ automatically sorts in ascending order, so I can make the score
        // negative, which will sort it in ascending order. I can still retreive
        // the score if I need to as well
        judges.emplace_back(-(10*p + 4*v + 25*a + 7*x), str);
    }

    sort(all(judges));

    for(int i = 0; i < n; i++){
        cout << judges[i].second << ln;
    }
}
int main()
{
    fast_cin();
    // #ifndef ONLINE_JUDGE
    //     freopen("bestjudges.in","r", stdin);
    //     freopen("../../../data/output.txt","w", stdout);
    // #endif
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}