#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

int main()
{

    double s, t; cin >> s >> t;
    int n; cin >> n;
    s = log2(s);
    t = log2(t);
    vector<pair<double, double> > blades;
    for (int i = 0; i < n; i++) {
        double m, h; cin >> m >> h;
        blades.emplace_back(log2(h), 1/m);
    }
    sort(blades.begin(), blades.end());
    // if (blades[blades.size() - 1].first < s) { 
    //     cout << -1 << endl;
    //     return 0;
    // }
    pair<double, double> mx = make_pair(-1, -1);
    int i = blades.size()-1;
    while (i!=0 and blades[i].first <= s) {

    }
    // for (int i = 0; i < blades.size(); i++) {
    //     cout << blades[i].first << ' ' << blades[i].second << endl;
    // }
}