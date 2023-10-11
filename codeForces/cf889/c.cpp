#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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



void solve()
{
    int n; cin >> n;
    vlong lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    vvint out;
    int mxI = max_element(all(lis))-lis.begin();
    int mnI = min_element(all(lis))-lis.begin();
    int negCount = 0;
    for(int i = 0; i < n; i++){
        if(lis[i]<0){
            negCount++;
        }
    }
    int posCount = 0;
    for(int i = 0; i < n; i++){
        if(lis[i]>0){
            posCount++;
        }
    }
    if(lis[mnI]<0 and ((lis[mxI]>-lis[mnI])*5 + posCount) <= 12){
        if(-lis[mnI]<lis[mxI]){
            for(int i = 0; i < 5; i++){
                out.push_back({mnI+1, mnI+1});
                lis[mnI]*=2;
            }
        }
        for(int i = 0; i < n; i++){
            if(lis[i]>0){
                lis[i]+=lis[mnI];
                out.push_back({i+1, mnI+1});
            }
        }
        for(int i = n-1; i >= 1; i--){
            if(lis[i]<lis[i-1]){
                lis[i-1]+=lis[i];
                out.push_back({i, i+1});
            }
        }
    }
    else{
        if(-lis[mnI]>lis[mxI]){
            for(int i = 0; i < 5; i++){
                out.push_back({mxI+1, mxI+1});
                lis[mxI]*=2;
            }
        }
        for(int i = 0; i < n; i++){
            if(lis[i]<0){
                lis[i]+=lis[mxI];
                out.push_back({i+1, mxI+1});
            }
        }
        for(int i = 1; i < n; i++){
            if(lis[i]<lis[i-1]){
                lis[i]+=lis[i-1];
                out.push_back({i+1, i});
            }
        }
    }
    if(sz(out)>31) cout << 1/(0*0) << endl;
    cout << sz(out) << endl;
    for(int i = 0; i < sz(out); i++){
        cout << out[i][0] << ' ' << out[i][1] << endl;
    }
    // for(int i = 0; i < n; i++){
    //     cout << lis[i] << ' ';
    // }
    // cout << endl;
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