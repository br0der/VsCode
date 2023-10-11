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
vint lis;

bool test(int mx){
    int used = 0;
    int left = 0;
    
    while(true){
        if(used==3) return false;
        
        used++;
        int i = 0;
        while(i<sz(lis) and lis[i]-lis[left]<=mx*2)i++;
        left = i;
        if(i==sz(lis)) return true;
        
    }
}

void solve()
{
    cin >> n;
    lis = vint(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    sort(all(lis));
    int lo = 0, hi = 1e9, ans = -1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(test(mid)) ans = mid, hi = mid-1;
        else lo = mid+1;
    }
    cout << ans << ln;
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