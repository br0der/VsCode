#include <bits/stdc++.h> 
#include <iostream>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

// Written by: Brady Aber
// UCF SI Camp: Contest 3
// 7/9/24
// calendar.cpp

void solve()
{
    int n; cin >> n;
    vint lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];

    vector<bool> seen(7*30*365/5);
    for(int i = 0; i < n; i++){
        // For simplicity, we can take our original bound of 10^9 and reduce it under modulo
        // to under the lcm(7, 30, 265), which is about 10^4.
        int md = lis[i]%(7*30*365/5);

        // The idea of this solution is finding the "complement", which is any number which
        // adds to the lcm of 7, 30 and 365.
        if (md == 0 || seen[(7*30*365/5) - md]) {
            // If we can find the complement, or a single number is a multiple, end early.
            cout << ":)" << ln;
            return;
        }
        seen[md] = true;
    }
    cout << ":(" << ln;
}
int main()
{
    fast_cin();
    // #ifndef ONLINE_JUDGE
    //     freopen("calendar_small.in","r", stdin);
    //     freopen("calendar_small.out","w", stdout);
    // #endif
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}