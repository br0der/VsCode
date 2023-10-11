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


void solve()
{
    int n; cin >> n;
    int b = 0, s = 0;
    for(int i = 0; i < n; i++){
        string temp; cin >> temp;
        if(temp=="bronze") b++;
        if(temp=="silver"){
            if(b==0){
                cout << "NO" << ln;
                return;
            }
            b--;
            s++;
        }
        if(temp=="gold"){
            if(s==0){
                if(b<3){
                    cout << "NO" << ln;
                    return;
                }
                b-=3;
            }
            else if(b==0){
                cout << "NO" << ln;
                return;
            }
            else{
                s--;
                b--;
            }
        }
    }
    cout << "YES" << ln;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}