// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
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
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds ;



bool solve()
{
    int n; cin >> n;
    vector<vector<ll>> events;
    for(int i = 0; i < n; i++){
        ll temp; cin >> temp;
        events.push_back({temp, 1});
    }
    for(int i = 0; i < n; i++){
        ll st; cin >> st;
        ll en; cin >> en;
        events.push_back({st, 0, i});
        events.push_back({en, 2, i});
    }
    sort(all(events));
    queue<vector<ll>> ehandler;
    for(int i = 0; i < sz(events); i++) ehandler.push(events[i]);
    ll children = 0;
    ll ranges = 0;
    // cout << sz(ehandler) << endl;
    set<ll> rangeNoChild;
    while(sz(ehandler)>0){
        ll currTime = ehandler.front()[0];
        bool taken = false;
        
        while(sz(ehandler) and ehandler.front()[0]==currTime){
            // cout << ehandler.front()[0] << ' ' << ehandler.front()[1] << endl;
            if(ehandler.front()[1]==0) rangeNoChild.insert(ehandler.front()[2]);
            if(ehandler.front()[1]==1){
                if(sz(rangeNoChild)==0 and ranges==0) return false;
                ranges+=sz(rangeNoChild);
                rangeNoChild.clear();
                children++;
                
            }
            if(ehandler.front()[1]==2){
                if(rangeNoChild.count(ehandler.front()[2])) return false;
                if(children<1) return false;
                if(taken) return false;
                taken = true;
                ranges--, children--;
            }
            if(children>1) return false;
            // if(children>=2) return false;
            ehandler.pop();
        }
    }
    return true;
}
void solve_print()
{
    bool out = solve();
    cout << (out ? "unique" : "oops") << endl;
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