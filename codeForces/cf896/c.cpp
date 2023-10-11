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
    vvint grid(n, vint(m, -1));
    if(m==1){
        cout << 0 << ln;
        for(int i = 0; i < n; i++){
            cout << 0 << ln;
        }
        return;
    }
    for(int i = 0; i < min(n, m); i++){
        for(int j = i; j >=0 ; j--){
            if(i!=m-1 or j!=i)grid[j][i] = i-j;
        }
    }
    if(n>=m){
        for(int i = 1; i < m-1; i++){
            for(int j = 0; j < i; j++){
                grid[i][j] = grid[i][(j+m-1)%m]+1;
            }
        }
        for(int i = m-1; i < n; i++){
            for(int j = 0; j < m; j++){
                grid[i][j] = grid[i-1][j];
            }
        }
        cout << m << ln;
    }
    else{
        for(int i = 0; i < n; i++){
            for(int j = n; j < m; j++){
                grid[i][j] = grid[i][j-1]+1;
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                grid[i][j] = grid[i][(j+m-1)%m]+1;
            }
        }
        cout << n+1 << ln;
    }
    // for(int i = min(n, m); i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         grid[j][i] = grid[j][i-1]+1;
    //     }
    // }

    // for(int i = 0; i < min(n, m); i++){
    //     for(int j = i+1; j < n-1; j++){
    //         if(i!=0) grid[j][i] = grid[j][i-1]+1;
    //         else{
    //             grid[j][i] = grid[j][min(n, m)-1]+1;
    //         }
    //     }
    // } 
    for(int i = 0; i < sz(grid); i++){
        for(int j = 0; j < sz(grid[0]); j++) cout << grid[i][j] << ' ';
        cout << endl;
    }
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