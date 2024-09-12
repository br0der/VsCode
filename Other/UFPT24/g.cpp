#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

//BG, BR, BY, GR, GY, or RY
int encode(string s) {
    if (s=="RY") {
        return 0;
    }
    if (s=="GY") {
        return 1;
    }
    if (s=="GR") {
        return 2;
    }
    if (s=="BG") {
        return 3;
    }
    if (s=="BR") {
        return 4;
    }
    if (s=="BY") {
        return 5;
    }
    assert(1==0);
    return -1;
}

int main(){ 
    int tc; cin >> tc;
    while (tc--) {
        int n, q; cin >> n >> q;
        vector<int> colors;
        rep (i, n) {
            string s; cin >> s;
            colors.push_back(encode(s));
        }
        vector<vector<int>> closestDiffForw(6);
        rep(i, 6) closestDiffForw[i].push_back(-1);
        
        rep(i, n) {
            rep(j, 6) {
                closestDiffForw[j].push_back(closestDiffForw[j][i]);
                if ((abs(colors[i])-j)%3==0) continue;
                closestDiffForw[j][i+1] = i;
            }
        }
        // rep(i, 6) {
        //     rep(j, closestDiffForw[i].size()) cout << closestDiffForw[i][j] << ' ';
        //     cout << endl; 
        // }
        vector<vector<int>> closestDiffBack(6);
        rep(i, 6) closestDiffBack[i].push_back(-1);
        rep(ii, n) {
            int i = n-ii-1;
            rep(j, 6) {
                closestDiffBack[j].push_back(closestDiffBack[j][ii]);
                if ((abs(colors[i])-j)%3==0) continue;
                closestDiffBack[j][ii+1] = i;
            }
        }
        rep(i, 6) reverse(closestDiffBack[i].begin(), closestDiffBack[i].end());
        // rep(i, 6) {
        //     rep(j, closestDiffBack[i].size()) cout << closestDiffBack[i][j] << ' ';
        //     cout << endl; 
        // }
        rep(i, q) {
            int a, b; cin >> a >> b;
            a--, b--;
            if (b<a) swap(a, b);
            if (abs(colors[a]-colors[b])!=3) cout << abs(b-a) << endl;
            else {
                int left = -1, right = -1;
                // cout << a << ' ' << b << endl;
                if (closestDiffForw[colors[b]][b]!=-1) {
                    left = abs(b-closestDiffForw[colors[b]][b])+abs(a-closestDiffForw[colors[b]][b]);
                }
                if (closestDiffBack[colors[a]][a+1]!=-1) {
                    right = abs(a-closestDiffBack[colors[a]][a+1])+abs(b-closestDiffBack[colors[a]][a+1]);
                }
                // cout << left << ' ' << right << endl;
                if (left==right and left==-1) cout << -1 << endl;
                else {
                    if (left==-1 or right==-1) cout << max(left, right) << endl;
                    else cout << min(left, right) << endl;
                }
            }
            
        }
    }
    return 0;
}