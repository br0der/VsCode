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
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds ;



int solve()
{
    int t;
    cin >> t;
    vector<vector<ll>> temp;
    for(int i = 0; i < t; i++){
        ll r, c, d;
        cin >> r >> c >> d;
        temp.push_back({r, c, d}); // will be put in like (start, time, due)
    }
    sort(all(temp));
    queue<vector<ll>> todo;
    for(int i = 0; i < t; i++){
        todo.push(temp[i]);
    }
    ll currTime = 0;
    int ans = 0;
    priority_queue<vector<ll>> taskList; // will be put in like (due, time, start)
    if(sz(todo)>0) currTime=todo.front()[0];
    while(sz(todo)>0){
        ll elapsedTime = todo.front()[0]-currTime;
        ll nextTime = currTime+elapsedTime;
        // cout << currTime << ' ' << elapsedTime << endl;
        
        while(sz(taskList)>0 and taskList.top()[1]<=elapsedTime){
            // if(sz(taskList)) cout << taskList.top()[2] << ' ' << taskList.top()[1] << ' ' << -taskList.top()[0] << endl;
            currTime+=taskList.top()[1];
            
            elapsedTime-=taskList.top()[1];
            if(currTime<=-taskList.top()[0]) ans++;
            
            taskList.pop();
        }
        if(sz(taskList)>0){
            
            vector<ll> fr = taskList.top();
            taskList.pop();
            fr[1]-=elapsedTime;
            taskList.push(fr);
        }
        
        taskList.push({-todo.front()[2], todo.front()[1], todo.front()[0]});
        todo.pop();
        currTime = nextTime;
    }
    // cout << currTime << endl;
    while(sz(taskList)>0){
        // cout << taskList.top()[2] << ' ' << taskList.top()[1] << ' ' << -taskList.top()[0] << endl;
        currTime+=taskList.top()[1];
        if(currTime<=-taskList.top()[0]) ans++;
        taskList.pop();
    }
    return ans;
}
void solve_print()
{
    cout << solve() << endl;
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
        solve_print();
    }
    return 0;
}