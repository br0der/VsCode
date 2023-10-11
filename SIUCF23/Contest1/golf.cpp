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
typedef complex<double> cd;
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define atan3(y, x) (atan2(y,x)>=0 ? atan2(y,x) : 2*M_PI + atan2(y,x))
// using cd = complex<double>;

void solve()
{
    int n;
    cin >> n;
    vector<double> plus, minus;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        int y;
        cin >> y;
        int r;
        cin >> r;
        double center = atan3(y, x);
        double d = sqrt(x*x + y*y);
        for(int i = r; i >= 1; i--){
            plus.push_back(center-asin((i)/d)+0.000000001);
            minus.push_back(center+asin((i)/d)-0.000000001);
        }
    }
    sort(all(plus));
    sort(all(minus));
    // for(int i = 0; i < sz(plus); i++){
    //     // cout << plus[i] << ' ' << minus[i] << endl;
    // }
    double curr = -1.0;
    int score = 0, i = 0, j = 0;
    int out = 0;
    while(i<sz(plus)){
        if(plus[i]<minus[j]){
            score++;
            i++;
            out = max(out, score);
        }
        else{
            score--;
            j++;
        }
    }
    cout << out << endl;
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    ll t;
    cin >> t;
    // cout << acos(0.999)*180.0/M_PI << endl;
    for(int it=1;it<=t;it++) {
        solve();
    }
    // vint frogs;
    // cout << setprecision(10) << fixed << atan3(-0,-0) << endl;
    return 0;
}