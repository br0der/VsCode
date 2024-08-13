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

// Written by: Brady Aber
// UCF SI Camp 2024
// 7/15/24
// movie.cpp

void solve()
{
    int M; cin >> M;
    int d; cin >> d;

    vint lis(M); for(int _ = 0; _ < M; _++) cin >> lis[_];

    // Lets store a list of booleans, representing if we can create every number thus far.
    vector<bool> canMake(d + 1);
    // We can make zero
    canMake[0] = true;

    int ans = 0;

    for(int i = 0; i < M; i++){
        // If we went through every index it would be a bit slower, and also is just wasted time.
        // We can start at the max index that would actually lead us to reaching the end if 
        // it were creatable.
        for(int j = d - lis[i]; j >= 0; j--){
            if (canMake[j]) {
                canMake[j+lis[i]] = true;
                ans = max(ans, j+lis[i]);
            }
        }
    }
    // We have been counting the max number we can create, so lets invert it.
    cout << d-ans << ln;
}
int main()
{
    fast_cin();
    // #ifndef ONLINE_JUDGE
    //     freopen("movie_small.in","r", stdin);
    //     freopen("myout.out","w", stdout);
    // #endif
    ll t; cin >> t;
    assert(1 <= t && t <= 25);
    while(t--) solve();
    return 0;
}