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



int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    int n; cin >> n;
    set<int> a;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        a.insert(temp);
    }
    set<int> b;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        b.insert(temp);
    }
    set<int> c;
    set_intersection(all(a), all(b), inserter(c, c.begin()));
    set<int> d;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        d.insert(temp);
    }
    set<int> e;
    set_intersection(all(d), all(c), inserter(e, e.begin()));
    int mx = -1;
    for(int elem : e){
        mx = max(mx, elem);
    }
    cout << mx << endl;
    return 0;
}