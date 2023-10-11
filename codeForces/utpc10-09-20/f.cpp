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
    vector<string> grid;
    for(int i = 0; i < 3; i++){
        string temp;
        cin >> temp;
        grid.pb(temp);
    }
    // int col = 1;
    // vint last;
    
    queue<pii> q;
    for(int i = 0; i < 3; i++){
        if(grid[i][0]=='0')q.push({i, 0});
    }
    set<pii> visited;
    while(sz(q)){
        pii curr = q.front();
        // cout << curr.first << ' ' << curr.second << endl;
        q.pop();
        if(visited.count(curr)) continue;
        visited.insert(curr);
        if(curr.second==n-1){
            cout << "Solvable!" << endl;
            return;
        }
        if(curr.first!=0){
            if(grid[curr.first-1][curr.second]=='0'){
                q.push({curr.first-1, curr.second});
            }
        }
        if(curr.first!=2){
            if(grid[curr.first+1][curr.second]=='0'){
                q.push({curr.first+1, curr.second});
            }
        }
        if(grid[curr.first][curr.second+1]=='0'){
            q.push({curr.first, curr.second+1});
        }
    }
    cout << "Unsolvable!" << endl;
    
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