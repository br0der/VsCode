//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<double> vdouble;
typedef vector<vector<int> > vvint;
typedef vector<vector<ll> > vvlong;
typedef vector<vector<double> > vvdouble;
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";

bool failed = false;

void solve()
{
    int n; cin >> n;
    if (n==-1) failed = true;
    if(failed) return;
    int m; cin >> m;
    vector<set<int> > adj(n);
    for(int i = 0; i < m; i++){
        int a; cin >> a;
        int b; cin >> b;
        a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    vint color(n, -1);
    queue<int> q;
    q.push(0);
    color[0] = 0;
    bool colorable = true;
    while (sz(q)) {
        int curr = q.front();
        q.pop();
        for (int nxt : adj[curr]) {
            if (color[nxt] == color[curr]) {
                colorable = false;
                break;
            }
            if (color[nxt]==-1) q.push(nxt);
            color[nxt] = 1 - color[curr];
        }
        if (!colorable) break;
    }
    queue<int> c1, c2;
    for(int i = 0; i < n; i++){
        if (color[i]==0) c1.push(i);
        else c2.push(i);
    }
    if (!colorable) {
        cout << "Alice" << ln;
        cout.flush();
        for(int i = 0; i < n; i++){
            cout << "1 2" << ln;
            cout.flush();
            int temp1, temp2; cin >> temp1 >> temp2;
        }
    }
    else {
        cout << "Bob" << ln;
        cout.flush();
        for(int i = 0; i < n; i++){
            int a, b; cin >> a >> b;
            if (a>b) swap(a, b);
            if (a==1) {
                if (sz(c1)==0) {
                    cout << c2.front()+1 << ' ' << b << ln;
                    cout.flush();
                    c2.pop();
                }
                else {
                    cout << c1.front()+1 << ' ' << a << ln;
                    cout.flush();
                    c1.pop();
                }
            }
            else if (a==2) {
                if (sz(c2)==0) {
                    cout << c1.front()+1 << ' ' << b << ln;
                    cout.flush();
                    c1.pop();
                }
                else {
                    cout << c2.front()+1 << ' ' << a << ln;
                    cout.flush();
                    c2.pop();
                }
            }
            else {
                cout << "What" << ln;
                cout.flush();
            }
        }
    }
}
int main()
{
    fast_cin();
    // #ifndef ONLINE_JUDGE
    //     freopen("../../data/input.txt","r", stdin);
    //     freopen("../../data/output.txt","w", stdout);
    // #endif
    ll t; cin >> t;
    while(t-- and !failed) solve();
    return 0;
}