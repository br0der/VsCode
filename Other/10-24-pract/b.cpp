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

vint owners;
vector<vector<int>> loc;
vvint islands;
bool dfs(int idx, int team){
    for(int i : islands[idx]){
        int newloc = -1;
        if(loc[i][0]==idx) newloc = loc[i][1];
        else if(loc[i][1]==idx) newloc = loc[i][0];
        else return false;
        // cout << i << ' ' << newloc << ln;
        if(owners[newloc]==team) return false;
        if(owners[newloc]==(team+1)%2) continue;
        owners[newloc] = (team+1)%2;
        if(dfs(newloc, (team+1)%2)) continue;
        return false;
    }
    return true;
}

void solve()
{
    int m; cin >> m;
    int n; cin >> n;
    loc = vector<vector<int>>(n);
    islands = vvint(m);
    owners = vint(m, -1);
    for(int i = 0; i < m; i++){
        int temp; cin >> temp;
        while(temp!=0){
            islands[i].pb(temp-1);
            loc[temp-1].pb(i);
            cin >> temp;
        }
    }
    bool works = true;
    for(int i = 0; i < m; i++){
        if(owners[i]==-1){
            owners[i] = 0;
            if(dfs(i, 0)) continue;
            works = false;
        }
    }
    // for(int i = 0; i < sz(owners); i++) cout << owners[i] << ' ';
    // cout << ln;
    cout << (works? "YES" : "NO") << ln;
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