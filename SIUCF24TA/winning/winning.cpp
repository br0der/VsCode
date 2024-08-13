#include <bits/stdc++.h> 
#include <iostream>

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
// winning.cpp

void solve()
{
    // We can solve this problem using greedy, starting with the earliest
    // in this case, then cheating in the next competition you are able to
    // given the last competition you cheated in.

    int n; cin >> n;
    int k; cin >> k;
    assert(1<=n && n<= 100000);
    vint lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    
    sort(all(lis));

    // Assuming you already have taken the first one, which you always can.
    int score = 1;
    int last = lis[0];

    for(int i = 1; i < n; i++){
        assert(lis[i]!=lis[i-1]);
        if (last + k < lis[i]) {
            // If you are able to take this, take it.
            score++;
            last = lis[i];
        }
    }

    cout << score << ln;
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("winning_small.in","r", stdin);
        freopen("winning_small.out","w", stdout);
    #endif
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}