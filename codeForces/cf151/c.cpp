#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvlong;
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

string solve()
{
    vint locations[10];
    string db;
    int pl;
    string lower, upper;
    cin >> db;
    cin >> pl;
    cin >> lower;
    cin >> upper;
    for (size_t i = 0; i < sz(db); i++)
    {
        locations[db[i]-'0'].push_back(i);
    }
    int currIdx = -1;
    for (size_t i = 0; i < pl; i++)
    {
        int nextIdx = -1;
        for (size_t j = lower[i]-'0'; j <= upper[i]-'0'; j++)
        {
            // cout << i << j << currIdx << locations[j][upper_bound(locations[j].begin(), locations[j].end(), currIdx)-locations[j].begin()] <<  endl;
            auto temp = upper_bound(locations[j].begin(), locations[j].end(), currIdx);
            if(temp!=locations[j].end()){
                nextIdx = max(nextIdx, locations[j][temp-locations[j].begin()]);
            }
            else{
                return "YES";
            }
        }
        currIdx = nextIdx;
    }
    return "NO";
}
void solve_print()
{
    cout << solve() << endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    int t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve_print();
    }
    return 0;
}