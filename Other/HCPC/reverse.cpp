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
    string s1; cin >> s1;
    string s2; cin >> s2;
    vint pos;
    for(int i = 0; i < sz(s1); i++){
        if(s1[i]==s2[0]){
            pos.pb(i+1);
        }
    }
    bool works = true;
    for(int i = 1; i < sz(s2); i++){
        if(sz(pos)==0){
            works = false;
            break;
        }
        vint n;
        for(int j = 0; j < sz(pos); j++){
            // cout << pos[j] << ' ' << i << ln;
            if(i!=1 and abs(pos[j])-2>=0 and s1[abs(pos[j])-2]==s2[i]) n.pb((abs(pos[j])-1)*-1);
            if((pos[j]>=1) and pos[j]<sz(s1) and s1[pos[j]]==s2[i]) n.pb(pos[j]+1);
        }
        // pos.clear();
        // for(int elem : n){
        //     pos.pb(elem);
        // }
        
        swap(pos, n);
        if(sz(pos)==0){
            works = false;
            break;
        }
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
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}