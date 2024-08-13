using namespace std;
# include <bits/stdc++.h>
#include <iostream>

int main(){
    freopen("calendar_small.in","r", stdin);
    int cases; cin >> cases;

    while (cases--) {
        int n; cin >> n;
        vector<int> nums(n);
        bool earlyContinue = false;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            nums[i] = x;
            if (x >= 15330 && x % 15330 == 0) {
                cout << n << ":)\n";
                earlyContinue = true;
                break;
            }
        }
        if (earlyContinue) continue;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int sum = nums[i] + nums[j];
                if (sum % 15330 == 0) {
                    cout << n << ":)\n";
                    earlyContinue = true;
                    break;
                }
            }
            if (earlyContinue) break;
        }
        if (earlyContinue) continue;
        cout << n << ":(\n";
    }
    return 0;
}

