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
#define pb push_back
string ln = "\n";

int divisor(int n){
    int out = 1;

    while(n%2==0) out*=2, n/=2;
    return out;
}

void solve()
{
    int n; cin >> n;
    vint lis;
    lis.pb(n);
    // vint diffs;
    // bool nxt = true;
    while(n!=1){
        int temp = divisor(n);
        if(temp==n) temp/=2;
        n-=temp;
        // diffs.pb(temp);
        lis.pb(n);
    }
    // for(int i = 0; i < 1000; i++){
    //     int a = divisor(n), b = n/(divisor(n))-1;
    //     if(a==n){
    //         n--;
    //         diffs.pb(1);
    //         lis.pb(n);
    //         continue;
    //     }
    //     cout << a << ' ';
    //     n-=a;
    //     diffs.pb(a);
    //     lis.pb(n);
    //     a--;
    //     cout << b << ' ';
    //     n-=b;
    //     diffs.pb(b);
    //     lis.pb(n);
    //     b--;
    // }
    // sort(all(diffs));
    // for(int i = 0; i < sz(diffs); i++) cout << diffs[i] << ' ';
    // cout << endl;
    cout << sz(lis) << ln;
    for(int i = 0; i < sz(lis); i++) cout << lis[i] << ' ';
    cout << endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}