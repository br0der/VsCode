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

string str;

bool func(int idx){
    set<char> seen;
    for(int i = idx; i < sz(str); i++){
        if(sz(seen)==7) seen.clear();
        if(seen.count(str[i])) return false;
        seen.insert(str[i]);
    }
    return true;
}

void solve()
{
    cin >> str;
    set<char> seen;
    bool works = func(0);
    for(int i = 0; i < min(7, int(sz(str))); i++){
        if(seen.count(str[i])) break;
        seen.insert(str[i]);
        works|=func(i+1);
    }
    cout << (works? 1 : 0) << ln;
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