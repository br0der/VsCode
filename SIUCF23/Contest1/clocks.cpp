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
map<int, vector<string>> nums;
void solve()
{
    string time;
    cin >> time;
    string line = "";
    for(int row = 0; row < 5; row++){
        for(int j = 0; j < 2; j++){
            line+=nums[time[j]-'0'][row];
            line+='.';
        }
        if(row!=2){
            line+="..O..";
        }
        else{
            line+=".....";
        }
        for(int j = 0; j < 2; j++){
            line+='.';
            line+=nums[time[j+3]-'0'][row];
        }
        cout << line << endl;
        line = "";
    }
    cout << endl;
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    
    nums[0] = {
        "OOOOO", 
        "O...O", 
        "O...O", 
        "O...O", 
        "OOOOO"
    };
    nums[1] = {
        "..O..", 
        "..O..", 
        "..O..", 
        "..O..", 
        "..O.."
    };
    nums[2] = {
        "OOOOO", 
        "....O", 
        "OOOOO", 
        "O....", 
        "OOOOO"
    };
    nums[3] = {
        "OOOOO", 
        "....O", 
        "OOOOO", 
        "....O", 
        "OOOOO"
    };
    nums[4] = {
        "O...O", 
        "O...O", 
        "OOOOO", 
        "....O", 
        "....O"
    };
    nums[5] = {
        "OOOOO", 
        "O....", 
        "OOOOO", 
        "....O", 
        "OOOOO"
    };
    nums[6] = {
        "OOOOO", 
        "O....", 
        "OOOOO", 
        "O...O", 
        "OOOOO"
    };
    nums[7] = {
        "OOOOO", 
        "....O", 
        "....O", 
        "....O", 
        "....O"
    };
    nums[8] = {
        "OOOOO", 
        "O...O", 
        "OOOOO", 
        "O...O", 
        "OOOOO"
    };
    nums[9] = {
        "OOOOO", 
        "O...O", 
        "OOOOO", 
        "....O", 
        "OOOOO"
    };
    // string nums[][] = {{"OOOOO", "O...O", "O...O", "O...O", "OOOOO"}, {"..O..", "..O..", "..O..", "..O..", "..O.."}};
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}