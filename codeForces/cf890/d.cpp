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
string ln = "\n";

int largest(int l, int r){
    if(l>=r) return l;
    if(r-l==1){
        cout << "? " << l+1 << ' ' << r+1 << ln;
        cout.flush();
        int temp; cin >> temp;
        // if(temp==-1) cout << 1/(1-1);
        return r-temp;
    }
    int mid = (l+r)/2;
    int left = largest(l, mid);
    int right = largest(mid+1, r);
    if(right-left==1){
        cout << "? " << left+1 << ' ' << right+1 << ln;
        cout.flush();
        int temp; cin >> temp;
        // if(temp==-1) cout << 1/(1-1);
        return right-temp;
    }
    int ans1;
    cout << "? " << left+1 << ' ' << right+1 << ln;
    cout.flush();
    cin >> ans1;
    // if(ans1==-1) cout << 1/(1-1);
    
    int ans2;
    cout << "? " << left+2 << ' ' << right+1 << ln;
    cout.flush();
    cin >> ans2;
    // if(ans2==-1) cout << 1/(1-1);

    if(ans1-ans2==right-left){
        return left;
    }
    return right;
}

void solve()
{
    int n; cin >> n;
    int ans = largest(0, n-1)+1;
    cout << "! " << ans << endl;
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../../data/input.txt","r", stdin);
    //     freopen("../../data/output.txt","w", stdout);
    // #endif
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}