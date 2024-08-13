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
    int m; cin >> m;
    int k; cin >> k;
    string str; cin >> str;
    int lastW = -1;
    int lastIdx = -1;
    while(lastIdx!=n){
        if (lastIdx>=0 && str[lastIdx]=='C') {
            cout << "NO" << ln;
            return;
        }
        if (lastIdx>=0 && str[lastIdx]=='W') {
            lastIdx++;
            k--;
            if (k < 0) {
                cout << "NO" << ln;
                return;
            }
            continue;
        }
        bool jumped = false;
        if (lastIdx + m >= n) {
            cout << "YES" << ln;
            return;
        }
        for(int j = m; j >= 1; j--){
            if (str[lastIdx+j]=='L'){
                lastIdx += j;
                jumped = true;
                break;
            }
        }
        if (!jumped) {
            lastIdx += m;
        }
    }
    cout << (k < 0? "NO" : "YES") << ln;
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