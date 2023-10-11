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
 

char solve()
{
    string grid[3];
    for (size_t i = 0; i < 3; i++)
    {
        cin >> grid[i];
    }
    for (size_t i = 0; i < 3; i++)
    {
        // cout << grid[0][2] << endl;
        if(grid[0][i] == grid[1][i] and grid[1][i]== grid[2][i] and grid[0][i]!='.'){
            return grid[0][i];
        }
        if(grid[i][0]==grid[i][1] and grid[i][1]== grid[i][2] and grid[i][0]!='.'){
            return grid[i][0];
        }
    }
    if(grid[0][0]==grid[1][1] and grid[1][1] == grid[2][2] and grid[0][0]!='.'){
        return grid[0][0];
    }
    if(grid[2][0]==grid[1][1] and grid[1][1] == grid[0][2] and grid[2][0]!='.'){
        return grid[2][0];
    }
    return ' ';
}
void solve_print()
{
    char temp = solve();
    if(temp==' '){
        cout << "DRAW" << endl;
    }
    else{
        cout << temp << endl;
    }
    
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve_print();
    }
    return 0;
}