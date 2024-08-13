//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<double> vdouble;
typedef vector<vector<int> > vvint;
typedef vector<vector<ll> > vvlong;
typedef vector<vector<double> > vvdouble;
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

vint parents;
vlong sizes;

int find(int a) {
    if (parents[a] == a) {
        return a;
    }
    parents[a] = find(parents[a]);
    return parents[a];
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
        return;
    }

    if (sizes[a] < sizes[b]) {
        swap(a, b);
    }
    sizes[a] += sizes[b];
    parents[b] = a;
}

void solve()
{
    int intersections; cin >> intersections;
    int roadCount; cin >> roadCount;
    assert(0 <= roadCount && roadCount <= 100000);

    parents = vint(intersections, -1);
    sizes = vlong(intersections, 1);

    for(int i = 0; i < intersections; i++){
        parents[i] = i;
    }

    vector<pair<ll, pii> > roads;

    for(int i = 0; i < roadCount; i++){
        int a; cin >> a;
        int b; cin >> b;
        assert(1 <= a && a <= intersections);
        assert(1 <= b && b <= intersections);
        a--, b--;
        assert(a!=b);
        ll dist; cin >> dist;
        assert(1 <= dist && dist <= 1000000000);
        roads.emplace_back(dist, make_pair(a, b));
    }

    sort(all(roads));
    
    int queryNum; cin >> queryNum;
    vector<pll> queries;
    
    for(int i = 0; i < queryNum; i++){
        int temp; cin >> temp;
        assert(1 <= temp && temp <= 1000000000);
        queries.emplace_back(temp, i);
    }
    sort(all(queries));
    ll pairs = 0;
    int nxtRoad = 0;
    for(int i = 0; i < queryNum; i++){
        while(nxtRoad < roadCount && roads[nxtRoad].first <= queries[i].first) {
            int a = find(roads[nxtRoad].second.first);
            int b = find(roads[nxtRoad].second.second);
            nxtRoad++;
            if (a == b) {
                continue;
            }
            ll newSize = sizes[a] + sizes[b];
            pairs -= (sizes[a]*(sizes[a] - 1))/2;
            pairs -= (sizes[b]*(sizes[b] - 1))/2;
            merge(a, b);
            pairs += (newSize*(newSize - 1))/2;
            
        }

        queries[i].first = queries[i].second;
        queries[i].second = pairs;
    }
    sort(all(queries));
    
    for(int i = 0; i < queryNum; i++){
        cout << queries[i].second << ln;
    }
}
int main()
{
    fast_cin();
    // #ifndef ONLINE_JUDGE
    //     freopen("moar_large.in","r", stdin);
    //     freopen("../../../data/output.txt","w", stdout);
    // #endif
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}