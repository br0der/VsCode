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
    string instr; cin >> instr;
    map<string, pair<string, string>> mp;
    string s; cin >> s;
    while(s!="."){
        string k = s;
        cin >> s; cin >> s;
        pair<string, string> p;
        p.first = s.substr(1, 3); cin >> s;
        p.second = s.substr(0, 3); cin >> s;
        mp.insert({k, p});
    }
    

    vector<string> curr;
    for(auto s = mp.begin(); s != mp.end(); s++){
        if(s->first[2]=='A') curr.pb(s->first);
    }
    vlong vals;
    for(int i = 0; i < sz(curr); i++){
        int cnt = 0;
        while(curr[i][2]!='Z'){
            if(instr[cnt%sz(instr)]=='L') curr[i] = mp[curr[i]].first;
            else curr[i] = mp[curr[i]].second;
            cnt++;
        }
        vals.pb(cnt);
    }
    ll out = vals[0];
    for(int i = 1; i < sz(vals); i++){
        ll g = __gcd(out, vals[i]);
        out = out*vals[i]/g;
    }
    for(int i = 0; i < sz(vals); i++) cout << vals[i] << ' ';
    cout << ln;
    cout << out << ln;
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../data/input.txt","r", stdin);
        freopen("../data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}