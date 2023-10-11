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

string inp;
int count(int l, int r){
    int out = 0;
    for(int i = l; i <= r; i++){
        // cout << inp[i] << ln;
        if(inp[i]=='0') out++;
    }
    return out;
}

void solve()
{
    cin >> inp;
    int n = sz(inp);
    int zo = 0, oz = 0;
    int one = 0, zero = 0;
    for(int i = 0; i < n; i++){
        if(inp[i]=='1') {
            one++;
            zo+=zero;
        }
        else{
            zero++;
            oz+=one;
        }
    }
    if(oz<zo){
        string temp;
        for(int i = 0; i < n; i++){
            if(inp[i]=='1') temp+='0';
            else temp+='1';
        }
        inp = temp;
    }
    int left = abs(oz-zo);
    int out = 0;
    if(left==0) return void(cout << 0 << ln);
    for(int i = n-1; i >= 0; i--){
        if(inp[i]!='0') continue;
        for(int j = 0; j < i; j++){
            if(inp[j]!='1') continue;
            int z = count(j, i);
            int o = i-j+1-z;
            // cout << z << ' ' << o << ln;
            if(o+z-1>left) continue;
            if(o+z-1==left) return void(cout << out+1 << ln);
            left-=o+z-1;
            out++;
            string temp = "";
            for(int k = 0; k < n; k++){
                if(k==i) temp += inp[j];
                else if(k==j) temp += inp[i];
                else temp += inp[k];
            }
            inp = temp;
            // continue;
        }
    }
    cout << 1/(1*1) << ln;
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