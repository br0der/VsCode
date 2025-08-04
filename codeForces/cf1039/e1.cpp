#include <bits/stdc++.h>
#include <iostream>
#include <queue>

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, a, b) for (int i = a; i < b; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define sz(x) (long long)(x).size()
#define ll long long
#define int long long

using namespace std;
int MOD = 998244353;

int n, k; 
vector<int> a;

pair<int, int> check(int mid) {
    vector<pair<int, int>> bestPref(n, {0, 1});
    if (a[0]>=mid) bestPref[0].second--;
    rep(i, n) if (a[i]>=mid) bestPref[i].first++;
    rep2(i, 1, n) {
        if (bestPref[i].first) {
            bestPref[i].first = bestPref[i-1].first+1;
            bestPref[i].second = bestPref[i-1].second;
        }
        else {
            bestPref[i].first = bestPref[i-1].first-1;
            bestPref[i].second = bestPref[i-1].second;
            if (bestPref[i].first < 0) {
                bestPref[i] = {0, i+1};
            }
        }
        
    }
    int acc = 0;
    rep(i, k-1) {
        acc+=a[i]>=mid? 1:-1;
    }

    pair<int, int> out = {-1, -1};
    rep(i, n-k+1) {
        acc+=a[i+k-1]>=mid? 1:-1;

        int score = acc;

        if (i!=0) {
            score+=bestPref[i-1].first;
            if (score >= 0) out = {bestPref[i-1].second+1, i+k};
        }
        else if (score>=0) out = {i+1, i+k};

        acc-=a[i]>=mid? 1:-1;
    }

    return out;
}

signed main() {
    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> k;
        a = vector<int>(n);rep(i, n) cin >> a[i];
        int lo = 1, hi = n, ans2 = -1;
        pair<int, int> ans = {-1, -1};
        while (lo<=hi){
            int mid = (lo+hi)/2;
            auto res = check(mid);
            if (res.first!=-1) {
                ans2 = mid;
                ans = res;
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }
        assert(ans2!=-1);
        assert(ans.second-ans.first+1 >= k);
        cout << ans2 << ' ' << ans.first << ' ' << ans.second << endl;
    }
}