#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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

struct segTreeNode {
    int lo, md, hi;
    int mx = -1, lazy = 0;
    segTreeNode *left, *right;

    // Constructor
    segTreeNode(int L, int R) {
        lo = L, hi = R;
        md = (lo + hi) / 2;
        if(lo == hi) return;
        left = new segTreeNode(L, md);
        right = new segTreeNode(md+1, R);
    }

    // update sum for lazy prop
    void lazyUpdate(int dif) {
        lazy = max(lazy, dif);
        mx = max(mx, lazy);
    }

    // propagate function
    void prop() {
        if(!lazy) return;
        left->lazyUpdate(lazy);
        right->lazyUpdate(lazy);
        lazy = 0;
    }

    // Merge function: updates current node's sum
    // Mainly helpful for segTrees with intrecate merging
    void merge() {
        mx = max(left->mx, right->mx);
    }

    // Range update
    void update(int L, int R, int val) {

        // Full cover
        if(L <= lo && R >= hi) {
            mx = max(mx, val);
            lazy = max(val, lazy);
            return;
        }

        // No cover
        if(L > hi || R < lo) return;

        prop();

        left->update(L, R, val);
        right->update(L, R, val);

        merge();

        return;
    }

    // Range Query
    int query(int L, int R) {
        // Full Cover
        if(L <= lo && R >= hi) return mx;
        
        // No cover
        if(L > hi || R < lo) return -1;

        // Partial cover
        prop();

        return max(left->query(L, R), right->query(L, R));
    }
};

void solve()
{
    int n; cin >> n;
    vvint events;
    map<int, int> coord;
    vint back;
    vint nums;
    for(int i = 0; i < n; i++){
        int l; cin >> l;
        int r; cin >> r;
        int a; cin >> a;
        int b; cin >> b;
        nums.pb(l);
        nums.pb(a);
        nums.pb(b);
        nums.pb(r);
        events.pb({b, a, l, r});
    }
    int q; cin >> q;
    vint queries;
    for(int i = 0; i < q; i++){
        int idx; cin >> idx;
        nums.pb(idx);
        queries.pb(idx);
    }
    sort(all(nums));
    int nxt = 0;
    for(int i = 0; i < sz(nums); i++){
        if(i!=sz(nums)-1 and nums[i]==nums[i+1])continue;
        back.pb(nums[i]);
        coord[nums[i]] = nxt++;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            // if(coord.count(events[i][j])==0) cout << "bruh" << ln;
            events[i][j] = coord[events[i][j]];
        }
    }
    for(int i = 0; i < q; i++){
        // if(coord.count(queries[i])==0) cout << "bruh" << ln;
        queries[i] = coord[queries[i]];
    }
    segTreeNode *st = new segTreeNode(0, nxt);
    sort(all(events));
    for(int i = n-1; i >= 0; i--){
        int farthest = events[i][0];
        farthest = max(farthest, st->query(events[i][1], events[i][0]));
        // cout << back[events[i][2]] << ' ' << back[events[i][3]] << ' ' << back[farthest] << ln;
        st->update(events[i][2], events[i][3], farthest);
        // cout << back[st->query(events[i][2], events[i][3])] << ln;
    }
    for(int i = 0; i < q; i++){
        if(st->query(queries[i], queries[i])==-1) cout << back[queries[i]] << " ";
        else cout << max(back[st->query(queries[i], queries[i])], back[queries[i]]) << " ";
    }
    cout << ln;
}

void solve2() {
    int n;
    cin >> n;
 
    vector<int> ans(n);
    vector<vint> events;
    for (int i = 0 ; i < n ; i++) {
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        ans[i] = b;
        events.pb({b, 1, i});
        events.pb({l, -1, i});
    }
    int q;
    cin >> q;
    vector<int> queries(q);
    for (int i = 0 ; i < q ; i++) {
        int x;
        cin >> x;
        queries[i] = x;
        events.pb({x, 0, i});
    }
 
    sort(all(events));
    reverse(all(events));
    multiset<int> s;
    for (vint event : events) {
        int x = event[0], type = event[1], ind = event[2];
        if (type == 1) {
            if (!s.empty()) {
                ans[ind] = *s.rbegin();
            }
            s.insert(ans[ind]);
        } else if (type == 0) {
            if (!s.empty()) {
                queries[ind] = max(queries[ind], *s.rbegin());
            }
        } else {
            s.erase(ans[ind]);
        }
    }
 
    for (auto el : queries)
        cout << el << " ";
    cout << "\n";
}

int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve2();
    }
    // segTreeNode *st = new segTreeNode(0, 1e5);
    // cout << st->query(0, 1e6) << ln;
    return 0;
}