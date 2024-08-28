//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>
#include <queue>

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


void solve()
{
    int n; cin >> n;
    int k; cin >> k;
    priority_queue<pair<int, int> > pq;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        pq.push(make_pair(-min(a, b), -max(a, b)));
    }
    ll cost = 0;
    int amt = 0;
    while (sz(pq) && amt < k) {
        pair<int, int> curr = pq.top(); pq.pop();
        amt++;
        cost-=curr.first;
        if (curr.first==-1 && curr.second==-1) amt++;
        else pq.push(make_pair(max(curr.first, curr.second+1), min(curr.first, curr.second+1)));
    }
    if (amt<k) cout << -1 << ln;
    else cout << cost << ln;
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}