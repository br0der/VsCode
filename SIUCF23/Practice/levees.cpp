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

double rnd(double num){
    num*=1000;
    num = round(num);
    num/=1000;
    return num;
}

double area(pdd a, pdd b){
    return abs((a.first)*(b.second) - (a.second)*(b.first))/2;
}

double dist(pdd a, pdd b){
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    while(true){
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        // cout << 'a' << endl;
        if(x1==x2 and x2==x3 and x3==x4 and x4==0.0) break;
        // cout << 'h' << endl;
        double xCenter, yCenter;
        if(x1==x3){
            xCenter = x1;
            yCenter = (y2+y4)/2;
            // cout << 1 << endl;
        }
        else if(x2==x4){
            xCenter = x2;
            yCenter = (y1+y3)/2;
            // cout << 2 << endl;
        }
        else{
            double a1 = y3 - y1;
            double b1 = x1 - x3;
            double c1 = a1*(x1) + b1*(y1);
        
            // Line CD represented as a2x + b2y = c2
            double a2 = y4 - y2;
            double b2 = x2 - x4;
            double c2 = a2*(x2)+ b2*(y2);
            
            double determinant = a1*b2 - a2*b1;
            xCenter = (b2*c1 - b1*c2)/determinant;
            yCenter = (a1*c2 - a2*c1)/determinant;
            // double slope1 = (y3-y1)/(x3-x1);
            // double slope2 = (y4-y2)/(x4-x2);
            // double yint1 = y1-slope1*x1;
            // double yint2 = y2-slope2*x2;
            // xCenter = (yint1-yint2)/(slope2-slope1);
            // yCenter = slope1*xCenter + yint1;
            // cout << 3 << endl;
        }
        // cout << xCenter << ' ' << yCenter << endl;
        double d1, d2, d3, d4;
        d1 = dist(make_pair(xCenter, yCenter), make_pair(x1, y1));
        d2 = dist(make_pair(xCenter, yCenter), make_pair(x2, y2));
        d3 = dist(make_pair(xCenter, yCenter), make_pair(x3, y3));
        d4 = dist(make_pair(xCenter, yCenter), make_pair(x4, y4));
        double a1, p1, a2, p2, a3, p3, a4, p4;
        a1 = area(make_pair(x1-xCenter, y1-yCenter), make_pair(x2-xCenter, y2-yCenter));
        a2 = area(make_pair(x2-xCenter, y2-yCenter), make_pair(x3-xCenter, y3-yCenter));
        a3 = area(make_pair(x3-xCenter, y3-yCenter), make_pair(x4-xCenter, y4-yCenter));
        a4 = area(make_pair(x1-xCenter, y1-yCenter), make_pair(x4-xCenter, y4-yCenter));
        p1 = dist(make_pair(x1, y1), make_pair(x2, y2)) + d1 + d2;
        p2 = dist(make_pair(x3, y3), make_pair(x2, y2)) + d3 + d2;
        p3 = dist(make_pair(x3, y3), make_pair(x4, y4)) + d3 + d4;
        p4 = dist(make_pair(x1, y1), make_pair(x4, y4)) + d1 + d4;
        vector<pdd> stuff = {
            make_pair(-rnd(a1), -rnd(p1)), 
            make_pair(-rnd(a2), -rnd(p2)), 
            make_pair(-rnd(a3), -rnd(p3)), 
            make_pair(-rnd(a4), -rnd(p4))
        };
        sort(all(stuff));
        for(int i = 0; i < 4; i++) cout << setprecision(3) << fixed << -stuff[i].first << ' ' << -stuff[i].second << ' ';
        cout << endl;
    }
    return 0;
}