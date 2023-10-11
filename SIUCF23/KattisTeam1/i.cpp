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
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvlong;
typedef vector<vector<double>> vvdouble;
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
vvlong pieces;
int glen;
vector<bool>used;
// vector<int> visited;

// int solve(int last)
// {
//     if(last==glen) return 0;
//     if(visited[last]!=-1) return visited[last];
//     visited[last] = INF;
//     int mn = INF;
//     for(int i = 0; i<sz(pieces); i++){
//         // if(used[i]) continue;
//         auto shape = pieces[i];
//         if(shape[1]==last){
//             // used[i] = true;
//             mn = min(mn, solve(shape[2])+shape[0]);
//             // used[i] = false;
//         }
//         if(shape[2]==last){
//             // used[i] = true;
//             mn = min(mn, solve(shape[1])+shape[0]);
//             // used[i] = false;
//         }
//     }
//     visited[last] = mn;
//     return mn;
// }

signed main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif

    while(true) {
        int n; cin >> n;
        if(n==0) break;
        pieces = vvlong();
        used = vector<bool>(n, false);
        // visited = vint(1001, -1);
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            int b; cin >> b;
            int height; cin >> height;

            // visited.clear();
            if(a!=b){
                pieces.push_back({(a+b)*height, a, b});
            }
        }
        sort(all(pieces));
        int first; cin >> first;
        glen; cin >> glen;
        priority_queue<pair<int, int>> pq;
        pq.push({0,first});
        while(sz(pq)>0){
            if(pq.top().second==glen) break;
            for(int i = 0; i<sz(pieces); i++){
                if(used[i]) continue;
                auto shape = pieces[i];
                if(shape[1]==pq.top().second){
                    pq.push({pq.top().first-shape[0], shape[2]});
                    used[i] = true;
                }
                if(shape[2]==pq.top().second){
                    pq.push({pq.top().first-shape[0], shape[1]});
                    used[i] = true;
                }
            }
            pq.pop();
        }
        cout << setprecision(2) << fixed << (-pq.top().first/100.0) << endl;
        // return 0;
    }
    return 0;
}