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
    map<int, ll> mp;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        mp[temp]++;
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        ll x; cin >> x;
        ll y; cin >> y;
        ll rad = x*x - 4*y;
        if(rad<0){
            cout << 0 << ' ';
            continue;
        }
        ll rnd = round(sqrt(rad));
        ll aj1 = x+rnd;
        ll aj2 = x-rnd;
        if(rnd*rnd != rad or aj1%2==1){
            cout << 0 << ' ';
            continue;
        }
        aj1/=2; aj2/=2;
        ll ai1 = x-aj1, ai2 = x-aj2;
        ll count = 0;
        if(ai1==aj1){
            cout << (mp[ai1]*(mp[ai1]-1))/2 << ' ';
            continue;
        }
        count+=mp[ai1]*mp[aj1];
        if(ai2!=aj1 and ai1!=aj2) count+=mp[ai2]*mp[aj2];
        cout << count << ' ';
    }
    cout << ln;
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