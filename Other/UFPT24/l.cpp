#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

vector<long long> heights;

long long watercalc(long long h) {
    long long out = 0;
    rep(i, heights.size()) {
        out+=max((long long)0, h-heights[i]);
    }
    return out;
}

int main(){ 
    int tc; cin >> tc;
    while (tc--) {
        long long n, x; cin >> n >> x;
        heights = vector<long long>(n); rep(i, n) cin >> heights[i];
        sort(heights.begin(), heights.end());

        long long lo = 0, hi = 2000000000, ans = -1;
        while (lo <= hi) {
            long long mid = (lo+hi)/2;
            if (watercalc(mid) > x) {
                hi = mid-1;
            }
            else {
                lo = mid+1;
                ans = mid;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}