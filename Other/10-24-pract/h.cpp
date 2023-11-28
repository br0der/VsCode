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

vector<vvdouble> dp;

// double func1(int m1, int n1, int t1){
    
//     if((t1+n1)<=1 or m1<0 or n1<0 or t1<0){
//         return 0;
//     }
//     double m = m1, n = n1, t = t1;
//     if(dp[m1][n1][t1]==-1){
//         dp[m1][n1][t1] = n/(t+n) * (n-1)/(t+n-1) + 
//         2*m/(t+n) * 1/(t+n-1) + 
//         2*m/(t+n) * (2*m-2)/(t+n-1) * func1(m-2,n,t-2) + 
//         2*m/(t+n) * (t-2*m)/(t+n-1) * func1(m-1,n,t-2) + 
//         (2 * (t-2*m)/(t+n) * (t-2*m-1)/(t+n-1) * ((t-2*m >= 1)? func1(m,n,t-2) : 0)) + 
//         2 * n/(t+n) * (t-2*m)/(t+n-1) * func1(m,n-1,t-1) + 
//         2 * n/(t+n) * 2*m/(t+n-1) * func1(m-1,n-1,t-1);
//     }
//     return dp[m1][n1][t1];
// }

double func2(int m1, int n1, int t1){
    // if(m1==1 and n1==2 and t1==1) return 0.3;
    if(n1<=1 and m1==0){
        return 0;
    }
    double total = 2*m1 + n1 + t1;
    double m = m1, n = n1, t = t1;
    if(dp[m1][n1][t1]==-1){
        double ans = 0;
        if(m>0) ans+=(2*m/(total*(total-1)));
        if(n>1) ans+=(n*(n-1)/(total*(total-1)));
        
        if(m>1) {
            ans+=(2*m/total)*(2*(m-1)/(total-1))*func2(m1-2, n1, t1+2);
            // cout << (2*m/total)*(2*(m-1)/(total-1)) << ln; 
        }
        if(t>1) ans+=(t*(t-1)/(total*(total-1)))*func2(m1, n1, t1-2);
        if(m>0 and n>0) ans+=
                            (2*(2*m*n)/(total*(total-1)))
                            *func2(m1-1, n1-1, t1+1);
        if(m>0 and t>0) ans+=
                            (2*2*m*t/(total*(total-1)))*func2(m1-1, n1, t1);
        if(n>0 and t>0) ans+=
                            (2*n*t/(total*(total-1)))*func2(m1, n1-1, t1-1);
        dp[m1][n1][t1] = ans;                                      
    }
    // cout << m1 << ' ' << n1 << ' ' << t1 << ' ' << dp[m1][n1][t1] << ln;
    return dp[m1][n1][t1];
}

void solve()
{
    int m; cin >> m;
    int n; cin >> n;
    dp = vector<vvdouble>(m+1, vvdouble(n+1, vdouble(m+1, -1)));
    cout << setprecision(15) << fixed << 1-func2(m, n, 0) << ln;
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