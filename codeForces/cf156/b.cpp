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

double dist (int p1, int p2, int p3, int p4){
    return (p1-p3)*(p1-p3) + (p2-p4)*(p2-p4);
}

void solve()
{
    int p1; cin >> p1;
    int p2; cin >> p2;
    int p3; cin >> p3;
    int p4; cin >> p4;
    int p5; cin >> p5;
    int p6; cin >> p6;
    if(dist(0, 0, p3, p4)<=dist(0, 0, p5, p6) and dist(p1, p2, p3, p4)<=dist(p1, p2, p5, p6)){
        cout << setprecision(10) << fixed << sqrt(max(dist(0, 0, p3, p4),dist(p1, p2, p3, p4))) << ln;
    }
    else if(dist(0, 0, p3, p4)>=dist(0, 0, p5, p6) and dist(p1, p2, p3, p4)>=dist(p1, p2, p5, p6)){
        cout << setprecision(10) << fixed << sqrt(max(dist(0, 0, p5, p6),dist(p1, p2, p5, p6))) << ln;
    }
    else{
        double house = min(dist(0, 0, p3, p4), dist(0, 0, p5, p6));
        double curr = min(dist(p1, p2, p3, p4), dist(p1, p2, p5, p6));
        double between = dist(p3, p4, p5, p6);
        cout << setprecision(10) << fixed << max(sqrt(max(house, curr)), sqrt(between)/2) << ln;
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