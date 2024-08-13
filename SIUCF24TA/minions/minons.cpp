//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>

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
// minions.cpp

void solve()
{
    int n; cin >> n;
    // Lets separate the people and TAs, the combine them later.
    vector<pair<int, string> > people;
    vector<pair<int, string> > tas;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        int score; cin >> score;
        // Separating them.
        if (sz(str) >= 2 && str.substr(0, 2)=="TA") {
            // Use the negative score, so we can use the default c++ sorting.
            tas.emplace_back(-score, str);
        }
        else{
            // Use the negative score, so we can use the default c++ sorting.
            people.emplace_back(-score, str);
        }
    }
    // Sort both, increasing score then decreasing string.
    sort(all(people));
    sort(all(tas));
    for(int i = 0; i < sz(people); i++){
        cout << people[i].second << ln;
    }
    for(int i = 0; i < sz(tas); i++){
        cout << tas[i].second << ln;
    }
}
int main()
{
    fast_cin();
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}