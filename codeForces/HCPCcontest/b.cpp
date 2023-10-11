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

bool simulate(int n1, int k, int goal){

}

void solve()
{
    int n; cin >> n;
    int k; cin >> k;
    if(k>30) return void(cout << 0 << ln);
    int count = 0;
    for(int i = 0; i <= n; i++){
        int start = n, nxt = i;
        bool works = true;
        for(int i = 0; i < k-2; i++){
            
            // cout << nxt << ' ' << start << ln;
            int temp = start-nxt;
            start = nxt, nxt = temp;
            if(nxt<0 or start<0){
                works=false;
                break;
            }
        }
        // cout << nxt << ' ' << start << ln << ln;
        if(works and (start!=0 or nxt!=0) and start>=nxt) count++;
    }
    cout << count << ln;
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