#include <bits/stdc++.h>
#include <iostream>

using namespace std;
long long MOD = 1e9+7;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(){ 
    long long psum = 1, prevAnsPsum = 1;
    vector<long long> ans(1, 1);
    rep (ii, 1e6) {
        int i = ii+1;
        
        ans.push_back((psum+prevAnsPsum)%MOD);
        psum*=3;
        psum%=MOD;
        psum+=ans[i];
        prevAnsPsum+=ans[i];
        psum%=MOD;
    }
    

    int tc; cin >> tc;
    while (tc--) {
        int a; cin >> a;
        cout << ans[a] << endl;
    }
    return 0;
}