#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

int query(int l, int r) {
    if (l == r) return 0;
    cout << "? " << l << ' ' << r << endl;
    
    int res;
    cin >> res;
    return res;
}

// Finds max on p[l; r]
int solve(int l, int r) {
    if (l == r) return l;
    
    int m = (l + r) / 2;
    int a = solve(l, m);
    int b = solve(m + 1, r);
    
    int r1, r2;
    r1 = query(a, b - 1);
    r2 = query(a, b);
    
    if (r1 == r2) {
        return b;
    } else {
        return a;
    }
}

void solve() {
    int n;
    cin >> n;
    
    int ans = solve(1, n);
    cout << "! " << ans << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}