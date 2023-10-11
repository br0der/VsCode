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

ll idx, total, n;

bool test(ll num){
    num = n-num-1;
    return total-((num*(num+1))/2)>=idx;
}

string getS(string s, int numTaken){
    deque<char> st;
    int i = 0;
    for(; i < sz(s); i++){
        if(numTaken==0) break;
        while(not st.empty() and st.back()>s[i] and numTaken>0) st.pop_back(), numTaken--;
        st.push_back(s[i]);
    }
    // int temp = sz(st);
    // cout << sz(st) << ' ' << numTaken << ln;
    string out = "";
    if(numTaken==0){
        while(not st.empty()) out+=st.front(), st.pop_front();
        for(; i < sz(s); i++){
            out+=s[i];
        }
        return out;
    }
    
    while(numTaken>0) st.pop_back(), numTaken--;
    while(not st.empty()) out+=st.front(), st.pop_front();
    return out;
}

void solve()
{
    string str; cin >> str;
    n = sz(str);
    cin >> idx;
    total = (n*(n+1))/2;
    ll ans = -1, lo = 0, hi = n-1;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(test(mid)) ans = mid, hi = mid-1;
        else lo = mid+1;
    }
    // cout << ans << ln;
    int numTaken = ans;
    string s = getS(str, numTaken);
    // cout << s << ln;
    ans = n-ans;
    idx = idx-total+((ans*(ans+1))/2)-1;
    // cout << idx << ' ' << ans << ln;
    cout << s[idx];
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}