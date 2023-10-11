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
 

// int solve()
// {
    
    
//     return 0;
// }
// void solve_print()
// {
//     cout << solve() << endl;
// }
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    bool works[1000001];
    memset(works, false, 1000001);

    for (int i = 2; i < 1000001; i++)
    {
        ll curr = 1;
        ll last = 1;
        int wait = 2;
        while (curr<1000001){
            // cout << curr << endl;
            if(wait==0){
                works[curr]=true;
            }
            else{
                wait--;
            }
            curr+=last*i;
            last = last*i;
            // cout << curr << endl;
        }
        // cout << endl;
    }
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        // solve_print();
        int temp;
        cin >> temp;
        if(works[temp]){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}