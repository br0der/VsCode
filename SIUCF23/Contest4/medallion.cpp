// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
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
double pi = atan(1)*4;


void solve()
{
    int cuts; cin >> cuts;
    double r; cin >> r;
    double subSection = (r*r*pi)/(cuts+1);
    double totalArea = r*r*pi;
    double next = subSection;
    vector<double> angles;
    for(int i = 0; i < cuts/2; i++){
        double lo = 0;
        double hi = 90;
        double mid;
        while((hi-lo)>0.00000001){
            mid = (hi+lo)/2;
            double area = (totalArea*mid)/180 - (r*r*sin(pi*(2*mid)/180.0)/2);
            // cout << hi << ' ' << lo << endl;
            if(area<=next){
                lo = mid;
                continue;
            }
            else if(area>next){
                hi = mid+0.00000000001;
            }
        }
        // cout << endl;
        angles.push_back(mid);
        next+=subSection;
    }

    if((cuts%2)==1) angles.push_back(90);
    for(int i = cuts/2-1; i >=0; i--){
        angles.push_back(180-angles[i]);
    }
    for(int i = 0; i < sz(angles); i++){
        cout << angles[i] << endl;
    }
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    cout << setprecision(4) << fixed;
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}