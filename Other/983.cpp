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
typedef pair<string, double> psd;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvlong;

ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
int bits(int n)
{
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}


set<psd> solve(int mask, vector<double> nums){
    if(bits(mask)==1){
        // cout << mask << endl;
        for (size_t i = 0; i < 6; i++){
            if(mask&(1<<i)){
                string temp = "(" + to_string(nums[i]) + ")";
                psd p(temp, nums[i]);
                return set<psd> {p};
            }
        }
    }
    // cout << mask << endl;
    set<psd> achievable;
    for (size_t i = 0; i < 6; i++)
    {
        if(mask&(1<<i)){
            set<psd> temp = solve(mask^(1<<i), nums);
            // cout << sz(temp) << endl;
            for(psd thing: temp){
                string eq = thing.first;
                double num = thing.second;
                achievable.insert(make_pair("(" + eq + " + " + to_string(nums[i]) + ")", num+nums[i]));
                achievable.insert(make_pair("(" + eq + " - " + to_string(nums[i]) + ")", num-nums[i]));
                achievable.insert(make_pair("(" + eq + " * " + to_string(nums[i]) + ")", num*nums[i]));
                if(nums[i]!=0) achievable.insert(make_pair("(" + eq + " / " + to_string(nums[i]) + ")", num/nums[i]));
                achievable.insert(make_pair("(" + to_string(nums[i]) + " - " + eq + ")", nums[i]-num));
                if(num!=0) achievable.insert(make_pair("(" + to_string(nums[i]) + " / " + eq + ")", nums[i]/num));
            }
        }
    }
    
    return achievable;
}
// void solve_print()
// {
//     cout << solve() << endl;
// }
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    vector<double> nums = {2,2,3,3,10,25};
    set<psd> out = solve((1<<6)-1, nums);
    vector<psd> vecOut(out.begin(), out.end());
    sort(vecOut.begin(), vecOut.end(),[](psd const& one, psd const& two) -> bool
  {
    return one.second < two.second;
  });
    for (size_t i = 0; i < sz(vecOut); i++)
    {
        cout << vecOut[i].first << " " << vecOut[i].second << endl;
    }
    cout << "done" << endl;
    return 0;
}