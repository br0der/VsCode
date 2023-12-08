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

bool isDig(string s){
    for(int i = 0; i < sz(s); i++){
        if(not isdigit(s[i])) return false;
    }
    return true;
}

ll toLong(string s){
    ll out = 0;
    for(int i = 0; i < sz(s); i++){
        out*=10;
        out+=s[i]-'0';
    }
    return out;
}

void solve()
{
    string s;
    cin >> s;
    cin >> s;
    vint time;
    vint dist;
    string tm;
    string d;
    while(isDig(s)){
        // cout << s << ln;
        tm+=s;
        cin >> s;
    }
    cin >> s;
    while(isDig(s)){
        // cout << s << ln;
        d+=s;
        cin >> s;
    }
    // int out = 1;
    ll tm2 = toLong(tm);
    ll d2 = toLong(d);
    ll n = 0;
    // cout << tm2 << ' '<< d2 << ln;
    for(ll j = 0; j < tm2; j++){
        if((tm2-j)*j>=d2){
            n++;
        }
    }
    
    cout << n << ln;
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