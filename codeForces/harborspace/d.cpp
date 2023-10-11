// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    int maxDiag = 2*n - 1;
    vector<bool> swap (maxDiag, false);
    int row = 0, col = 0;
    int out = 0;
    bool base = false;
    while(!(row==n and col==n-1)){
        int r = row, c = col;
        bool invert = base;
        int currDiag = n-1-r+c;
        while(r<n and c>=0){
            invert ^= swap[n-1-r+c];
            if(n-r+c<maxDiag) invert ^= swap[n-r+c];
            if((grid[r][c]-'0')^invert){
                // cout << r << ' ' << c << ln;
                out++;
                swap[n-1-r+c] = !swap[n-1-r+c];
                invert = !invert;
            }
            r++, c--;
        }

        if(col!=n-1) col++;
        else{
            if(currDiag+1<maxDiag) base ^= swap[currDiag+1];
            row++;
        }
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