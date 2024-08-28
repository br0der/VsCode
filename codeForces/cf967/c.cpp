//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>
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

bool bad = false;
void solve()
{
    int n; cin >> n;
    set<int> inTree;
    set<int> outofTree;
    for(int i = 1; i < n; i++){
        outofTree.insert(i);
    }
    vector<pii> edges;
    ll q = 15*n;
    while(sz(outofTree)){
        int st = 0;
        int end = *outofTree.begin();
        while (true) {
            q--;
            if (q < 0) assert(1==0);
            cout << "? " << st+1 << ' ' << end+1 << ln;
            cout.flush();
            int x; cin >> x;
            x--;
            if (x==-2) return void(bad = true);
            if (x==st) {
                edges.emplace_back(st, end);
                outofTree.erase(end);
                inTree.insert(end);
                break;
            }
            if (inTree.count(x)) {
                st = x;
                continue;
            }
            end = x;
            continue;
        }
    }
    cout << "! ";
    for(int i = 0; i < sz(edges); i++){
        cout << edges[i].first+1 << ' ' << edges[i].second+1 << ' ';
    }
    cout << ln;
    cout.flush();
}
int main()
{
    fast_cin();
    // #ifndef ONLINE_JUDGE
    //     freopen("../../data/input.txt","r", stdin);
    //     freopen("../../data/output.txt","w", stdout);
    // #endif
    ll t; cin >> t;
    while(t-- && !bad) solve();
    return 0;
}