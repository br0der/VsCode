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

int rnum(){
    return rand();
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("./data/input.txt","w", stdout);
        // freopen("./data/alcatraz_tiny.in","w", stdout);
    #endif
    vlong inputs = vlong();
    for(int i = 1; i <= 10; i++){
        inputs.pb(i);
    }
    inputs.pb(3*3*3);
    inputs.pb(3*3*3*3);
    inputs.pb(3*3*3*3*3*3);
    inputs.pb(26);
    inputs.pb(28);
    inputs.pb(26);
    inputs.pb(10000000000);
    inputs.pb((ll)99991*(ll)99989);
    inputs.pb(99991);
    inputs.pb(999999937);
    inputs.pb(3486784401);
    inputs.pb(561961);
    inputs.pb(2048);
    inputs.pb(5*5*5*5);
    inputs.pb(139*139*139);
    inputs.pb(2*3*5*7*11*13*17*19*23);
    cout << sz(inputs) + 10 << endl;
    for(int i = 0; i < sz(inputs); i++){
        if (i < 10) {
            cout << i+1 << " " << 'V' << endl;
            cout << i+1 << " " << 'P' << endl;
        }
        else {
            cout << inputs[i] << " " << (rand()%2==1 ? 'V' : 'P') << endl;
        }
    }
    return 0;
}