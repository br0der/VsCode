#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<double> vdouble;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvlong;
typedef vector<vector<double>> vvdouble;
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

vvint facs(100001, vint());

void solve()
{
    int n; cin >> n;
    int m; cin >> m;
    vector<bool> on(n+1, false);
    vint factors(100001, -1);
    for(int i = 0; i < m; i++){
        string a; cin >> a;
        int b; cin >> b;
        bool works = true;
        if(a=="+"){
            if(on[b]){
                cout << "Already on" << ln;
                continue;
            }
            
            for(int fac : facs[b]){
                if(factors[fac]!=-1){
                    cout << "Conflict with " << factors[fac] << ln;
                    works = false;
                    break;
                }
            }
            if(works){
                cout << "Success" << ln;
                for(int fac : facs[b]){
                    factors[fac] = b;
                }
                on[b] = true;
            }
        }
        else{
            // cout << sz(on) << ln;
            if(not on[b]){
                cout << "Already off" << ln;
                continue;
            }

            for(int fac : facs[b]){
                // if(p*p>b) break;
                factors[fac] = -1;
            }
            cout << "Success" << ln;
            on[b] = false;
        }
    }
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif

    vector<bool> prime = vector<bool>(100001, true);
    prime[1] = false;
    for (int p = 2; p <= 100000; p++) {
        facs[p].pb(p);
        if (prime[p] == true) {
            for (int i = p*2; i <= 100000; i += p){
                facs[i].pb(p);
                prime[i] = false;
            }
        }
    }
    facs[1].pb(1);

    solve();
    return 0;
}