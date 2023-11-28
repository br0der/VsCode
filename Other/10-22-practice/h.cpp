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

int n;
vvint dp;
vector<vector<bool>> grid;
vvint nxt;
int solve(int l, int r){
    if(l>=r) return 0;
    if(dp[l][r]==-1){
        dp[l][r] = solve(l+1, r);
        for(int i = l; i != r; i++, i%=n){
            if(nxt[i][r]!=-1){
                int newl = (i-1+n)%n, newr = nxt[i][r]+1;
                if(newl>newr) newr+=n;
                dp[l][r] = max(dp[l][r], solve(i+1, nxt[i][r]-1)+solve(min(newl, newr), max(newl, newr))+1);
            }
            
        }
    }
    return dp[l][r];
}

void solve()
{
    cin >> n;
    grid = vector<vector<bool>>(n, vector<bool>(n, false)); 
    nxt = vvint(n, vint(n, -1));
    dp = vvint(n, vint(n, -1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp; cin >> temp;
            grid[i][j] = (temp==1);
        }
    }
    for(int i = 0; i < n; i++){
        int last = -1;
        for(int j = i+1; j < n; j++){
            if(grid[i][j]) last = j;
            nxt[i][j] = last;
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << nxt[i][j] << ' ';
    //     }
    //     cout << ln;
    // }
    cout << solve(0, n-1) << ln;
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    // ll t; cin >> t;
    // while(t--) 
    solve();
    return 0;
}