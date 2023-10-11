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

bool isPow2(ll num){
    if(num==0) return true;
    if(num%2==0) return isPow2(num/2);
    if(num==1) return true;
    return false;
}

void solve()
{
    int n; cin >> n;
    vlong lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    ll total = 0;
    for(int i = 0; i < n; i++){
        total+=lis[i];
    }
    if(total%n!=0) return void(cout << "No" << ln);
    ll avg = total/n;
    map<ll, int> a;
    for(int i = 0; i < n; i++){
        if(avg-lis[i]>0){
            a[(avg-lis[i])&-(avg-lis[i])]++;
            a[-1*((avg-lis[i])+(avg-lis[i])&-(avg-lis[i]))]++;
        }
        else{
            a[-1*(abs(avg-lis[i])&-abs(avg-lis[i]))]++;
            a[abs(avg-lis[i])+abs(avg-lis[i])&-abs(avg-lis[i])]++;
        }
        ll num = abs(avg-lis[i]);
        if(not isPow2(num + num&-num)) return void(cout << "No" << ln);

    }
    for(auto i : a){
        // cout << i.first << ' ' << s[i.first] << ' ' << i.second << ln;
        if(a[-1*(i.first)] != i.second) return void(cout << "No" << ln);
    }
    cout << "Yes" << ln;
} 
int main()
{
    fast_cin();
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