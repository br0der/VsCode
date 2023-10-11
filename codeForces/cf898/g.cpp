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
    int n = sz(s);
    vector<pii> Bs;
    ll out = 0;
    for(int i = 0; i < n; i++){
        if(s[i]=='B'){
            int left = i, right = i;
            while(left>0 and s[left-1]=='A')left--;
            while(right<n-1 and s[right+1]=='A')right++;
            
            Bs.pb({i-left, right-i});
            
            if(right-i==0){
                if(Bs[0].first==0){
                    for(pii curr : Bs){
                        out+=curr.second;
                    }
                }
                else{
                    // int mn = 1e6;
                    int total = 0;
                    for(int j = 0; j < sz(Bs); j++){
                        // mn = min(mn, Bs[j].first);
                        total+=Bs[j].first;
                    }
                    out+=total;
                }
                Bs = vector<pii>();
            }
        }
        // cout << i << ' ' << out << ln;
    }
    if(sz(Bs)>0){
        if(Bs[0].first==0){
            for(pii curr : Bs){
                out+=curr.second;
            }
        }
        else{
            int mn = Bs[0].first;
            int total = Bs[0].first;
            for(int j = 0; j < sz(Bs); j++){
                mn = min(mn, Bs[j].second);
                total+=Bs[j].second;
            }
            out+=total-mn;
        }
    }
    cout << out << ln;
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