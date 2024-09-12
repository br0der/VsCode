#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int a; cin >> a;
        vector<int> out;
        rep(i, a) {
            string s; cin >> s;
            if (s[0]=='#') out.push_back(1);
            if (s[1]=='#') out.push_back(2);
            if (s[2]=='#') out.push_back(3);
            if (s[3]=='#') out.push_back(4);
        }
        reverse(out.begin(), out.end());
        rep(i, a) {
            cout << out[i] << ' ';
        }
        cout << endl;
    }
}