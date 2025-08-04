#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <set>

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, a, b) for (int i = a; i < b; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define sz(x) (long long)(x).size()
#define ll long long
#define int long long

using namespace std;
int MOD = 998244353;

int n, k; 
vector<int> a;
// multiset<int> L, R;


pair<int, int> check(int mid, bool mx) {
    if (!mx) {
        mid*=-1;
        rep(i, n) a[i]*=-1;
    }
    vector<pair<int, int>> bestPref(n, {0, 1});
    if (a[0]>=mid) bestPref[0].second--;
    rep(i, n) if (a[i]>=mid) bestPref[i].first++;
    rep2(i, 1, n) {
        if (bestPref[i].first) {
            bestPref[i].first = bestPref[i-1].first+1;
            bestPref[i].second = bestPref[i-1].second;
        }
        else {
            bestPref[i].first = bestPref[i-1].first-1;
            bestPref[i].second = bestPref[i-1].second;
            if (bestPref[i].first < 0) {
                bestPref[i] = {0, i+1};
            }
        }
    }
    int acc = 0;
    rep(i, k-1) {
        acc+=a[i]>=mid? 1:-1;
    }

    pair<int, int> out = {-1, -1};
    rep(i, n-k+1) {
        acc+=a[i+k-1]>=mid? 1:-1;

        int score = acc;

        if (i!=0) {
            score+=bestPref[i-1].first;
            if (score >= 0) out = {bestPref[i-1].second+1, i+k};
        }
        else if (score>=0) out = {i+1, i+k};

        acc-=a[i]>=mid? 1:-1;
    }
    if (!mx) {
        mid*=-1;
        rep(i, n) a[i]*=-1;
    }

    return out;
}

pair<int, pair<int, int>> get(bool mx) {
    int lo = 1, hi = n, ans = -1;
    pair<int, int> ansp = {-1, -1};
    while (lo<=hi){
        int mid = (lo+hi)/2;
        auto res = check(mid, mx);
        if (res.first!=-1) {
            ans = mid;
            ansp = res;
            if (mx) lo = mid+1;
            else hi = mid-1;
        }
        else {
            if (mx) hi = mid-1;
            else lo = mid+1;
        }
    }
    return {ans, ansp};
}


#define MSETS std::multiset<long long>& l, std::multiset<long long>& r

void rightShift(MSETS) {
    if (l.empty()) return;                      // guard
    auto it = std::prev(l.end());
    r.insert(*it);
    l.erase(it);
}

void leftShift(MSETS) {
    if (r.empty()) return;                      // guard
    auto it = r.begin();
    l.insert(*it);
    r.erase(it);
}

void insert_ll(long long x, MSETS) {
    if (l.empty() || x <= *prev(l.end()))   // use prev(end())
        l.insert(x);
    else
        r.insert(x);

    if (l.size() < r.size())        leftShift(l, r);
    if (l.size() > r.size() + 1)    rightShift(l, r);
}

void remove_ll(long long x, MSETS) {
    auto itl = l.find(x);
    if (itl != l.end()) l.erase(itl);
    else {
        auto itr = r.find(x);
        if (itr != r.end()) r.erase(itr);
        else return; // x not present – decide what you want to do
    }

    if (l.size() < r.size())        leftShift(l, r);
    if (l.size() > r.size() + 1)    rightShift(l, r);
}

pair<long long,long long> median(MSETS) {
    if (l.size() != r.size())
        return { *prev(l.end()), *prev(l.end()) };
    else
        return { *prev(l.end()), *r.begin() };
}


signed main() {
    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> k;
        a = vector<int>(n); rep(i, n) cin >> a[i];
        auto top = get(true);
        auto bottom = get(false);

        set<int> todo; rep2(i, bottom.first, top.first+1) todo.insert(i);
        multiset<int> L, R;
        int l2 = top.second.first-1, r2 = top.second.second-1;
        int l1 = bottom.second.first-1, r1 = bottom.second.second-1;
        
        rep2(i, l1, r1+1) {
            insert_ll(a[i], L, R);
        }

        pair<int, int> med;
        cout << top.first - bottom.first+1 << endl;
        while (todo.size()) {
            // cout << l1 << ' ' << r1 << endl;

            med = median(L, R);
            auto it = todo.lower_bound(med.first);
            if (it!=todo.end() and *it <= med.second) {
                cout << *it << ' ' << l1+1 << ' ' << r1+1 << endl;
                todo.erase(it);
            }
            else {
                if (r1 < r2) {
                    r1++;
                    insert_ll(a[r1], L, R);
                }
                else if (l1 > l2) {
                    l1--;
                    insert_ll(a[l1], L, R);
                }
                else if (r1 > r2) {
                    remove_ll(a[r1], L, R);
                    r1--;
                }
                else if (l1 < l2) {
                    remove_ll(a[l1], L, R);
                    l1++;
                }
                else {
                    assert(false);
                }
            }
        }
    }
}