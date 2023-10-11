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
    int a; cin >> a;
    int b; cin >> b;
    a--, b--;
    vint indegree(n, 0);
    vector<set<int>> adj(n);
    for(int i = 0; i < n; i++){
        int l; cin >> l;
        int r; cin >> r;
        l--, r--;
        indegree[l]++, indegree[r]++;
        adj[l].insert(r), adj[r].insert(l);
    }
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indegree[i]==1) indegree[i]--, q.push(i);
    }
    while(sz(q)>0){
        int curr = q.front(); q.pop();
        for(int nxt : adj[curr]){
            
            if(indegree[nxt]==0) continue;
            // cout << curr << ' ' << nxt << ln;
            indegree[nxt]--;
            if(indegree[nxt]<=1) q.push(nxt), indegree[nxt]--;
        }
    }
    vector<bool> visited = vector<bool> (n, false);    
    priority_queue<pii> pqb;
    pqb.push({0, b});
    int distB = -1, locB = -1;
    // cout << 'a' << ln;
    while(sz(pqb)>0){
        pii curr = pqb.top(); pqb.pop();
        if(indegree[curr.second]>0) {
            distB = -curr.first;
            locB = curr.second;
            break;
        }
        for(int nxt : adj[curr.second]){
            if(visited[nxt]) continue;
            visited[nxt] = true;
            pqb.push({curr.first-1, nxt});
        }
    }
    visited = vector<bool> (n, false);
    priority_queue<pii> pqa;
    pqa.push({0, a});
    int distA = -1;
    // cout << 'b' << ln;
    while(sz(pqa)>0){
        pii curr = pqa.top(); pqa.pop();
        if(curr.second==locB) {
            distA = -curr.first;
            break;
        }
        for(int nxt : adj[curr.second]){
            if(visited[nxt]) continue;
            visited[nxt] = true;
            pqa.push({curr.first-1, nxt});
        }
    }
    // for(int i = 0; i < n; i++) cout << indegree[i] << ' ';
    // cout << endl;
    // cout << distA << ' ' << distB << ' ' << locB << ln;
    cout << ((distA>distB)? "YES" : "NO") << ln;
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
        solve();
    }
    return 0;
}