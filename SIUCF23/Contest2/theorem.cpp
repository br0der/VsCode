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
 

int oldsolve()
{
    vint nums = {1};
    vint ans = {1, 1};
    int off = 0;
    for(int i = 2; i <= int(1e5); i++){
        ll carry = 0;
        for(int j = off; j < sz(nums); j++){
            carry+=nums[j]*i;
            nums[j] = carry%10;
            if(nums[j]==0) off++;
            carry/=10;
        }
        while(carry!=0){
            nums.push_back(carry%10);
            carry/=10;
        }
        ans.push_back(nums[sz(nums)-1]);
    }
    for(int i = sz(nums)-1; i >= off-50; i--){
        cout << nums[i];
    }
    // cout << endl;
    // cout << sz(nums) << endl;
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        int n;
        cin >> n;
        cout<< ans[n] << endl;
    }
    
    return 0;
}
void solve(){
    double total = 0;
    vint ans = {1};
    for(int i = 1; i <= int(1e5); i++){
        total+=log10(i);
        ans.push_back(int(pow(10,(total - int(total)))));
        // cout << ans[sz(ans)-1] << endl;
    }
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        ll temp;
        cin >> temp;
        cout << ans[temp] << endl;
    }
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    solve();
    return 0;
}