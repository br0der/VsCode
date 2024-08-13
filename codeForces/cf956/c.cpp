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


void solve()
{
    int n; cin >> n;
    vvint abc = vvint(3, vint(n));
    ll total = 0;
    for(int _ = 0; _ < n; _++) cin >> abc[0][_];
    for(int _ = 0; _ < n; _++) cin >> abc[1][_];
    for(int _ = 0; _ < n; _++) cin >> abc[2][_], total+=abc[2][_];
    bool works = false;

    for(int i = 0; i < 3; i++){
        int cnt = 0;
        int curr = i;
        ll s = 0;
        vint ans = vint(6);
        ans[2*i] = 1;
        ans[(2*i + 5)%6] = n;
        for(int j = 0; j < n; j++){
            // for(int i = 0; i < sz(ans); i++) cout << ans[i] << ' ';
            // cout << ln;
            s += abc[curr][j];
            if (s >= (total+2)/3) {
                cnt ++;
                if (cnt >= 3) break;
                ans[2*curr + 1] = j+1;
                ans[(2*curr + 2)%6] = j+2;
                curr += 1;
                curr %= 3;
                s = 0;
            }
        }
        if (cnt >= 3) {
            for(int i = 0; i < sz(ans); i++) cout << ans[i] << ' ';
            works = true;
            break;
        }
    }
    
    if (!works) {
        for(int i = 0; i < 3; i++){
            int cnt = 0;
            int curr = i;
            ll s = 0;
            vint ans = vint(6, -1);
            ans[2*i] = 1;
            ans[(2*i + 3)%6] = n;
            for(int j = 0; j < n; j++){
                // for(int i = 0; i < sz(ans); i++) cout << ans[i] << ' ';
                // cout << ln;
                s += abc[curr][j];
                if (s >= (total+2)/3) {
                    cnt ++;
                    if (cnt >= 3) break;
                    ans[2*curr + 1] = j+1;
                    ans[(2*curr + 4)%6] = j+2;
                    curr += 2;
                    curr %= 3;
                    s = 0;
                }
            }
            if (cnt >= 3) {
                for(int i = 0; i < sz(ans); i++) cout << ans[i] << ' ';
                works = true;
                break;
            }
        }
    }

    cout << (works? "" : "-1") << ln;
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