#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main(){ 
    

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vector<int> lis(n); rep(i, n) cin >> lis[i];
        sort(lis.begin(), lis.end());
        do {
            rep(i, n) cout << lis[i] << ' ';
            cout << endl;
        } while(next_permutation(lis.begin(), lis.end()));
    }
    return 0;
}