#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

void solve()
{
    int total; cin >> total;
    int bills; cin >> bills;
    
    assert(1 <= bills);
    assert(bills <= 200);
    assert(5*bills <= total);
    assert(total <= 10*bills);
    int fives = -1, tens = -1;

    // A brute force approach, because of the small bounds. Tries every amount of
    // fives, then reasons how many tens would be needed and checks for correctness.
    for(fives = 0; 5 * fives <= total; fives++){
        tens = bills - fives;

        // If they correctly make the total, then do no search any more.
        if (tens * 10 + fives * 5 == total) {
            break;
        }
    }

    // Throws an error if the answer doesn't make sense.
    assert(tens * 10 + fives * 5 == total);
    assert(tens + fives == bills);

    cout << fives << " " << tens << endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    int t; cin >> t;
    while(t--) solve();
    return 0;
}