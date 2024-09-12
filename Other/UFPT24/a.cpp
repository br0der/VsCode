#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main(){ 
    int tc; cin >> tc;
    while (tc--) {
        int n, m, k; cin >> n >> m >> k;
        vector<vector<int>> edges(n);
        rep (i, m) {
            int a, b; cin >> a >> b;
            edges[a-1].push_back(b-1);
        }
        vector<int> cnt(n, 0);
        cnt[0] = 2e9;
        rep (i, n) {
            rep (j, n) {
                rep (k, edges[j].size()) {
                    
                }
            }
        }
    }
    return 0;
}