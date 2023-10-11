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
    vint lis(n);
    for(int i = 0; i < n; i++){
        cin >> lis[i];
    }
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        if((lis[i]>0 and i==0 or i==n-1) or lis[i]==2){
            q.push({lis[i], i});
        }
    }
    int out = 0;
    while(sz(q)>0){
        int curr = q.top().second;
        q.pop();
        if(curr<0 or curr>=n) continue;
        if(visited[curr]) continue;
        visited[curr] = true;
        out++;
        // cout << curr << endl;
        if(lis[curr]==2){
            for(int i = curr-1; i >= 0; i--){
                if(visited[i]) break;
                visited[i] = true;
                if(lis[i]==0){
                    q.push({lis[i-1],i-1});
                    break;
                }
            }
            for(int i = curr+1; i < n; i++){
                if(visited[i]) break;
                visited[i] = true;
                if(lis[i]==0){
                    q.push({lis[i+1],i+1});
                    break;
                }
            }
        }
        if(lis[curr]==1){
            if(curr==n-1 or visited[curr+1]){
                for(int i = curr-1; i >= 0; i--){
                    if(visited[i]) break;
                    visited[i] = true;
                    if(lis[i]==0){
                        q.push({lis[i-1],i-1});
                        break;
                    }
                }
            }
            else{
                for(int i = curr+1; i < n; i++){
                    if(visited[i]) break;
                    visited[i] = true;
                    if(lis[i]==0){
                        q.push({lis[i+1],i+1});
                        break;
                    }
                }
            }
        }
        if(lis[curr]==0){
            q.push({lis[curr+1],curr+1});
            q.push({lis[curr-1],curr-1});
        }
    }
    cout << out << endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}