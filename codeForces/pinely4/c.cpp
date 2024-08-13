//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<double> vdouble;
typedef vector<vector<int> > vvint;
typedef vector<vector<ll> > vvlong;
typedef vector<vector<double> > vvdouble;
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
    vlong lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    int odd = lis[0]%2;
    for(int i = 1; i < n; i++){
        if(lis[i]%2!=odd) {
            cout << -1 << ln;
            return;
        }
    }
    cout << 31+odd << ln;
    ll mid = (1024*1024*1024)/2;
    while(mid!=0) {
        cout << mid+odd << ' ';
        for(int i = 0; i < n; i++){
            lis[i] = abs(lis[i]-mid-odd);
        }
        mid/=2;
    }
    for(int i = 0; i < n; i++){
        lis[i] = abs(lis[i]-1);
    }
    cout << 1 << ' ';
    if (odd){
        for(int i = 0; i < n; i++){
            lis[i] = abs(lis[i]-1);
        }
        cout << 1 << ' ';
    }
    cout << ln;
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