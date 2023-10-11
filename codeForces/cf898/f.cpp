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
    int k; cin >> k;
    vint a(n); for(int _ = 0; _ < n; _++) cin >> a[_];
    vint h(n); for(int _ = 0; _ < n; _++) cin >> h[_];
    int i = 0, j = 0, total = a[0], longest = 0;
    while(j<n and i<n){
        while(total>k and j<n) j++, i=j, total=a[j];
        if(j==n) break;
        longest = max(longest, j-i+1);
        while(j<n-1 and h[j]%h[j+1]==0){
            j++, total+=a[j];
            while(i<=j and total>k) total-=a[i], i++;
            longest = max(longest, j-i+1);
        }
        j++, i=j, total=a[j];            
    }
    cout << longest << ln;
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