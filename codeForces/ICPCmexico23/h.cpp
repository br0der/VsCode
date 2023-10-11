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

struct segTree{
    segTree *left = nullptr, *right = nullptr;
    int l, r, mid;
    int sum = 0;
    segTree(int lef, int rig){
        l = lef, r = rig;
        mid = (l+r)/2;
        if(l!=r){
            left = new segTree(lef, mid);
            right = new segTree(mid+1, rig);
        }
    }

    void update(int idx, int amt, int cap){
        // cout << l << ' ' << r << ' ' << idx << endl;
        
        if(l==r) return void(sum = min(cap, int(sum+amt)));
        if(idx<=mid)left->update(idx, amt, cap);
        else right->update(idx, amt, cap);
        sum = left->sum + right->sum;
    }

    int query(int lo, int hi){
        if(lo>r or hi<l) return 0;
        if(lo<=l and hi>=r) return sum;
        
        return left->query(lo, hi) + right->query(lo, hi);
    }
};

void solve()
{
    int n; cin >> n;
    int m; cin >> m;
    int q; cin >> q;
    vint capacities(n); for(int _ = 0; _ < n; _++) cin >> capacities[_];
    vint ans(q, -1);
    vvint adds;
    vvint queries;
    for(int i = 0; i < m; i++){
        int idx; cin >> idx;
        int amt; cin >> amt;
        adds.pb({idx-1, amt});
    }
    for(int i = 0; i < q; i++){
        int day; cin >> day;
        int left; cin >> left;
        int right; cin >> right;
        queries.pb({day-1, left-1, right-1, i});
    }
    segTree* st = new segTree(0, n-1);
    int i = 0;
    int j = 0;
    sort(all(queries));
    while(i<m){
        st->update(adds[i][0], adds[i][1], capacities[adds[i][0]]);
        i++;
        while(j<q and queries[j][0]<i){
            // cout << queries[j][1] << ' ' << queries[j][2] << endl;
            ans[queries[j][3]] = st->query(queries[j][1], queries[j][2]);
            j++;
        }
    }
    while(j<q){
        // cout << j << endl;
        ans[queries[j][3]] = st->query(queries[j][1], queries[j][2]);
        j++;
    }
    for(int i = 0; i < q; i++) cout << ans[i] << endl;
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