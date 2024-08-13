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

int num;

int query(int a, int b) {
    // cout << "? " << a << " " << b << ln;
    // cout.flush();
    if (b>=num && a >= num) return (a+1)*(b+1);
    if (b>=num) return a*(b+1);
    return a*b;
}

int bad = false;

void solve()
{
    int lo = 1, hi = 1000, ans = -1;
    int cnt = 0;
    while (lo <= hi) {
        cnt++;
        // cout << lo << ' ' << hi << ln;
        int m1 = (lo+hi+lo)/3;
        int m2 = (lo+hi+hi)/3;
        int res = query(m1, m2);
        // cout << res << ln;
        if (res==-1) {bad = true; return;}
        if (res==m1*m2) {
            lo = m2+1;
        }
        else if (res==m1*(m2+1)) {
            hi = m2-1;
            lo = m1+1;
            ans = m2;
        }
        else {
            hi = m1-1;
            ans = m1;
        }
    }
    cout << "! " << ans << ln; 
    assert(cnt <= 7);
    assert(ans==num);
    cout.flush();
}
int main()
{
    fast_cin();
    // #ifndef ONLINE_JUDGE
    //     freopen("../../data/input.txt","r", stdin);
    //     freopen("../../data/output.txt","w", stdout);
    // #endif
    // ll t; cin >> t;
    // while(t-- && !bad) solve();
    for(int i = 1; i <= 1000; i++){
        num = i;
        solve();
    }
    return 0;
}