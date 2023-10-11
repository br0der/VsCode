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
 
vector<ll> years;
int solve()
{
    ll n;
    cin >> n;
    if(years[lower_bound(all(years), n)-years.begin()]==n){
        return 0;
    }
    return years[upper_bound(all(years), n)-years.begin()]-n;
}
void solve_print()
{
    cout << solve() << endl;
}
ll convert(int arr[]){
    ll out = 0;
    for(int i = 0; i < 9; i++){
       out+=arr[i]*(pow(10, (8-i)));
    }
    return out;
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    do {
        years.push_back(convert(nums));
    } while (next_permutation(nums, nums+9));
    sort(all(years));
    // for(int i = 0; i < sz(years); i++){
    //    cout << years[i] << endl;
    // }
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve_print();
    }
    return 0;
}