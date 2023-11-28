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

vector<bool> prime = vector<bool>(100001, true);
vector<int> primeLis;
map<int, int> nxtPrim;

vint factor(ll num){
    vint facs;
    for(int div = 2; div*div <= num; div++){ 
        while(num%div==0){
            num/=div;
            facs.pb(div);
        }
    }
    if(sz(facs)==0) facs.pb(num);
    return facs;
}

struct Node{
    Node* skip = nullptr;
    Node* noskip = nullptr;
    int prim = -1;
    int pre = -1, post = -1;
    int cnt = 0;
    Node(int p){
        prim = p;
        // if(p!=nullptr) rank = p->rank+1;
        // for(int i = 0; i < 26; i++) connect[i] = nullptr;
    }
    void insert(vint &facs){
        Node* curr = this;
        curr->cnt++;
        for(int i = 0; i < sz(facs); i++){
            while(curr->prim<facs[i]){
                if(curr->skip==nullptr){
                    curr->skip = new Node(nxtPrim[curr->prim]);
                }
                curr = curr->skip;
            }
        }
    }
    ll cnt(vint &facs){
        Node* curr = this;
        ll out = 0;
        for(int i = 0; i < sz(facs); i++){
            while(curr->prim<facs[i]){
                if(curr->skip==nullptr){
                    return 0;
                }
                if(curr->skip==nullptr){
                    curr->skip = new Node(nxtPrim[curr->prim]);
                }
            }
        }
    }
};

void solve()
{
    int n; cin >> n;
    vint lis(n); for(int _ = 0; _ < n; _++) cin >> lis[_];
    vlong seen = vlong(100005, 0);
    sort(all(lis));
    ll out = 0;
    Node* t = new Node();
    for(int i = 0; i < n; i++){
        vint f = factor(lis[i]);
        for(int i = 0; i < sz(f); i++) cout << f[i] << ' ';
        cout << ln;
        for(int fac : f){
            out+=(seen[fac])*(n-i);
        }
        for(int fac : f){
            seen[fac]++;
        }
    }
    cout << out << ln;
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    prime[1] = false;
    int last = -1;
    for (ll p = 2; p <= 100000; p++) {
        if (prime[p] == true) {
            primeLis.pb(p);
            nxtPrim[last] = p;
            last = p;
            for (ll i = p*p; i <= 100000; i += p){
                prime[i] = false;
            }
        }
    }
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}