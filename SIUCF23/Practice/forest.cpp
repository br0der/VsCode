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
double pi = acos(-1);

double cross(pdd a, pdd b, pdd c){ // returns a positive number if ab and ac forms a right turn
    return (c.first-a.first)*(b.second-a.second) - (c.second-a.second)*(b.first-a.first);
}

double dist(pdd a, pdd b){
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

vector<pdd> getCH(vector<pdd> &points){
    sort(all(points));
    vector<pdd> top;
    for(int i = 0; i < sz(points); i++){
        if(sz(top)<2){
            top.push_back(points[i]);
            continue;
        }
        while(sz(top) >= 2 and cross(top[sz(top)-2], top[sz(top)-1], points[i])<0){
            top.pop_back();
        }
        top.push_back(points[i]);
    }
    vector<pdd> bottom;
    for(int i = sz(points)-1; i >= 0; i--){
        // COPY FROM THE ABOVE LOOP
        if(sz(bottom)<2){
            bottom.push_back(points[i]);
            continue;
        }
        while(sz(bottom) >= 2 and cross(bottom[sz(bottom)-2], bottom[sz(bottom)-1], points[i])<0){
            bottom.pop_back();
        }
        bottom.push_back(points[i]);
    }
    for(int i = 1; i < sz(bottom)-1; i++){
        top.push_back(bottom[i]);
    }
    return top;
}   


pdd solve()
{
    double n;
    cin >> n;
    double radius;
    cin >> radius;
    pdd out;
    out.first = 2*radius*pi; 
    out.second = radius*radius*pi;
    vector<pdd> points;
    for(int i = 0; i < n; i++){
        double x;
        cin >> x;
        double y;
        cin >> y;
        points.push_back(make_pair(x,y));
    }
    // sort(all(points));
    if(n==1) return out;
    else if(n==2){
        out.first+=2*sqrt((points[1].first-points[0].first)*(points[1].first-points[0].first) + (points[1].second-points[0].second)*(points[1].second-points[0].second));
        out.second+=radius*2*sqrt((points[1].first-points[0].first)*(points[1].first-points[0].first) + (points[1].second-points[0].second)*(points[1].second-points[0].second));
    }
    else if(n>2){
        vector<pdd> ch = getCH(points);
        // for(int i = 0; i < sz(ch); i++) cout << ch[i].first << ' ' << ch[i].second << endl;
        double xCenter = 0, yCenter = 0;
        for(int i = 0; i < sz(ch); i++){
            xCenter+=ch[i].first;
            yCenter+=ch[i].second;
        }
        xCenter/=sz(ch);
        yCenter/=sz(ch);
        for(int i = 0; i < sz(ch)-1; i++){
            out.second+=cross(make_pair(xCenter, yCenter), make_pair(ch[i].first, ch[i].second), make_pair(ch[i+1].first, ch[i+1].second))/2;
            out.first+=dist(make_pair(ch[i].first, ch[i].second), make_pair(ch[i+1].first, ch[i+1].second));
            out.second+=dist(make_pair(ch[i].first, ch[i].second), make_pair(ch[i+1].first, ch[i+1].second))*radius;
        }
        out.second+=cross(make_pair(xCenter, yCenter), make_pair(ch[sz(ch)-1].first, ch[sz(ch)-1].second), make_pair(ch[0].first, ch[0].second))/2;
        out.first+=dist(make_pair(ch[sz(ch)-1].first, ch[sz(ch)-1].second), make_pair(ch[0].first, ch[0].second));
        out.second+=dist(make_pair(ch[sz(ch)-1].first, ch[sz(ch)-1].second), make_pair(ch[0].first, ch[0].second))*radius;
        // cout << endl;
    }
    return out;
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    auto out = solve();
    cout << setprecision(2) << fixed << out.first << ' ' << out.second << endl;
    return 0;
}