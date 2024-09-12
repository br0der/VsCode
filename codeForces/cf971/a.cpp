#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int a, b; cin >> a >> b;
        cout << max(a, b) - min(a, b) << endl;
    }
}