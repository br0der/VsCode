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
    int r; cin >> r;
    int c; cin >> c;
    vector<string> grid(r);
    for(int i = 0; i < r; i++){
        cin >> grid[i];
    }
    vector<vector<char>> out(r, vector<char>(c, '.'));
    for(int i = 0; i < r; i++){
        bool needs = false;
        for(int j = 0; j < c; j++){
            if(grid[i][j]=='U'){
                if(needs) out[i][j] = 'W', out[i+1][j] = 'B';
                else out[i][j] = 'B', out[i+1][j] = 'W';
                needs = !needs;
            }
        }
        if(needs) return void(cout << -1 << ln);
    }

    for(int i = 0; i < c; i++){
        bool needs = false;
        for(int j = 0; j < r; j++){
            if(grid[j][i]=='L'){
                if(needs) out[j][i] = 'W', out[j][i+1] = 'B';
                else out[j][i] = 'B', out[j][i+1] = 'W';
                needs = !needs;
            }
        }
        if(needs) return void(cout << -1 << ln);
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++) cout << out[i][j];
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