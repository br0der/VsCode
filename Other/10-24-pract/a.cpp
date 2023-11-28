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

ll newNum(ll x){
    vint nums;
    while(x>0){
        nums.pb(x%10);
        x/=10;
    }
    ll out = 0;
    for(int i = 0; i < sz(nums); i++){
        out*=10;
        if(nums[i] == 0 or nums[i] == 1 or nums[i] == 2 or nums[i] == 5 or nums[i] == 8){
            out+=nums[i];
        }
        else if(nums[i] == 6){
            out+=9;
        }
        else if(nums[i] == 9){
            out+=6;
        }
        else{
            return -1;
        }
    }
    return out;
}

void solve()
{
    ll n; cin >> n;
    ll k; cin >> k;
    set<ll> s;
    bool works = false;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        // cout << newNum(x) << ln;
        if(s.count(k-x) or s.count(k-newNum(x))){
            // cout << x << ln;
            works = true;
        }
        s.insert(x);
        s.insert(newNum(x));
    }
    cout << (works? "YES" : "NO") << ln;
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}