//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>
#include <set>

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


int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif

    // vector<bool> prime(1000000, true);
    // prime[1] = false;
    // for(int i = 2; i*i <= 1000000; i++){
    //     if(!prime[i]) continue;
    //     for(int j = i*2; j < 1000000; j+=i){
    //         prime[j] = false;
    //     }
    // }
    // cout << ln;
    // vint ks;
    // vint ans;
    // ks.pb(0);
    // ans.pb(0);
    // ks.pb(1);
    // ans.pb(1);
    // for(int i = 2; i < 100; i++){
    //     set<int> colors;
    //     for(int j = 1; j < i; j++){
    //         if (prime[i^j]) {
    //             colors.insert(ans[j]);
    //         }
    //     }
    //     if (sz(colors)==ks[i-1]) {
    //         ks.pb(ks[i-1]+1);
    //     }
    // }
    ll t; cin >> t;
    while(t--){
        int n; cin >> n;
        if (n <= 5) {
            cout << (n+2)/2 << ln;
            for(int i = 0; i < n; i++){
                cout << (i+3)/2 << ' ';
            }
            cout << ln;
        }
        else {
            cout << 4 << ln;
            for(int i = 0; i < n; i++){
                cout << i%4 + 1 << ' ';
            }
            cout << ln;
        }
    }
    return 0;
}