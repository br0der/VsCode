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
 

string solve()
{
    string out = "1";
    vint q;
    int n;
    cin >> n;
    int temp;
    for (size_t i = 0; i < n; i++)
    {
        cin >> temp;
        q.push_back(temp);
    }
    int lower = -1, upper = q[0];
    int last = 0;
    for (size_t i = 1; i < n; i++)
    {
        if(lower!=-1){
            if(q[i]>=lower and q[i]<=upper){
                lower = q[i];
                out+='1';
            }
            else{
                out+='0';
            }
        }
        else{
            // cout << q[i] << q[last] << endl;
            if(q[i]<q[last]){
                if(upper>=q[i]){
                    out+='1';
                    if(q[i]<q[last]){
                        lower = q[i];
                    }
                }
                else{
                    out+='0';
                }
            }
            else{
                out+='1';
                last = i;
            }
        }
    }
    return out;
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