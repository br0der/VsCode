#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vector<bool> bottom(n+1, false), top(n+1, false);
        rep(i, n) {
            int a, b; cin >> a >> b;
            if (b==0) bottom[a] = true;
            else top[a] = true;
        }
        long long out = 0;
        int seenB = 0, seenT = 0;
        rep(i, n+1) {
            if (bottom[i] and top[i]) out+=seenB+seenT;
            if (bottom[i]) seenB++;
            if (top[i]) seenT++;
        }

        seenB = 0, seenT = 0;
        rep(ii, n+1) {
            int i = n-ii;
            if (bottom[i] and top[i]) out+=seenB+seenT;
            if (bottom[i]) seenB++;
            if (top[i]) seenT++;
        }

        rep (i, n-1) {
            if (bottom[i+1] and top[i] and top[i+2]) out++; 
            if (top[i+1] and bottom[i] and bottom[i+2]) out++; 
        }
        cout << out << endl;
    }

    return 0;
}