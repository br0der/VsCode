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
    int endX, endY;
    cin >> endX >> endY;
    int n; cin >> n;
    int dirX = 0, dirY = 1;
    int finalX = 0, finalY = 0;
    vint instructions = vint(n);
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        if(temp=="Forward"){
            instructions[i]=0;
            finalX+=dirX;
            finalY+=dirY;
        }
        if(temp=="Left"){
            instructions[i]=1;
            dirY = -dirY;
            swap(dirX, dirY);
        }
        if(temp=="Right"){
            instructions[i]=2;
            dirX = -dirX;
            swap(dirX, dirY);
        }
    }
    cout << dirX << ' ' << dirY << endl;
    dirX = 0, dirY = 1;
    int currX = 0, currY = 0;
    for(int i = 0; i < n; i++){
        
        if(instructions[i]==0){
            finalX-=dirX, finalY-=dirY;
            currX+=dirX, currY+=dirY;
        }
        if(instructions[i]==1){
            // finalX = -finalX;
            // swap(finalX, finalY);
            dirY = -dirY;
            swap(dirX, dirY);
            // finalX = finalY, dirY = -finalX;
        }
        if(instructions[i]==2){
            // finalY = -finalY;
            // swap(finalX, finalY);
            dirX = -dirX;
            swap(dirX, dirY);
            // finalX = -finalY, finalY = finalX;
        }
        cout << finalX << ' ' << finalY << "  " << currX << ' ' << currY << "  " << dirX << ' ' << dirY << endl;
        if(currX+finalX==endX and currY+finalY==endY){
            cout << i+1 << ' ' << "Forward" << endl;
            return;
        }
        if(currX+finalY==endX and currY-finalX==endY){
            cout << i+1 << ' ' << "Right" << endl;
            return;
        }
        if(currX-finalY==endX and currY+finalX==endY){
            cout << i+1 << ' ' << "Left" << endl;
            return;
        }
    }
    cout << "fuc" << endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    solve();

    return 0;
}