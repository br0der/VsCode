#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main(){ 
    int n, s, l; cin >> n >> s >> l;
    vector<int> lis(n); rep(i, n) cin >> lis[i];
    int mx = lis[0], mn = lis[0], cnt = 0;
    int strips = 0;
    rep (i, n) {
        mx = max(mx, lis[i]);
        mn = min(mn, lis[i]);
        // cout << "adding " << lis[i] << endl;
        if (mx-mn > s) {
            // cout << "overflow" << endl;
            if (cnt < l) {
                // cout << i << endl;
                cout << -1 << endl;
                return 0;
            }
            mx = lis[i];
            mn = lis[i];
            int newCnt = 1;
            int backwards = i-1;
            while (cnt != l) {
                // cout << "trying to add " << lis[backwards] << endl;
                mx = max(mx, lis[backwards]);
                mn = min(mn, lis[backwards]);
                if (max(mx, lis[backwards])-min(mn, lis[backwards]) > s) {
                    // cout << "couldnt" << endl;
                    break;
                }
                else newCnt++, cnt--, backwards--;
            }
            strips++;
            cnt = newCnt;
        }
        else {
            cnt++;
        }
    }
    cout << strips+1 << endl;
    return 0;
}