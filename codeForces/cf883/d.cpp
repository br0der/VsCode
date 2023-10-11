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

double n, d, h;
double calc(double height){
    double out = d*height;
    double top = d;
    double slope = h/(d/2.0);
    if(height<h){
        top = h-height;
        top = top/slope;
        top = d-(top*2.0);
    }
    out-=(top/2.0)*height;
    // cout << setprecision(9) << out << endl;
    return out;
}
double solve()
{
    cin >> n >> d >> h;
    vector<double> heights;
    for (size_t i = 0; i < n; i++)
    {
        double temp;
        cin >> temp;
        heights.push_back(temp);
    }
    // sort(all(heights));
    double out = 0;
    vector<double> dists;
    for (size_t i = 0; i < n-1; i++)
    {
        dists.push_back(heights[i+1]-heights[i]);
        if(dists[sz(dists)-1]>h){
            dists[sz(dists)-1] = h;
        }
    }
    dists.push_back(h);
    for (size_t i = 0; i < n; i++)
    {
        out+=calc(dists[i]);
    }
    return out;
}
void solve_print()
{
    cout << setprecision(20) << solve() << endl;
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