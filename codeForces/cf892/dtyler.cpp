#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pii>;
using vvi = vector<vi>;

void solve() {
    int n;
    cin >> n;
 
    vector<int> ans(n);
    vvi events;
    for (int i = 0 ; i < n ; i++) {
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        ans[i] = b;
        events.push_back({b, 1, i});
        events.push_back({l, -1, i});
    }
    int q;
    cin >> q;
    vector<int> queries(q);
    for (int i = 0 ; i < q ; i++) {
        int x;
        cin >> x;
        queries[i] = x;
        events.emplace_back(x, 0, i);
    }
 
    sort(all(events));
    reverse(all(events));
    multiset<int> s;
    for (vi event : events) {
        int x = event[0];
        int type = event[1];
        int ind = event[2];
        if (type == 1) {
            if (!s.empty()) {
                ans[ind] = *s.rbegin();
            }
            s.insert(ans[ind]);
        } else if (type == 0) {
            if (!s.empty()) {
                queries[ind] = max(queries[ind], *s.rbegin());
            }
        } else {
            s.erase(ans[ind]);
        }
    }
 
    for (auto el : queries)
        cout << el << " ";
    cout << "\n";
}

int main(){
    cin.tie() -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}