//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>
#include <set>
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

int num = 0;
void solve(int t)
{
    int n; cin >> n;
    vint lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    set<int> unique;
    vint cnt(n+1, 0);
    for(int i = 0; i < n; i++){
        unique.insert(lis[i]);
        cnt[lis[i]]++;
    }
    int i = 0;
    multiset<int, less<int> > behind;
    // behind.insert(1e9);
    set<int> used;
    vint out;
    for(int j = 0; j < n; ){
        if (used.count(lis[j])) continue;
        cnt[lis[j]]--;
        behind.insert(lis[j]);
        cout << j << ln;
        if (cnt[lis[j]]==0) {
            while (i <= j) { 
                if (used.count(lis[i])) {
                    i++;
                    continue;
                }
                if (sz(out)%2==0) {
                    if (lis[i]==*behind.rbegin()) {
                        out.pb(lis[i]);
                        used.insert(lis[i]);
                        behind.erase(lis[i]);
                        i++;
                        if (lis[i]==lis[j]) {
                            j++;
                            break;
                        }
                    }
                    else {
                        behind.erase(behind.find(lis[i]));
                    }
                }
                else {
                    if (lis[i]==*behind.begin()) {
                        out.pb(lis[i]);
                        used.insert(lis[i]);
                        behind.erase(lis[i]);
                        i++;
                        if (lis[i]==lis[j]) {
                            j++;
                            break;
                        }
                    }
                    else {
                        behind.erase(behind.find(lis[i]));
                    }
                }
                i++;
            }
            if (i > j) j++;
        }
        else {
            j++;
        }
    }
    // assert(sz(unique)==sz(out));
    cout << sz(out) << ln;
    // if (num+sz(out) >= 7289) cout << "tc" <<  t << ln;
    for(int i = 0; i < sz(out); i++) cout << out[i] << ' ';
    cout << ln;
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    ll t; cin >> t;
    while(t--) solve(t);
    return 0;
}