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
ll MOD = 998244353;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

vint parents, sizes;

int get(int a){
    if(parents[a]==a) return a;
    return parents[a] = get(parents[a]);
}

void merge(int a, int b){
    a = get(a);
    b = get(b);
    if(a==b) return;
    if(sizes[a]>sizes[b]) swap(a, b);
    parents[a] = b;
    sizes[b] += sizes[a];
}

ll expo(ll a, ll b){
    if(b==0 or a==1) return 1;
    return ((ll)(b%2==1 ? a : 1) * (ll)expo((a*a)%MOD, b/2))%MOD;
}

void solve()
{
    int n; cin >> n;
    int S; cin >> S;
    vvint edges;
    for(int i = 0; i < n-1; i++){
        int a; cin >> a;
        int b; cin >> b;
        int w; cin >> w;
        edges.pb({w, a-1, b-1});
    }
    sort(all(edges));
    
    parents = vint(n, -1);
    for(int i = 0; i < n; i++) parents[i] = i;
    sizes = vint(n, 1);
    ll out = 1;
    // cout << n << ln;
    for(int i = 0; i < n-1; i++){
        int a = get(edges[i][1]);
        int b = get(edges[i][2]);
        if(a==b) continue;
        ll added = ((ll)sizes[a] * (ll)sizes[b]) - 1;
        ll available = S-edges[i][0];

        // cout << available+1 << ' ' << added << ln;
        // cout << available+1 << ' ' << added << ' ' << (ll)expo(available+1, added) << ln;
        merge(a, b);
        // if(added==0 or available==0) continue;
        out*=(ll)expo(available+1, added);
        out%=MOD;
    }
    
    cout << out << ln;
}
int main()
{
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