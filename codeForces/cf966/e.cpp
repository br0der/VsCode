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


void solve()
{
    int n; cin >> n;
    int m; cin >> m;
    int k; cin >> k;
    int w; cin >> w;
    vector<int> gorillas(w); for (int i = 0; i < w; i++) cin >> gorillas[i], gorillas[i]*=-1;
    sort(gorillas.begin(), gorillas.end());
    vector<int> positions;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            positions.push_back(-min(min(i+1, n-i), min(k, n-k+1)) * min(min(j+1, m-j), min(k, m-k+1)));
        }
    }
    sort(positions.begin(), positions.end());
    ll out = 0;
    // for (int i = 0; i < n*m; i++) cout << -positions[i] << ' ';
    // cout << ln;
    for(int i = 0; i < w; i++){
        // cout << positions[i] << ' ' << gorillas[i] << ln;
        out+=(ll)positions[i]*(ll)gorillas[i];
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