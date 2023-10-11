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

vlong ans, points, favorites;
vector<int> par;
vector<map<int, int>*> maps;


// map<int, int>* func(int idx){
//     map<int, int> *curr = new map<int, int>();
//     // cout << idx << endl;
//     (*curr)[favorites[idx]]++;
//     for(int child : children[idx]){
//         map<int, int> *other = func(child);
//         if(sz(*other)>sz(*curr)) swap(other, curr);
//         for(auto i : *other){
//             (*curr)[i.first]+=i.second;
//         }
//     }
//     // cout << idx << endl;
//     ans[idx] = scoreIt(curr);
//     return curr;
// }

ll scoreIt(map<int, int> *m){
    ll total = 0;
    for(auto i : *m){
        total+=points[i.second-1];
        // cout << i.second << ' ' << points[i.second-1] << endl;
    }
    return total;
}

void solve()
{
    int num; cin >> num;
    vint inDegree(num, 0);
    par = vector<int>(num);
    for(int i = 0; i < num-1; i++){
        int temp; cin >> temp;
        par[i+1] = (temp-1);
        inDegree[temp-1]++;
    }
    ans = vlong(num, 0);
    points = vlong(num);
    favorites = vlong(num);
    for(int i = 0; i < num; i++){
        cin >> favorites[i];
    }
    for(int i = 0; i < num; i++){
        cin >> points[i];
    }
    queue<int> q;
    maps = vector<map<int, int>*>(num, nullptr);

    for(int i = 0; i < num; i++){
        // maps.push_back(new map<int, int>);
        if(inDegree[i]==0){
            q.push(i);
            maps[i] = new map<int, int>;
        }
    }
    while(sz(q)){
        int curr = q.front();
        q.pop();
        if((*maps[curr])[favorites[curr]]!=0)
            ans[curr]-=points[(*maps[curr])[favorites[curr]]-1];
        (*maps[curr])[favorites[curr]]++;
        ans[curr]+=points[(*maps[curr])[favorites[curr]]-1];
        // ans[curr] = 0;
        // for(auto i : *maps[curr]){
        //     ans[curr]+=points[i.second-1];
        //     // cout << i.second << ' ' << points[i.second-1] << endl;
        // }
        if(curr!=0){
            if(maps[par[curr]]==nullptr) maps[par[curr]] = new map<int, int>;
            if(sz(*maps[curr])>sz(*maps[par[curr]])){
                swap(maps[par[curr]], maps[curr]);
                // int temp = ans[par[curr]];
                ans[par[curr]] = ans[curr];
            }
            // int iter = 0;cout << iter++ << endl;
            for(auto i : *maps[curr]){
                if((*maps[par[curr]])[i.first]!=0)
                    ans[par[curr]]-=points[(*maps[par[curr]])[i.first]-1];
                (*maps[par[curr]])[i.first]+=i.second;
                ans[par[curr]]+=points[(*maps[par[curr]])[i.first]-1];
            }
            inDegree[par[curr]]--;
            if(inDegree[par[curr]]==0) q.push(par[curr]);
        }
    }
    for(int i = 0; i<num;i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
    // return 0;
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