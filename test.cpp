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
ll MOD = 9758543491;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

ll expo(ll a, ll b){ 

    if(b==0 or a==1) return 1; 

    return ((ll)(b%2==1 ? a : 1) * (ll)expo((a*a)%MOD, b/2))%MOD; 

} 

vlong factor(ll num){ 

    vlong facs; 

    ll div = 2; 

    while(num>1){ 

        // facs.push_back(0); 

        // cout << num << endl; 

        while(num%div==0){ 
            facs.pb(div);
            num/=div; 

            // facs[sz(facs)-1]++; 

        } 

        div++; 

    } 

    return facs; 

} 

void solve()
{
    
}
int main(){
    vlong lis = factor((ll)9758543491);
    ll e = 47;
    // for(int i = 0; i < sz(lis); i++) cout << lis[i] << ' ';
    // cout << ln;
    ll n = (lis[0]-1)*(lis[1]-1);
    cout << n << ln;
    ll d = ((n*3)-1)/e;
    cout << d << ' ' << d*e << ln;
    ll d2 = 8097350591;
    
    cout << (d*e)%n << ln;
    cout << expo((ll)8599755573, ((n*3)-1)/47) << ln;
    cout << expo((ll)7, 47);
    return 0;
}