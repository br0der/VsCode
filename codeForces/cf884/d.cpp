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
 
bool isPr(ll num){
    if(num<2){
        return false;
    }
    if(num==2){
        return true;
    }
    if(num==3){
        return true;
    }
    for(int i = 2; i*i <= num; i++){
        if(num%i==0){
            // cout << num << ' ' << false << endl;
            return false;
        }
    }
    return true;
}

string solve()
{
    int n;
    cin >> n;
    
    unordered_set<int> factors;
    for(int i = 2; i <= n; i++){
        if(n%i==0){
            // cout << n << ' ' << i << endl;
            factors.insert(i);
        }
    }
    int period = -1;
    for(int i = 2; i < 30; i++){
        // cout << i <<d endl;
        if(!factors.count(i)){
            period = i;
            break;
        }
    }
    
    string s;
    char nxt = 'a';
    // cout << period << endl;
    if(isPr(n)){
        period = 2;
    }
    while(sz(s)<n){
        s+=nxt;
        nxt++;
        if(nxt-'a'==period){
            nxt='a';
        }
    }
    return s;
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