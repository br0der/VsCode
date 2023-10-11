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

vector<pair<int, string>> channels;

ll func(int simul){
    ll score = 0;
    for(int i = 0; i < sz(channels[0].second); i++){
        int recorded = 0;
        for(int j = 0; j < sz(channels); j++){
            if(recorded>=simul) break;
            if(channels[j].second[i]=='1')score-=channels[j].first, recorded++;
        }
    }
    return score;
}

void solve()
{
    int n; cin >> n;
    int m; cin >> m;
    ll k; cin >> k;
    channels = vector<pair<int, string>>(n);
    for(int i = 0; i < n; i++){
        cin >> channels[i].first;
        channels[i].first*=-1;
    }
    for(int i = 0; i < n; i++){
        cin >> channels[i].second;
    }
    sort(all(channels));

    int low = 1, high = n+1;
    while(low<high){
        int mid = (low+high)/2;
        // cout << low << ' ' << mid << ' ' << high << ln;

        ll ans = func(mid);
        // cout << mid << ' ' << ans << ln;
        if(ans>=k){
            high = mid;
        }
        else if(ans<k){
            low = mid+1;
        }
    }
    if(low==n+1) return void(cout << -1 << ln);
    cout << low << ln;
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