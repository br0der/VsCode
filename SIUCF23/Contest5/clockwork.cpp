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



void solve()
{
    int n; cin >> n;
    vvlong gears;
    for(int i = 0; i < n; i++){
        ll x, y, z, r;
        cin >> x >> y >> z >> r;
        gears.push_back({x, y, z, r, i, i==0, i==0}); //{x, y, z, radius, index, speedNum, speedDen}
    }
    queue<vlong> q;
    // cout << sz(gears[0]) << endl;
    q.push(gears[0]);
    // int visited = 1;
    bool bad = false;
    while(sz(q)>0){
        vlong curr = q.front();
        q.pop();
        // cout << curr[4] << endl;
        for(int i = 0; i < n; i++){
            if(gears[i][4]==curr[4]) continue;
            int dx = (gears[i][0]-curr[0]);
            int dy = (gears[i][1]-curr[1]);
            int rad = (gears[i][3]+curr[3]);
            if(gears[i][2]==curr[2] and (dx*dx + dy*dy <= rad*rad)){
                if(gears[i][5]==0){
                    gears[i][5] = -curr[5]*curr[3];
                    gears[i][6] = gears[i][3]*curr[6];
                    ll g = __gcd(abs(gears[i][5]), gears[i][6]);
                    gears[i][5]/=g;
                    gears[i][6]/=g;
                    // visited++;
                    q.push(gears[i]);
                }
                else if((gears[i][5]*gears[i][3]*curr[6]) != -(curr[5]*curr[3]*gears[i][6])) {
                    // cout << i << ' ' << curr[4] << endl;
                    bad = true;
                }
            }
            if(gears[i][0]==curr[0] and gears[i][1]==curr[1]){
                if(gears[i][5]==0){
                    gears[i][5] = curr[5];
                    gears[i][6] = curr[6];
                    // ll g = __gcd(gears[i][5], gears[i][6]);
                    // gears[i][5]/=g;
                    // gears[i][6]/=g;
                    // visited++;
                    q.push(gears[i]);
                }
                else if(gears[i][5] != curr[5] or gears[i][6] != curr[6]) {
                    bad = true;
                }
            }
        }
        
    }
    if(bad){
        cout << "broken clocks are right twice a day" << endl;
    }
    else{
        for(int i = 0; i < n; i++){
            cout << abs(gears[i][5]) << '/' << gears[i][6] << ' ';
            if(gears[i][5]<0) cout << 'c';
            cout << "cw" << endl;
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < 7; j++){
    //         cout << gears[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << bad << endl;
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