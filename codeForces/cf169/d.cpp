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

int enc(string s) {
    // BG, BR, BY, GR, GY, or RY
    if (s=="BG") {
        return 0;
    }
    if (s=="BR") {
        return 1;
    }
    if (s=="BY") {
        return 2;
    }
    if (s=="RY") {
        return 3;
    }
    if (s=="GY") {
        return 4;
    }
    if (s=="GR") {
        return 5;
    }
    cout << s << ln;
    return -1;
}

void solve()
{
    int n; cin >> n;
    int q; cin >> q;
    vvint prefEqDist(6);
    vvint postEqDist(6);
    vector<string> temp(n);
    vint vals;
    for(int i = 0; i < n; i++){
        cin >> temp[i];
        vals.pb(enc(temp[i]));
    }
    for(int i = 0; i < 6; i++){
        prefEqDist[i].pb(1e9+1);
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 6; j++){
            if (j==vals[i-1]) {
                prefEqDist[j].pb(1);
            }
            else {
                prefEqDist[j].pb(prefEqDist[j][i-1]+1);
            }
        }
    }
    for(int i = 0; i < 6; i++){
        postEqDist[i].pb(1e9+1);
    }
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j < 6; j++){
            if (j==vals[i+1]) {
                postEqDist[j].pb(1);
            }
            else {
                postEqDist[j].pb(postEqDist[j][n-i-2]+1);
            }
        }
    }
    for(int i = 0; i < 6; i++){
        reverse(all(postEqDist[i]));
    }
    
    // for(int i = 0; i < 6; i++){
    //     for(int j = 0; j < sz(prefEqDist[i]); j++) cout << prefEqDist[i][j] << ' ';
    //     cout << ln;
    // }
    // for(int i = 0; i < 6; i++){
    //     for(int j = 0; j < sz(postUniqueDist[i]); j++) cout << postUniqueDist[i][j] << ' ';
    //     cout << ln;
    // }

    for(int i = 0; i < q; i++){
        int a; cin >> a;
        int b; cin >> b;
        a--, b--;
        if (a > b) swap(a, b);
        if (a==b) cout << 0 << ln;
        else {
            if (abs(vals[a]-vals[b])!=3) {
                cout << b-a << ln;
            }
            else {
                int early = 1e9;
                int late = 1e9;
                for(int j = 0; j < 6; j++){
                    if (j%3!=vals[a]%3) {
                        late = min(late, postEqDist[j][a]);
                    }
                    if (j%3!=vals[b]%3) {
                        early = min(early, prefEqDist[j][b]);
                    }
                }
                if (early >= 1e9 and late >= 1e9) {
                    cout << -1 << ln;
                    continue;
                }
                // cout << early << ' ' << late << ln;
                if (b-early >= a or late+a <= b) {
                    cout << b-a << ln;
                }
                else {
                    cout << min(early + (a-(b-early)), late + ((a+late)-b)) << ln;
                }
            }
            
        }

    }
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