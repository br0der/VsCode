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

int func(int a) {
    int out = 0;
    while (a > 0) a/=3, out++;
    return out;
}

void solve()
{
    int a; cin >> a;
    int b; cin >> b;
    int out = 2*func(a);
    for(int i = a+1; i <= b; i++){
        out+=func(i);
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
    vlong psum;
    psum.pb(0);
    for(int i = 1; i <= 200000; i++){
        psum.pb(func(i)+psum[i-1]);
    }
    for(int i = 0; i < t; i++){
        int a; cin >> a;
        int b; cin >> b;
        cout << psum[b] - psum[a-1] + func(a) << ln;
    }
    return 0;
}