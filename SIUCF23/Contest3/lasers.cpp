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
 
string flip(string s){
    string out = "";
    for(int i = 0; i < sz(s); i++){
        out+=s[i]=='0'?'1':'0';
    }
    return out;
}

int count(string s){
    int c = 0;
    for(int i = 0; i < sz(s); i++){
        if(s[i]=='1') c++;
    }
    return c;
}

void solve()
{
    int r;
    cin >> r;
    int c;
    cin >> c;
    vector<string> grid(r);
    string forward, back;
    cin >> forward;
    grid[0] = forward;
    back = flip(forward);
    bool br = false;
    for(int i = 1; i < r; i++){
        string s;
        cin >> s;
        grid[i] = s;
        if(s!=forward and s!=back) br = true;
    }
    if(br){
        cout << "impossible" << endl;
        return;
    }
    string rowOut = "";
    for(int i = 0; i < r; i++){
        // cout << grid[i][0] << endl;
        if(grid[i][0]==forward[0]){
            rowOut+='0';
        }
        else{
            rowOut+='1';
        }
    }
    string rowOutBack = flip(rowOut);
    // cout << forward << ' ' << back << ' ' << rowOut  << ' ' << rowOutBack << endl;
    if(rowOut[0]=='1'){
        swap(forward, back);
        swap(rowOut, rowOutBack);
    }

    if(count(forward)+count(rowOut) > count(back)+count(rowOutBack)){
        for(int i = 0; i < sz(rowOutBack); i++) cout << rowOutBack[i] << ' ';
        cout << endl;
        for(int i = 0; i < sz(back); i++) cout << back[i] << ' ';
        cout << endl;
    }
    else{
        for(int i = 0; i < sz(rowOut); i++) cout << rowOut[i] << ' ';
        cout << endl;
        for(int i = 0; i < sz(forward); i++) cout << forward[i] << ' ';
        cout << endl;
    }
    // cout << forward << ' ' << rowOut << endl;
    // cout << back << ' ' << flip(rowOut) << endl;
    return;
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}