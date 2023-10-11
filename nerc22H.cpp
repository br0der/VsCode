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


void solve()
{
    int n; cin >> n;
    int m; cin >> m;
    int a; cin >> a;
    int b; cin >> b;
    vvint adj(n+1, vint(n+1, -1));
    ll total = 0;
    for(int i = 0; i < m; i++){
        int i1; cin >> i1;
        int i2; cin >> i2;
        int w; cin >> w;
        adj[i1][i2] = w;
        adj[i2][i1] = w;
        total+=w;
    }
    priority_queue<vvint> pq;
    pq.push({{0, a}, {}});
    vector<bool> visited (n+1, false);
    // visited[1] = true;
    // cout << 'a' << ln;
    while(sz(pq)){
        vvint curr = pq.top(); pq.pop();
        int dist = curr[0][0], idx = curr[0][1];
        // cout << dist << ' ' << idx << ln;
        curr[1].pb(idx);
        if(idx==b){
            set<pii> roads;
            for(int i = 0; i < sz(curr[1])-1; i++){
                roads.insert({curr[1][i], curr[1][i+1]});
            }
            // roads.insert({curr[1][sz(curr)-1], b});

            while(sz(pq)){
                // for(int i = 0; i < sz(pq.top()[1]); i++) cout << pq.top()[1][i] << ' ';
                // cout << endl;
                if(pq.top()[0][0]==dist and pq.top()[0][1]==b){
                    for(int i = 0; i < sz(pq.top()[1])-1; i++){
                        roads.insert({pq.top()[1][i], pq.top()[1][i+1]});
                    }
                    roads.insert({pq.top()[1][sz(pq.top()[1])-1], b});
                }
                pq.pop();
            }

            ll paved = 0;
            for(pii p : roads){
                // cout << p.first << ' ' << p.second << ln;
                paved+=adj[p.first][p.second];
            }
            return void(cout << total-paved << ln);
        }
        if(visited[idx]) continue;
        visited[idx] = true;
        for(int i = 1; i<=n; i++){
            if(i==idx or visited[i] or adj[idx][i]==-1) continue;
            pq.push({{dist-adj[idx][i], i}, curr[1]});
        }
    }
}
int main()
{
    fast_cin();
    // #ifndef ONLINE_JUDGE
    //     freopen("data/input.txt","r", stdin);
    //     freopen("data/output.txt","w", stdout);
    // #endif
    solve();
    return 0;
}