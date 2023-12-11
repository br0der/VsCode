#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
string ln = "\n";

ll func(ll n){
    return (n*(n+1))/2;
}

void solve()
{
    ll n; cin >> n;
    ll k; cin >> k;
    ll total = func(n);
    // Idea: instead of looping through each of the people in the raffle, 
    // (O(n) where n = 10^9 is too slow, 10^6 or 7 is the cap for 1 second)
    // you can use the sum of consecutive numbers formula:
    // Sum of all numbers [1:n] = n*(n+1)/2
    // and compute in O(1) time the range of tickets that the ith person will have.
    // Ex n = 6 finding the 20th ticket, you compute the total (21), then binary search
    // to find which person will contain the 20th ticket.
    ll lo = 1, hi = n, ans = -1;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        ll a = n-mid+1;
        ll b = total-func(a-1);
        if(b>=k){
            hi = mid-1;
            ans = mid;
        }
        else{
            lo = mid+1;
        }
    }
    cout << ans << ln;
}
int main()
{
    // I use this to take in input from a file, if you take input differently
    // feel free to omit. I though I would keep it in just in case you wanted to
    // try it out
    // #ifndef ONLINE_JUDGE
    //     freopen("../../data/input.txt","r", stdin);
    //     freopen("../../data/output.txt","w", stdout);
    // #endif
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}