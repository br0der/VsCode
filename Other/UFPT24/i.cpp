#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main(){ 
    int n, q; cin >> n >> q;
    vector<long long> lis(n); rep(i, n) cin >> lis[i];
    vector<long long> changes(n+1, 0);
    rep(i, q) {
        int a, b; cin >> a >> b;
        changes[a-1]++;
        changes[b]--;
    }
    long long cnt = 0;
    vector<long long> best;
    rep(i, n) {
        cnt+=changes[i];
        best.push_back(-cnt);
    }
    // rep (i, best.size()) cout << best[i] << ' ';
    sort(best.begin(), best.end());
    sort(lis.begin(), lis.end());
    long long out = 0;
    int last = 0;
    rep (i, n) {
        out+=-best[last]*lis[n-i-1];
        // cout << -best[last]*lis[i] << endl;
        last++;
    }
    cout << out << endl;
    return 0;
}