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
 
ll xA, yA, xB, yB, xC, yC;
ll solve()
{
    cin >> xA;
    cin >> yA;
    cin >> xB;
    cin >> yB;
    cin >> xC;
    cin >> yC;
    if((xB>=xA and xC>=xA) or (xB<=xA and xC<=xA)){
        if((yB>=yA and yC>=yA) or (yB<=yA and yC<=yA)){
            return min(abs(xB-xA), abs(xC-xA)) + min(abs(yB-yA), abs(yC-yA))+1;
        }
        return min(abs(xB-xA), abs(xC-xA))+1;
    }
    if((yB>=yA and yC>=yA) or (yB<=yA and yC<=yA)){
        return min(abs(yB-yA), abs(yC-yA))+1;
    }
    return 1;
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
        cout << solve() << endl;
    }
    return 0;
}