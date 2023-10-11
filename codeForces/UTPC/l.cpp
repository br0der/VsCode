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

int dp[51][51][51][2];

bool solve(int a, int b, int c, bool light){
    if(a>b or b>c){
        vint temp = {a, b, c};
        sort(all(temp));
        return solve(temp[0], temp[1], temp[2], light);
    }
    if(dp[a][b][c][light]!=-1) return dp[a][b][c][light];
    if(a==b and b==c and a==0) return false;
    if((b==c and c==0) or (a==c and a==0) or (a==b and b==0)) return true;
    int mn = min(a, min(b, c));
    bool out = false;
    if(mn!=0){
        out = (!solve(a-mn, b-mn, c-mn, !light));
    }
    for(int i = 1; i <= a; i++){
        out|=(!solve(a-i, b, c, !light));
    }
    for(int i = 1; i <= b; i++){
        out|=(!solve(a, b-i, c, !light));
    }
    for(int i = 1; i <= c; i++){
        out|=(!solve(a, b, c-i, !light));
    }
    dp[a][b][c][light] = out;
    return out;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    int a; cin >> a;
    int b; cin >> b;
    int c; cin >> c;
    memset(dp, -1, sizeof(dp));
    if(solve(a, b, c, true)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}