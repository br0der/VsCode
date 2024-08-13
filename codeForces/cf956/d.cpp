//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>
#include <map>

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
    vint a(n); for(int _ = 0; _ < n; _++) cin >> a[_];
    vint b(n); for(int _ = 0; _ < n; _++) cin >> b[_];
    map<int, int> binv;
    for(int i = 0; i < n; i++){
        binv[b[i]] = i;
    }
    bool works = true;
    for(int i = 0; i < n; i++){
        if (binv.find(a[i]) == binv.end()) {
            works = false;
        }
    }
    int even = 0;
    int odd = 0;
    int orr = 0;
    int cycles = 0;
    if (works) {
        vector<bool> visited = vector<bool>(n, false);
        
        for(int i = 0; i < n; i++){
            if (visited[i]) continue;
            visited[i] = true;
            int curr = binv.at(a[i]);
            int l = 1;
            while (curr != i) {
                visited[curr] = true;
                curr = binv.at(a[curr]);
                l++;
                if (l > 10000000) {
                    assert(1==0);
                }
            }
            if (l%2 == 1) {
                continue;
            }
            cycles++;
            bool o = false, e = false;
            if(abs(i - binv.at(a[i]))%2==1) o=true;
            else e=true;
            curr = binv.at(a[i]);
            while (curr!=i) {
                if(abs(curr - binv.at(a[curr]))%2==1) o=true;
                else e = true;
                curr = binv.at(a[curr]);
            }
            if (o&&e) orr++;
            else if (o) odd++;
            else if (e) even++;
        }
    }
    // cout << odd << ' ' << even << ln;
    orr-=odd;
    orr-=even;
    cout << ((works&&orr%2==0&&cycles%2==0)? "YES" : "NO") << ln;
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