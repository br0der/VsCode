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

ll IDEMPOTENT_VALUE = 0; 

struct node{
    int lo,hi,mid;
    ll val;
    node *left; node *right;
    node(int l, int r){
        lo = l; hi = r;
        mid = (lo+hi)/2;
        val = IDEMPOTENT_VALUE;
        if(l==r) return;
        left = new node(l,mid);
        right = new node(mid+1,r);
    }
    ll query(int l, int r){
        if(l>hi||r<lo) return IDEMPOTENT_VALUE;
        if(l<=lo&&hi<=r) return val;
        return left->query(l,r) + right->query(l,r);
    }
    void update(int i, ll amt){
        if(lo==hi) return void(val+=amt);
        if(i<=mid) left->update(i, amt);
        else right->update(i, amt);
        val = left->val + right->val;
    }
};

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
    for(int i = 2; i <= ceil(sqrt(num)); i++){
        if(num%i==0){
            // cout << num << ' ' << false << endl;
            return false;
        }
    }
    return true;
}



void solve()
{
    ll n;
    cin >> n;
    ll q;
    cin >> q;

    vint a;
    vint b;

    a.reserve(n);
    b.reserve(n);

    for(int _ = 0; _ < n; _++) cin >> a[_];
    for(int i = 0; i < n; i++){
        if(isPr(a[i])){
            b[i] = 1;
        }
        else{
            b[i] = 0;
        }
    }
    
    node *root = new node(0, n-1);
    node *rootP = new node(0, n-1);
    for(int i = 0; i < n; i++){
        root->update(i, a[i]);
        if(isPr(a[i])){
            rootP->update(i, 1);
        }
    }
    for(int i = 0; i < q; i++){
        ll k;
        cin >> k;
        ll n1;
        cin >> n1;
        ll n2;
        cin >> n2;
        if(k==1){
            if(isPr(root->query(n1-1, n1-1))){
                rootP->update(n1-1, -1);
            }
            root->update(n1-1, n2);
            if(isPr(root->query(n1-1, n1-1))){
                rootP->update(n1-1, 1);
            }
        }
        else{
            cout << root->query(n1-1, n2-1) << ' ' << rootP->query(n1-1, n2-1) << endl;
        }
    }
}

int main()
{
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    fast_cin();
    int n;
    cin >> n;
    vint lis;
    lis.reserve(n);
    for(int _ = 0; _ < n; _++) cin >> lis[_];
    
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}