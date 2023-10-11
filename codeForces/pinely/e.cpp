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
    ll k; cin >> k;
    vint lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    vint indegree(n, 0);
    vector<set<int>> children (n);
    for(int i = 0; i < m; i++){
        int a; cin >> a;
        int b; cin >> b;
        indegree[b-1]++;
        children[a-1].insert(b-1);
    }
    multiset<pair<int, int>> available;
    vector<pair<int, int>> nxtDay;
    int currTime = 0;
    int days = 0;
    int queued = 0;
    int start = -1;
    vector<pii> immediate;
    for(int i = 0; i < n; i++){
        if(indegree[i]==0) available.insert({lis[i], i}), queued++, immediate.pb({lis[i],i});
    }
    vlong finishDay(n, -1);
    while(true){
        while(sz(available)>0){
            pair<int, int> curr = *available.begin();
            finishDay[curr.second] = days;
            available.erase(available.begin());
            currTime = curr.first;
            if(start==-1) start = curr.first;
            for(int i : children[curr.second]){
                indegree[i]--;
                if(indegree[i]==0 and lis[i]>=currTime) available.insert({lis[i], i}), queued++;
                else if(indegree[i]==0) nxtDay.pb({lis[i], i});
            }
        }
        if(sz(nxtDay)==0) break;
        for(int i = 0; i < sz(nxtDay); i++){
            available.insert(nxtDay[i]);
            queued++;
        }
        nxtDay = vector<pair<int, int>>(0);
        days++;
        currTime = 0;
    }
    
    ll endTime = ((ll)days)*k + currTime;
    ll out = endTime - start;
    vector<bool> delayed(n, false);
    sort(all(immediate));
    for(int i = 0; i < sz(immediate)-1; i++){
        queue<int> q;
        q.push(immediate[i].second);
        while(sz(q)>0){
            int curr = q.front(); q.pop();
            endTime = max(endTime, (finishDay[curr]+1)*k+lis[curr]);
            for(int child : children[curr]){
                if(!delayed[child]){
                    if(finishDay[child]==finishDay[curr] or (finishDay[child]==finishDay[curr]+1 and lis[child]<lis[curr])){
                        delayed[child] = true;
                        q.push(child);
                    }
                }
            }
        }
        // cout << endTime << ' ' << immediate[i+1].first << ln;
        out = min(out, endTime-immediate[i+1].first);
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
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}