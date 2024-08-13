#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vlong;
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

// Written by: Brady Aber
// SI Camp 2024: Contest 2
// 7/8/24
// permutations.cpp

void solve()
{
    int n; cin >> n;
    vlong lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];

    // Sum calculation for the end
    ll s = 0;
    for(int i = 0; i < n; i++){
        s+=lis[i];
    }

    // Instead of counting down on what I could lose, why don't we look at what we can gain
    // by shifting a permutation by i. Left or right doesn't matter, because we only care
    // about the max.
    vlong off(n, 0);
    for(int i = 0; i < n; i++){
        // In simple terms, ((lis[i]-1)-i + n) % n is how many times we have to shift left 
        // in order to get it to its correct spot
        off[((lis[i]-1)-i + n) % n]+=lis[i];
    }

    ll out = INF;
    for(int i = 0; i < n; i++){
        out = min(out, s - off[i]);
    }

    cout << out << ln;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("permutations_sample.in","r", stdin);
        freopen("permutations_sample.out","w", stdout);
    #endif
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}