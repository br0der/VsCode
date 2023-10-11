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
 

void solve()
{
    priority_queue<ll> pq;
    int n;
    cin >> n;
    priority_queue<ll> reserve;
    priority_queue<ll> small;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        reserve.push(-temp);
    }
    while(sz(reserve)>0){
        ll nxt;
        if(sz(small)==0){
            nxt = -reserve.top();
            reserve.pop();
        }
        else{
            nxt = -small.top();
            small.pop();
        }
        while(sz(reserve)>0 and nxt*2+1 > -reserve.top()){
            small.push(reserve.top());
            reserve.pop();
        }
        if(sz(reserve)==0){
            small.push(-nxt);
            break;
        }
        reserve.push(-(nxt-reserve.top()));
        reserve.pop();
    }
    cout << sz(small) << endl;
    while(sz(small)>0){
        cout << -small.top() << endl;
        small.pop();
    }
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