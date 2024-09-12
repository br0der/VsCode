#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++) 

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n, k, q; cin >> n >> k >> q;
        vector<int> lis(n); rep(i, n) cin >> lis[i], lis[i]+=n-i-1;
        rep(i, n) cout << lis[i] << ' ';
        cout << endl;
        vector<int> ans(n, -1);
        vector<pair<int, int>> queries;
        rep(i, q) {
            int a, b; cin >> a >> b;
            queries.push_back({a-1, b-1});
            // cout << a << endl;
        }
        vector<int> nums(q); rep(i, q) nums[i] = i;
        
        int sz = sqrt(n);
        sort(nums.begin(), nums.end(), [&](int a, int b) {return 
        queries[a].first/sz < queries[b].first/sz 
        or (queries[a].first/sz == queries[b].first/sz 
            and queries[a].first%sz < queries[b].first%sz); });
        int l = queries[nums[0]].first;
        int r = queries[nums[0]].second;
        vector<int> occur(2*n, 0);
        set<pair<int, int>> occs;
        rep(i, r-l) {
            int ii = i+l;
            if (occur[lis[ii]]==0) occur[lis[ii]]++, occs.insert({1, lis[ii]});
            else occs.erase({occur[lis[ii]], lis[ii]}), occur[lis[ii]]++, occs.insert({occur[lis[ii]], lis[ii]});
        }
        rep(i, q) {
            int L = queries[nums[i]].first;
            int R = queries[nums[i]].second;
            while (L > l) {
                l++;
                if (occur[lis[l]]==0) occur[lis[l]]++, occs.insert({1, lis[l]});
                else occs.erase({occur[lis[l]], lis[l]}), occur[lis[l]]++, occs.insert({occur[lis[l]], lis[l]});
                
            }
            while (R < r) {
                r--;
                if (occur[lis[r]]==0) occur[lis[r]]++, occs.insert({1, lis[r]});
                else occs.erase({occur[lis[r]], lis[r]}), occur[lis[r]]++, occs.insert({occur[lis[r]], lis[r]});
                
            }
            while (R > r) {
                r++;
                if (occur[lis[r]]==1) occs.erase({1, lis[r]}), occur[lis[r]]--;
                else occs.erase({occur[lis[r]], lis[r]}), occur[lis[r]]--, occs.insert({occur[lis[r]], lis[r]});
                
            }
            while (L < l) {
                l--;
                if (occur[lis[l]]==1) occs.erase({1, lis[l]}), occur[lis[l]]--;
                else occs.erase({occur[lis[l]], lis[l]}), occur[lis[l]]--, occs.insert({occur[lis[l]], lis[l]});
                
            }
            pair<int, int> end = {-1, -1};
            for (pair<int, int> a : occs) {
                cout << a.first << ' ' << a.second << endl;
                end = a;
            }
            cout << end.first << endl;
        }
    }

    return 0;
}