#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main(){ 
    freopen("bcount.in","r", stdin);
    freopen("bcount.out","w", stdout);
    int n, q; cin >> n >> q;
    vector<int> sum1(1, 0), sum2(1, 0), sum3(1, 0);
    rep(i, n) {
        int a; cin >> a;
        sum1.push_back(sum1[i]);
        sum2.push_back(sum2[i]);
        sum3.push_back(sum3[i]);
        if (a==1) sum1[i+1]++;
        if (a==2) sum2[i+1]++;
        if (a==3) sum3[i+1]++;
    }
    // rep(i, n+1) cout << sum1[i] << ' ';
    // cout << endl;
    rep(i, q) {
        int a, b; cin >> a >> b;
        // cout << a << ' ' << b << endl;
        cout << sum1[b]-sum1[a-1] << ' ' << sum2[b]-sum2[a-1] << ' ' << sum3[b]-sum3[a-1] << endl;
    }
    
    return 0;
}