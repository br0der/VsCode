//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<double> vdouble;
typedef vector<vector<int> > vvint;
typedef vector<vector<ll> > vvlong;
typedef vector<vector<double> > vvdouble;
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

// Written by: Brady Aber
// UCF SI Camp 2024
// 7/16/24
// toomuchcrypto.cpp

map<char, char> substitution;

// Function to make applying the cipher easier.
string apply(string s) {
    string out = "";
    for(int i = 0; (ll)i < sz(s); i++){
        out+=substitution.at(s[i]);
    }
    return out;
}

void solve()
{
    string plain; cin >> plain;
    string cipher; cin >> cipher;

    int k; cin >> k;
    
    // Make a map of the cipher
    substitution.clear();
    for(int i = 0; i < 26; i++) {
        substitution[char(i + 'a')] = cipher[i];
    }

    // Because there are so few letters, the cycle length will be very small.
    string last = apply(plain);
    int cycles = 1;
    while (last != plain) {
        last = apply(last);
        cycles++;
    }

    // After {cycles} ciphers, the word will loop back to the beginning. So k is the same as k%cycles
    k%=cycles;

    // Apply it k%cycles times
    for(int i = 0; i < k; i++){
        plain = apply(plain);
    }
    cout << plain << ln;
}
int main()
{
    fast_cin();

    ll t; cin >> t;
    while(t--) solve();
    return 0;
}