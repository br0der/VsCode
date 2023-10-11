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
    int k; cin >> k;
    vector<string> nums;
    for(int i = 0; i < n; i++){
        string inp;
        cin >> inp;
        nums.pb(inp);
    }
    vector<pii> diffs;
    for(int i = 0; i < k; i++){
        int mn = int(nums[0][i]);
        int mx = int(nums[0][i]);
        // cout << nums[0][k] << ' ' << nums[0][k] << endl;
        for(int j = 1; j < n; j++){
            mn = min(int(nums[j][i]), mn);
            mx = max(int(nums[j][i]), mx);
        }
        diffs.pb({mx-mn, i});
    }
    sort(all(diffs));
    for(int i = 0; i < k; i++){
        cout << diffs[i].first;
    }
    // for(int i = 0; i < k; i++){
    //     cout << diffs[i].first << ' ' << diffs[i].second << endl;
    // }
    // vlong numsEdited;
    // for(int i = 0; i < n; i++){
    //     ll temp = 0;
    //     // cout << nums[i] << endl;
    //     for(int j = 0; j < sz(diffs); j++){
    //         // cout << temp << endl;
    //         temp*=10;
            
    //         temp+=int(nums[i][diffs[j].second])-'0';
    //     }
    //     // cout << temp << endl;
    //     numsEdited.pb(temp);
    // }
    // for(int i = 0; i < n; i++) cout << numsEdited[i] << ' ';
    // cout << endl;
    // cout << *max_element(all(numsEdited)) - *min_element(all(numsEdited)) << endl;
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