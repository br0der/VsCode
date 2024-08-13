#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";


void solve()
{
    /*
    It can be proven that if you start on a number that is not prime or 9, 
    you can win. You can also win on 3.
    One winning strategy is taking a number and turning it into its 
    lowest prime factor that isn't 3. For example, 15 = 3*5, and you can 
    subtract 10 because gcd(15, 10) = 5, leaving you with 5. 
    
    This works because the opponent has significantly fewer choices when 
    at a prime, as they can always only subtract 1. This is except for 3,
    because it is the only prime that is one greater than a previous prime. 
    9 is not winning, because the only primes you can reduce it to is 3, 
    and subtracting 1 or 3 leaving 8 or 6 is winning for the opponent. 
    Higher powers of 3 can all be reduced to 9, which is losing for the 
    opponent.
    */

    ll num; cin >> num;
    char c; cin >> c;

    // One is not prime.
    bool prime = num != 1;

    // Primality check for the number
    for(ll i = 2; i*i <= num; i++){
        if (num%i == 0) {
            prime = false;
        }
    }

    bool lose = (prime && num!=3) || num == 9;

    // If virgil starts and the first player loses, print Teams.
    // If virgil starts and the second player loses, print Email.
    // If pavlu starts and the first player loses, print Email.
    // If pavlu starts and the second player loses, print Teams.
    cout << ((lose==(c=='V'))? "Teams" : "Email") << endl;
}
int main()
{
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}