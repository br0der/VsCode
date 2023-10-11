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
 
struct port{
    vlong levels;
    vint dependencies;
    port(){
        levels = vlong(4);
        dependencies = {};
    }
};

struct charge{
    int type;
    ll power;
    ll destruction;
    charge(){

    }
};
vint dp;
vector<port*> ports;



int func(int mask){
    
    if(dp[mask]==-1){
        int out = 0;
        // cout << sz(dp) << endl;
        for(int i = 0; i < sz(ports); i++){
            if(!(mask&(1<<i))){
                // cout << i << endl;
                int newMask = mask;
                // cout << sz(ports[i]->dependencies) << endl;
                for(int j = 0; j < sz(ports[i]->dependencies); j++){
                    newMask|=(1<<(ports[i]->dependencies[j]));
                }
                out = max(out, func(newMask|(1<<i))+1);
            }
        }
        dp[mask] = out;
        // cout << mask << ' ' << out << endl;
    }
    return dp[mask];
} // 1 0 1 1

ll solve()
{
    int p;
    cin >> p;
    int c;
    cin >> c;
    int n;
    cin >> n;
    ll ans = 0;
    ports.clear();
    vector<ll> maxPow(4, -1);
    for(int i = 0; i < p; i++){
        port *temp = new port();
        cin >> temp->levels[0];
        cin >> temp->levels[1];
        cin >> temp->levels[2];
        cin >> temp->levels[3];
        for(int j = 0; j < 4; j++){
            maxPow[j] = max(maxPow[j], temp->levels[j]);
        }
        ports.push_back(temp);
    }
    vector<charge*> chargesTemp;
    vector<charge*> charges;
    vlong dest;
    for(int i = 0; i < c; i++){
        charge *temp = new charge();
        string typ;
        cin >> typ;
        if(typ=="air") temp->type = 0;
        if(typ=="earth") temp->type = 1;
        if(typ=="fire") temp->type = 2;
        if(typ=="water") temp->type = 3;
        cin >> temp->power;
        cin >> temp->destruction;
        // cout << typ << endl;
        if(maxPow[temp->type] < (temp->power)){
            charges.push_back(temp);
            dest.push_back(-temp->destruction);
        }
        else{
            ans+=temp->destruction;
        }
    }
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        int b;
        cin >> b;
        // cout << sz(ports[a-1]->dependencies) << endl;
        ports[a-1]->dependencies.push_back(b-1);
    }
    dp = vint(1<<p, -1);
    int count = func(0);
    sort(all(dest));
    // cout << ans << endl;
    for(int i = 0; i < min((ll)count, sz(dest)); i++){
        ans -= dest[i];
    }
    return ans;
}
void solve_print()
{
    cout << solve() << endl;
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
        solve_print();
    }
    return 0;
}