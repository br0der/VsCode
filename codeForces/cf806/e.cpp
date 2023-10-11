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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<double> vdouble;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvlong;
typedef vector<vector<double>> vvdouble;
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb(x) (push_back(x))

int l;

pii rotate(pii point){
    // cout << point.first << ' ' << point.second << "  " << l-point.second-1 << ' ' << point.first << endl;
    return {l-point.second-1, point.first};
}

void solve()
{
    cin >> l;
    vector<string> grid(l);
    for(int i = 0; i < l; i++){
        cin >> grid[i];
    }
    int out = 0;
    for(int i = 0; i < (l+1)/2; i++){
        for(int j = 0; j < l/2; j++){
            pii start = {i, j};
            int count = grid[start.first][start.second]-'0';
            for(int i = 0; i < 3; i++){
                start = rotate(start);
                // cout << start.first << ' '
                count += grid[start.first][start.second]-'0';
            }
            // cout << min(count, 4-count) << ' ' << i << ' ' << j << endl;
            out+=min(count, 4-count);
        }
    }
    cout << out << endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}