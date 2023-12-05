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

vvint l1, l2;
vint update;
void solve()
{
    int out = 0;
    int copies = 0;
    for(int i = 0; i < sz(l1); i++){
        copies+=update[i];
        int cnt = 0;
        set<int> nums;
        for(int j = 0; j < sz(l1[i]); j++){
            nums.insert(l1[i][j]);
        }
        for(int j = 0; j < sz(l2[i]); j++){
            if(nums.count(l2[i][j])) cnt++;
        }
        
        if(i+cnt+1<sz(update)) {
            update[i+cnt+1]-=copies+1;
        }
        out+=copies+1;
        copies+=copies+1;
        cout << cnt << ' ' << copies << ln;
        
    }
    cout << out << ln;
}

bool isDig(string s){
    for(int i = 0; i < sz(s); i++){
        if(not isdigit(s[i])) return false;
    }
    return true;
}

int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../data/input.txt","r", stdin);
        freopen("../data/output.txt","w", stdout);
    #endif
    string s; cin >> s;
    while(s!="."){
        l1.pb(vint());
        l2.pb(vint());
        // cout << s << ln;
        while(not isDig(s)) cin >> s;
        while(isDig(s)) l1[sz(l1)-1].pb(stoi(s)), cin >> s;
        cin >> s;
        while(isDig(s)) l2[sz(l2)-1].pb(stoi(s)), cin >> s;
    }
    update = vint(sz(l1), 0);
    solve();
    return 0;
}