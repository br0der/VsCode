#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << max(2*((a+c-1)/c)-1, 2*((b+c-1)/c)) << endl;
    }
}