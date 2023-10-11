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
#define pb(x) (push_back(x))



int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    int n; cin >> n;
    vlong out;
    ll j = 2, i = 1;
    while(j<n){
        if(j*j-i*i<n) j++;
        else if(j*j-i*i>n) i++;
        else{
            // cout << i << ' ' << j << endl;
            out.push_back(j);
            i++, j++;
        }
    }
    // sort(all(out));
    cout << sz(out) << endl;
    for(ll weight : out){
        cout << weight << ' ';
    }
    // for(int i = 0; i < sz(out); i++){
    //     cout << out[i];
    //     if(i!=sz(out)-1) cout << ' ';
    // }
    return 0;
}