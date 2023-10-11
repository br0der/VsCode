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
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb(x) (push_back(x))

double d, s;

double calcSag(double a){
    return a*cosh(d/(2*a)) - a;
}

double calcDist(double a){
    return 2*a*(sinh(d/(2*a)));
}

void solve()
{
    cin >> d >> s;
    double lo = 0.000001, hi = 2*s, mid;
    while(hi-lo>0.000001){
        mid = (hi-lo)/2;
        double out = calcSag(mid);
        if(out>s){
            hi = mid;
        }
        else if(out<=s){
            lo = mid;
        }
    }
    cout << lo << endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    // ll t;
    // cin >> t;
    // for(int it=1;it<=t;it++) {
        solve();
    // }
    return 0;
}