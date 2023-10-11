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

vint ans;

void solve()
{
    int n; cin >> n;
    vint lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    vvint lis2;
    for(int i = 0; i < n; i++){
        lis2.push_back({lis[i], i});
    }
    sort(all(lis2));
    int last = 0;
    int i = 0, j = n-1, numPos = 0, nxt = n, numNeg = 0;
    // cout << n << endl;
    ans = vint(n, 0);
    // for(int i = 0; i < n; i++){
    //     ans.push_back(0);
    // }
    
    while(true){
        // cout << i << ' ' << j << endl;
        if(i>j) break;
        bool something = false;
        if(lis2[i][0]==numPos){
            ans[lis2[i][1]] = -(nxt--);
            numNeg++;
            i++;
        }
        else if(lis2[j][0]==n-numNeg){
            ans[lis2[j][1]] = nxt--;
            numPos++;
            j--;
        }
        else{
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}