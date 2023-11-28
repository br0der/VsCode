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

vvdouble dp;
vdouble probs;

double func(int idx, int accep){
    // cout << idx << ln;
    if(idx>=sz(probs)) return (accep==0? 1 : 0);
    if(dp[idx][accep]<-.05){
        dp[idx][accep] = (1-probs[idx])*(func(idx+1, accep)); 
        if(accep!=0) dp[idx][accep] += probs[idx]*(func(idx+1, accep-1));
    }
    // cout << idx << ' ' << accep << ' ' << dp[idx][accep] << ln;
    return dp[idx][accep];
}

void solve()
{
    int n; cin >> n;
    // dp = vvdouble(n, vdouble(n+1, -1));
    // // cout << dp[0][0] << ' ' << dp[3][3] << ln;
    probs = vdouble(n);
    for(int i = 0; i < n; i++){
        cin >> probs[i];
        probs[i]/=100.0;
    }
    sort(all(probs));
    reverse(all(probs));
    int maxn = sz(probs);
    double maxe = 0;
    vdouble s = {1-probs[0], probs[0]};
    for(int j = 1; j <= maxn; j++){
        double e = 0;
        for(double i = 1; i <= j; i++){
            double k = pow(i, i/j);
            e+=k*s[i];
        }
        if(e>maxe){
            maxe = e;
        }
        else break;
        if(j<maxn){
            vdouble sn = {(1-probs[j])*s[0]};
            for(int i = 1; i < sz(s); i++){
                sn.pb(s[i]*(1-probs[j]) + s[i-1]*probs[j]);
            }
            sn.pb(probs[j]*s[sz(s)-1]);
            swap(sn, s);
        }
    }
    cout << setprecision(10) << fixed << maxe << ln;
    // double dn = (double)n;
    // double out = 0;
    // cout << func(0, 0) << ln;
    // for(int i = 1; i <= n; i++){
    //     double di = (double)i;
    //     out+=(pow(di, di/dn))*(func(0, i));
    //     cout << di << ' ' << pow(di, di/dn) << ' ' << func(0, i) << ln;
    // }
    // cout << setprecision(10) << fixed << out << ln;
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