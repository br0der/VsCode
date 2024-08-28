//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>
#include <random>

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
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep2(i, a, b) for (int i = a; i<=b; ++i)
string ln = "\n";

struct point {
    int x, y, idx;
};

void solve()
{
    int n; cin >> n;
    // int n = 1e6;
    mt19937 rng;
    uniform_int_distribution<int> dist(0, 1e6);
    vector<vector<vector<point> > > blocks(1000, vector<vector<point> >(1000, vector<point>()));
    for(int i = 0; i < n; i++){
        // int x = dist(rng);
        // int y = dist(rng);
        int x; cin >> x;
        int y; cin >> y;
        blocks[min(x/1000, 999)][min(y/1000, 999)].pb({x, y, i});
    }
    ll d = 0;
    point last;
    auto comp = [&](point p1, point p2) {
		if (p1.x!=p2.x) return p1.x < p2.x;
        if (p1.y!=p2.y) return p1.y < p2.y;
        return p1.idx < p2.idx;
	};
    rep(i, 1000) {
        rep(jj, 1000) {
            int j;
            if (i%2==0) j = jj;
            else j = 1000-jj-1;
            sort(all(blocks[i][j]), comp);
            rep(k, sz(blocks[i][j])) {
                if (d==0) last = blocks[i][j][k];
                d+=abs(last.x-blocks[i][j][k].x) + abs(last.y-blocks[i][j][k].y);
                assert(d <= 25*(ll)1e8);
                cout << blocks[i][j][k].idx+1 << ' ';
                last = blocks[i][j][k];
            }
        }
    }
    cout << ln;
    assert(d <= 25*(ll)1e8);
    cout << d << ln;
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}