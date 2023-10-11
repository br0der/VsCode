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



void solve()
{
    
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    int x; cin >> x;
    int y; cin >> y;
    int z; cin >> z;
    bool nt[x][y][z];
    memset(nt, 0, sizeof(nt));
    for(int i = 0; i < y; i++){
        string line;
        cin >> line;
        for(int j = 0; j < x; j++){
            if(line[j]=='#'){
                for(int k = 0; k < z; k++){
                    nt[j][i][k] = true;
                }
            }
        }
    }
    for(int i = 0; i < y; i++){
        string line;
        cin >> line;
        for(int j = 0; j < z; j++){
            if(line[j]=='#'){
                for(int k = 0; k < x; k++){
                    nt[k][i][j] = true;
                }
            }
        }
    }
    for(int i = 0; i < z; i++){
        string line;
        cin >> line;
        for(int j = 0; j < x; j++){
            if(line[j]=='#'){
                for(int k = 0; k < y; k++){
                    nt[j][k][i] = true;
                }
            }
        }
    }
    int out = 0;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            for(int k = 0; k < z; k++){
                out+=nt[i][j][k];
            }
        }
    }
    cout << (x*y*z)-out << endl;
    return 0;
}