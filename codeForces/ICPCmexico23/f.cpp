//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
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
#define pb(x) (push_back(x))

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    vint ans(1e6+1, 100000000);
    for(int i = 1; i <= 1e6; i++){
        int n = i;
        set<int> seq;
        while(!seq.count(n) and ans[n]==100000000){
            seq.insert(n);
            int temp = 0;
            while(n>0){
                temp+=(n%10)*(n%10);
                n/=10;
            }
            n = temp;
            // cout << n << endl;
        }
        ans[i] = min(*seq.begin(), ans[n]);
        // cout << i << ' ' << ans[i] << endl;
    }
    int a; cin >> a;
    int b; cin >> b;
    ll out = 0;
    for(int i = a; i <= b; i++){
        out+=ans[i];
    }
    cout << out << endl;
    return 0;
}