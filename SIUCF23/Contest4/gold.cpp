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
ll MOD = 1000000007;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

vint counts;
vint pSum;
string target;
int l;
vlong facs(1000001);

ll count(string bound){
    if(sz(bound)<l) return 0;
    ll total = facs[]
    if(sz(bound)>l) return facs[l];
    

    vint perms(l,0);
    for(int i = 0; i < l; i++){
        perms[i] = (pSum[target[i]-'0']*(l-i-1))%MOD;
        for(int j = target[i]-'0'; j < 10; j++) pSum[j]--;
        counts[target[i]-'0']--;
    }
    for(int i = 0; i < l; i++) cout << perms[i] << ' ';
    cout << endl;
    return perms[0];
}

void solve()
{
    cin >> target;
    string lo; cin >> lo;
    string hi; cin >> hi;
    l = sz(target);
    counts = vint(10, 0);
    for(char c: target){
        counts[c-'0']++;
    }
    pSum = vint(10, 0);
    pSum[0] = counts[0];
    for(int i = 1; i < 10; i++){
        pSum[i] = pSum[i-1]+counts[i];
    }
    ll lower = count(lo);
    for(int i = 0; i < 10; i++){
        lower/=facs[counts[i]];
    }
    cout << lower << endl;
    for(int i = 1; i < 10; i++){
        pSum[i] = pSum[i-1]+counts[i];
    }
    ll high = count(hi);
    for(int i = 0; i < 10; i++){
        high/=facs[counts[i]];
    }
    cout << high << endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    facs[0] = 1;
    for(int i = 1; i < 1000001; i++){
        facs[i] = facs[i-1]*i;
        facs[i]%=MOD;
    }
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}