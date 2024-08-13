#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
ll MOD = 1000000007;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

// Written by: Brady Aber
// UCF SI Camp 2024: Contest ?
// 7/9/24
// intense.cpp

vvint dp;

ll func(int x, int y) {
    // There are some cases where you would want a negative y
    // coordinate, in which case it is the same if it is positive
    y = abs(y);

    // If you ever pass the "line of no return" you have definitely
    // gotten off the shortest path.
    if (x < y) return 0;

    // There is only one shortest path if you are at the end or on the diagonal.
    if ((x == 0 and y == 0) or x == y) return 1;


    if (dp[x][y] == -1) {
        // Since x > y, we always have to make progress in the x direction.
        dp[x][y] = func(x - 1, y) + func(x - 1, y - 1) + func(x - 1, y + 1);
        dp[x][y] %= MOD;
    }

    return dp[x][y];
}

void solve()
{
    int xn; cin >> xn;
    int yn; cin >> yn;
    int xh; cin >> xh;
    int yh; cin >> yh;
    
    // We can simplify the problem by only looking at 
    // the difference in x and y.
    int dx = abs(xn - xh);
    int dy = abs(yn - yh);

    // We always want to guarentee that the X is the
    // bigger of the two variables
    cout << func(max(dx, dy), min(dx, dy)) << ln;
}

int main()
{
    fast_cin();
    
    // #ifndef ONLINE_JUDGE
    //     freopen("../../data/input.txt","r", stdin);
    //     freopen("../../data/output.txt","w", stdout);
    // #endif
    dp = vvint(1001, vint(1001, -1));
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}