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
 
int ans(int n1, int n2){
    if(n1==0 and n2==0) return 3;
    if(n1==n2) return 2;
    if(n1==0) return 0;
    if(n2==0) return 1;
    if(n1%(2*n2)==n1) return (ans(n2, abs(n1-n2))+1)%3;
    return ans(n1%(2*n2), n2);
}

string solve()
{
    int n;
    cin >> n;
    vint a(n);
    for(int _ = 0; _ < n; _++) cin >> a[_];
    vint b(n);
    for(int _ = 0; _ < n; _++) cin >> b[_];
    int same = 3;
    int st = 0;
    while(st<sz(a) and same==3){
        same = ans(a[st], b[st]);
        st++;
    }
    for(int i = st; i < n; i++){
        if(ans(a[i], b[i])!=3 and ans(a[i], b[i])!=same){
            return "NO";
        }
    }
    return "YES";
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
        cout << solve() << endl;
    }
    return 0;
}