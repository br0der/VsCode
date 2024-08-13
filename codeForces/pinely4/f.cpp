//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>
#include <set>

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

bool canMake(multiset<int, less<int> > &ms) {
    if (sz(ms) < 6) return false;
    // vint addBack;
    auto ap = ms.begin();
    int a = *ap;
    ms.erase(ap);
    auto bp = ms.begin();
    int b = *bp;
    ms.erase(bp);
    auto ap2 = ms.begin();
    int a2 = *ap2;
    ms.erase(ap2);
    auto bp2 = ms.begin();
    int b2 = *bp2;
    ms.erase(bp2);

    auto cp = ms.begin();
    int c = *cp;
    if (cp == ms.end() || c >= a + b2) {
        ms.insert(a);
        ms.insert(b);
        ms.insert(a2);
        ms.insert(b2);
        return false;
    }
    ms.erase(cp);

    auto cp2 = ms.begin();
    int c2 = *cp2;
    if (cp2 == ms.end() || c2 >= a2 + b) {
        ms.insert(a);
        ms.insert(b);
        ms.insert(c);
        ms.insert(a2);
        ms.insert(b2);
        return false;
    }
    ms.insert(a);
    ms.insert(b);
    ms.insert(c);
    ms.insert(a2);
    ms.insert(b2);
    return true;
}

void solve()
{
    int n; cin >> n;
    int q; cin >> q;
    vint lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    vint mnEnd(n, -1);
    multiset<int, less<int> > ms;
    int j = 0;
    for(int i = 0; i < n; i++){
        while (sz(ms) < 6 or !canMake(ms)) {
            if (j >= n) break;
            ms.insert(lis[j]);
            j++;
        }
        cout << i << ' ' << j << ' ' << sz(ms) << ln;
        if (canMake(ms)) mnEnd[i] = j;
        auto p = ms.find(lis[i]);
        if (p==ms.end()) continue;
        ms.erase(p);
    }
    for(int i = 0; i < sz(mnEnd); i++) cout << mnEnd[i] << ' ';
    cout << ln;
    for(int i = 0; i < q; i++){
        int a; cin >> a;
        int b; cin >> b;
        a--;
        if (mnEnd[a]==-1) cout << "NO" << ln;
        else if (mnEnd[a] <= b) cout << "YES" << ln;
        else cout << "NO" << ln;
    }

    // for(int i = 0; i < n; i++){
    //     ms.insert(lis[i]);
    // }
    // multiset<int, less<int> >::iterator itr;
    // for (itr = ms.begin(); itr != ms.end(); ++itr) {
    //     cout << *itr << " ";
    // }
    cout << endl;
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}