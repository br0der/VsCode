#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main(){ 
    int tc; cin >> tc;
    while (tc--) {
        string n; cin >> n;
        vector<string> out;
        rep(i, n.size()) {
            if (n[i]!='0') {
                string a = "";
                a+=n[i];
                rep(j, n.size()-i-1) {
                    a+='0';
                }
                out.push_back(a);
            }
        }
        cout << out.size() << endl;
        rep(i, out.size()) {
            cout << out[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}