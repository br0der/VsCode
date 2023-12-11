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

bool zero(vint v){
    if(sz(v)==0) return true;
    return *min_element(all(v))==*max_element(all(v)) and v[0]==0;
}

void solve()
{
    vector<vvint> seqs;
    for(int i = 0; i < 200; i++){
        seqs.pb(vvint());
        seqs[i].pb(vint());
        for(int j = 0; j < 21; j++){
            int temp; cin >> temp;
            seqs[i][0].pb(temp);
        }
    }
    int out = 0;
    for(int i = 0; i < sz(seqs); i++){
        while(not zero(seqs[i][sz(seqs[i])-1])){
            seqs[i].pb(vint());
            for(int j = 0; j < sz(seqs[i][sz(seqs[i])-2])-1; j++){
                seqs[i][sz(seqs[i])-1].pb(seqs[i][sz(seqs[i])-2][j+1]-seqs[i][sz(seqs[i])-2][j]);
            }
        }
        int a = 0;
        for(int j = 0; j < sz(seqs[i]); j++){
           a+=seqs[i][j][0] * (j%2==0 ? 1 : -1);
        }
        out+=a;
    }
    cout << out << ln;
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../data/input.txt","r", stdin);
        freopen("../data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}