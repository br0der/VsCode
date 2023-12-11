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
#include <experimental/random>
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

int rnum(){
    return rand();
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("./data/input.txt","w", stdout);
        // freopen("./data/alcatraz_tiny.in","w", stdout);
    #endif
    cout << "100 100 1000" << endl;
    vector<int> people(100, 0);
    for(int i = 0; i < 1000; i++){
        int person = rnum()%100;
        while(people[person]==10) person = rnum()%100;
        people[person]++;
        cout << person+1 << ' ' << rnum()%10+1 << endl;
    }
    return 0;
}