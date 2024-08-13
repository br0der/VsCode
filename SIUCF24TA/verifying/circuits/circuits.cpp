#include <bits/stdc++.h>
#include <queue>
#include <iostream>
using namespace std;

using pii = pair<int, int>;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> sensors(k);
    for(int i = 0; i < k; i++) {
        cin >> sensors[i];
        sensors[i]--;
    }

    vector<vector<pii>> radj(n);
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        radj[v].emplace_back(u, w);
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, 0);
    vector<int> dist(n, 2e9);
    dist[0] = 0;

    while(!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if(d > dist[cur]) continue;

        for(auto [nxt, wt]: radj[cur]) {
            int nxtD = d + wt;
            if(nxtD >= dist[nxt]) continue;
            dist[nxt] = nxtD;
            pq.emplace(nxtD, nxt);
        }
    }

    long long res = 0;
    for(int i: sensors)
        res += dist[i];
    
    cout << res << '\n';
}

int main() {
    int c; cin >> c;
    while(c--) solve();
    return 0;
}