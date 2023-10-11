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
    string s; cin >> s;
    int sorted = -1;
    int currlen = 0;
    int unsorted = 1e8;
    for(int i = 0; i < sz(s); i++){
        if(s[i]=='+') currlen++;
        else if(s[i]=='-'){
            if(unsorted==currlen) unsorted=1e8;
            currlen--, sorted = min(sorted, currlen);
        } 
        else if(s[i]=='1'){
            if(currlen<2) continue;
            if(unsorted!=1e8){
                cout << "NO" << ln;
                return;
            }
            sorted = max(sorted, currlen);
        }
        else{
            if(currlen<2){
                cout << "NO" << ln;
                return;
            }
            if(sorted==currlen){
                cout << "NO" << ln;
                return;
            }
            unsorted = min(unsorted, currlen);
        }
    }
    cout << "YES" << ln;
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