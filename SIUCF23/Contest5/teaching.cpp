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
typedef vector<double> vdouble;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvlong;
typedef vector<vector<double>> vvdouble;
ll MOD = 1e9+7;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb(x) (push_back(x))

vvlong mult(vvlong a, vvlong b){
    
    vvlong out = vvlong(sz(a), vlong(sz(b[0]), 0));
    for(int i = 0; i < sz(a); i++){
        for(int j = 0; j < sz(b[0]); j++){
            for(int k = 0; k < sz(a[0]); k++){
                // cout << sz(a[i]) << endl;
                // cout << i << ' ' << j << ' ' << k << a[i][k] * b[k][j] << endl;
                out[i][j] +=
                 a[i][k] * 
                 b[k][j];
                out[i][j]%=MOD;
            }
        }
    }
    return out;
}

vvlong expo(vvlong a, ll b){ // B CANNOT BE 0
    // cout << b << endl; 
    if(b==1) return a; 
    if(b%2==0) return expo(mult(a, a), b/2);
    return mult(a, expo(mult(a, a), b/2)); 
} 

void solve()
{
    vvlong a = {{1, 1}, {1, 0}};
    vvlong b = {{2}, {1}};
    int num; cin >> num;
    
    vvlong c = mult(expo(a, num), b);
    for(int i = 0; i < sz(c); i++){
        for(int j = 0; j < sz(c[0]); j++){
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }
    
}
int main()
{
    solve();
    return 0;
}