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

ll cross(pll a, pll b, pll c){ // returns a positive number if ab and ac forms a right turn 
    return (c.first-a.first)*(b.second-a.second) - (c.second-a.second)*(b.first-a.first); 
} 

ll areaTri(pll a, pll b){ 
    return abs((a.first)*(b.second) - (a.second)*(b.first))/2; 
} 

void solve()
{
    int n; cin >> n;
    ll a = 0;
    vector<pll> points;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        ll y; cin >> y;
        points.pb({2*x, 2*y});
    }
    for(int i = 0; i < n; i++){
        a+=cross({0,0}, points[i], points[(i+1)%n])/4;
        // cout << cross({0,0}, points[i], points[(i+1)%n])/4 << ln;
    }
    cout << abs(a) << ln;
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("data/input.txt","r", stdin);
        freopen("data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}