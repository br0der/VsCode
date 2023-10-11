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

vint dp;
int n, k, f;
vector<set<int>> allergies;

int func(int mask){
    set<int> items;
    for(int i = 0; i < n; i++) items.insert(i);
    for(int i = 0; i < f; i++){
        if(mask&(1<<i)){
            for(int item : allergies[i]){
                items.erase(item);
            }
        }
    }
    
}

void solve()
{
    cin >> n >> k >> f;
    dp = vint(1<<f, -1);
    for(int i = 0; i < f; i++){
        int count; cin >> count;
        set<int> temp;
        for(int i = 0; i < count; i++){
            int a; cin >> a;
            temp.insert(a);
        }
        allergies.pb(temp);
    }
    cout << func(0) << endl;
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