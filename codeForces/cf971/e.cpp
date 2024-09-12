#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

long long n, k;


long long calc(long long i) {
    long long val = 0;
    val+=k*(i+1 - (n-i-1));
    val+=(i*(i+1))/2;
    val-=(n*(n-1))/2 - ((i+1)*i)/2;
    return val;
}

int main() {
    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> k;
        long long lo = 0, hi = n-1, ans = -1;
        while (lo <= hi) {
            long long mid = (lo+hi)/2;
            // cout << lo << ' ' << hi << endl;
            if (calc(mid) >= 0) {
                ans = mid;
                hi = mid-1;
            }
            else { 
                lo = mid+1;
            }
        }
        cout << min(abs(calc(ans)), abs(calc(ans-1))) << endl;
    }
    return 0;
}