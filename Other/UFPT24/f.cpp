#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main(){ 
    int tc; cin >> tc;
    while (tc--) {
        long long n, k; cin >> n >> k;
        vector<long long> nums(n); rep(i, n) cin >> nums[i];
        sort(nums.begin(), nums.end());
        long long total = 0;
        rep(i, n/2) {
            int ii = n-i*2-1;
            // cout << nums[ii] << ' ' << nums[ii-1] << endl;
            long long change = nums[ii]-nums[ii-1];
            if (k > change) k-=change;
            else {
                change-=k;
                k = 0;
                total+=change;
            }
        }
        if (n%2==1) total+=nums[0];
        cout << total << endl;
    }
    return 0;
}