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
    ll n; cin >> n;
    ll k; cin >> k;
    ll l; cin >> l;
    string seq; cin >> seq;
    string temp; cin >> temp;
    vector<bool> bad(26, false);
    for(char c : temp) bad[c-'a'] = true;
    vlong idxs;
    for(int i = 0; i < n; i++){
        if(bad[seq[i]-'a']){
            idxs.push_back(i);
        }
    }
    ll i = 0, j = k-1, risks = 0;
    ll out = 0;
    while(j<sz(idxs)){
        ll right;
        ll left;
        if(i==0) left = idxs[i]+1;
        else left = idxs[i]-idxs[i-1];
        if(j==sz(idxs)-1) right = n-idxs[j];
        else right = idxs[j+1]-idxs[j];
        out+=right*left;
        j++;
        i++;
    }
    cout << out << endl;
    return 0;
}