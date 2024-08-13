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
typedef vector<vector<int> > vvint;
typedef vector<vector<ll> > vvlong;
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("permutations/permutations_small.in","w", stdout);
        // freopen("./data/alcatraz_tiny.in","w", stdout);
    #endif
    srand(time(NULL));
    vvint arrs;

    arrs.pb({1, 2, 3, 4, 5});

    for(int i = 0; i < sz(arrs); i++){
        cout << sz(arrs[i]) << endl;
        for(int j = 0; j < sz(arrs[i]); j++) cout << arrs[i][j] << ' ';
        cout << endl;
    }
    
    return 0;
}