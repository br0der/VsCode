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
#define pb(x) (push_back(x))

vvint children;

ll out;

// ll total;
vvlong dp;

ll func(int idx, ll diff, vlong &sizes, ll total){
    if(idx==sz(sizes)) return (total-diff)*diff;
    if(dp[idx][diff]==-1){
        dp[idx][diff] = max(func(idx+1, diff+sizes[idx], sizes, total), func(idx+1, diff, sizes, total));
    }
    return dp[idx][diff];
}

int dfs(int idx){
    if(sz(children[idx])==0) return 1;
    if(sz(children[idx])==1) return dfs(children[idx][0])+1;
    vlong sizes(0);
    ll total = 0;
    for(int i : children[idx]){
        sizes.push_back(dfs(i));
        total+=sizes[sz(sizes)-1];
    }
    // cout << idx << endl;
    // for(int i = 0; i < sz(sizes); i++) cout << sizes[i] << ' ';
    if(*max_element(all(sizes))<total/2){
        cout << endl;
        dp = vvlong(sz(sizes), vlong(total, -1));
        out += func(0, 0, sizes, total);
    }
    else{
        out+=*max_element(all(sizes))*(total-*max_element(all(sizes)));
    }
    return total+1;
}

void solve()
{
    int n; cin >> n;
    children = vvint(n, vint());
    for(int i = 0; i < n-1; i++){
        int temp; cin >> temp;
        children[temp-1].push_back(i+1);
    }
    out = 0;
    dfs(0);
    cout << out << endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}