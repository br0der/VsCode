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

struct segTree {
    int lo, mid, hi, mx, setCol, setRow;
    segTree *left, *right;
    segTree(int l, int r) {
        lo = l;
        hi = r;
        mid = (l+r)/2;
        mx = 0;
        if (l!=r) {
            left = new segTree(l, mid);
            right = new segTree(mid+1, r);
        }
        setCol = 1;
        setRow = 1;
    }

    pair<int, pii> query(int l, int r) {
        if (lo >= l and r >= hi) return make_pair(mx, make_pair(setRow, setCol));
        if (r < lo or hi < l) return make_pair(0, make_pair(1, 1));
        return max(left->query(l, r), right->query(l, r));
    }

    void update(int idx, int val, int col) {
        if (idx < lo or idx > hi) return;
        if (val > mx) {
            mx = val;
            setCol = col;
            setRow = idx;
        }
        if (lo!=hi) {
            left->update(idx, val, col);
            right->update(idx, val, col);
        }
    }
};

void solve()
{
    int r; cin >> r;
    int c; cin >> c;
    int n; cin >> n;
    
    vector<pii> coins;
    map<pii, pii> buildback;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        int b; cin >> b;
        coins.emplace_back(b, a);
    }
    sort(all(coins));
    segTree* st = new segTree(1, r);
    int lastC = 0;
    for(int i = 0; i < n; i++){
        int col = coins[i].first;
        int row = coins[i].second;
        assert(lastC <= col);
        lastC = col;
        pair<int, pii> info = st->query(1, row);
        assert(info.second.first <= row);
        buildback.insert(make_pair(make_pair(row, col), info.second));
        // cout << row << ' ' << col << ' ' << info.second.first << ' ' << info.second.second << ln; 
        st->update(row, info.first+1, col);
        // cout << st->query(1, r).first << ' ' << st->query(1, r).second.first << ' ' << st->query(1, r).second.second << ln;
    }
    pair<int, pii> end = st->query(1, r);
    pii curr = end.second;
    vector<pii> bb;
    bb.pb(make_pair(r, c));
    bb.pb(curr);
    while (curr.first!=1 or curr.second!=1) {
        curr = buildback.at(curr);
        // cout << curr.first << ' ' << curr.second << ln;
        bb.pb(curr);
    }
    // cout << sz(bb) << ln;
    // for(int i = 0; i < sz(bb); i++) cout << bb[i].first << ' ' << bb[i].second << ln;
    // cout << ln;
    reverse(all(bb));
    pii last = make_pair(1, 1);
    cout << sz(bb)-2 << ln;
    for(int i = 0; i < sz(bb); i++){
        for(int j = 0; j < bb[i].first-last.first; j++){
            cout << 'D';
        }
        for(int j = 0; j < bb[i].second-last.second; j++){
            cout << 'R';
        }
        last = bb[i];
    }
    cout << ln;
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