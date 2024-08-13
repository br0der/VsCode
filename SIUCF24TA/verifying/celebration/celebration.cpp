#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node {
    int lo, md, hi;
    int sum = 0;
    node *left, *right;
    node(int L, int R): lo(L), md((L+R)/2), hi(R) {
        if(L == R) return;
        left = new node(lo, md);
        right = new node(md+1, hi);
    }
    void update(int idx, int d) {
        if(lo == hi) {
            sum += d;
            return;
        }
        if(idx <= md) left->update(idx, d);
        else right->update(idx, d);
        sum = left->sum + right->sum;
    }
    int query(int L, int R) {
        // no cover
        if(R < lo || hi < L) return 0;
        // full cover
        if(L <= lo && hi <= R) return sum;
        // partial cover
        return left->query(L, R) + right->query(L, R);
    }
};

void solve() {
    int n, m, q; cin >> n >> m >> q;
    node seg_tree(0, m-1);
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x; x--;
        seg_tree.update(x, 1);
        arr[i] = x;
    }

    int shift = 0;
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int i, x; cin >> i >> x; i--;
            seg_tree.update(arr[i], -1);
            arr[i] = (arr[i] + x) % m;
            seg_tree.update(arr[i], 1);
        }
        else if(type == 2) {
            int x; cin >> x; 
            shift = (shift + x) % m;
        }
        else if(type == 3) {
            int L, R; cin >> L >> R;
            L += m-shift-1, R += m-shift-1;
            L %= m; R %= m;
            int res = 0;
            if(L <= R)
                res = seg_tree.query(L, R);
            else
                res = seg_tree.query(0, R) + seg_tree.query(L, m-1);
            cout << res << '\n'; 
        }
    }
}

int main() {
    int g; cin >> g;
    while(g--) solve();
    return 0;
}