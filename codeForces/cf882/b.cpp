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
 

int solve()
{
    int n;
    cin >> n;
    vint vamps;
    int total;
    cin >> total;
    vamps.push_back(total);
    for (size_t i = 1; i < n; i++)
    {
        int temp;
        cin >> temp;
        total&=temp;
        vamps.push_back(temp);
    }
    if(total!=0){
        return 1;
    }
    int groups = 0;
    int running = vamps[0];
    for (size_t i = 1; i < n; i++)
    {
        if(running==0){
            groups+=1;
            running = vamps[i];
        }
        running&=vamps[i];
    }
    if(running==0){
        groups+=1;
    }
    return max(1, groups);
}
void solve_print()
{
    cout << solve() << endl;
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