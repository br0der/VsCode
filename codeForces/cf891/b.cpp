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
    string n; cin >> n;
    int increase = -2;
    for(int i = 0; i < sz(n); i++){
        if(int(n[i])-'0'>=5){
            increase = i-1; break;
        }
    }
    if(increase==-2){
        cout << n << endl;
        return;
    }
    while(increase>=0 and n[increase]=='4') increase--;
    if(increase==-1){
        cout << '1';
        for(int i = 0; i < sz(n); i++){
            cout << '0';
        } 
        cout << ln;
        return;
    }
    for(int i = 0; i < increase; i++){
        cout << n[i];
    }
    cout << char(n[increase]+1);
    for(int i = increase+1; i < sz(n); i++){
        cout << '0';
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