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
int n, m, k;
vector<vector<bool>> visited;
vector<string> words;
int lastWord = -1, nxtidx = 0;
vector<pii> adj = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<char>> grid;
bool inBounds(int r, int c){return (r>=0 and r<n and c>=0 and c<m);}

int dfs(int r, int c){
    if(lastWord!=-1 and nxtidx==sz(words[lastWord])) lastWord=-1, nxtidx = 0;
    if(r==n-1 and lastWord==-1) return 1;
    visited[r][c] = true;
    int out = -1;
    // cout << r << ' ' << c << ln;
    for(pii ad : adj){
        int i = ad.first+r, j = ad.second+c;
        if(not inBounds(i, j)) continue;
        if(visited[i][j]) continue;
        if(lastWord==-1){
            for(int l = 0; l<k; l++){
                if(words[l][0]==grid[i][j]){
                    lastWord = l, nxtidx = 1;
                    int t = dfs(i, j);
                    if(t!=-1) out = max(out, t+1);
                    lastWord = -1, nxtidx = 0;
                }
            }
        }
        else{
            if(words[lastWord][nxtidx]==grid[i][j]){
                int tl = lastWord, tn = nxtidx;
                nxtidx++;
                int t = dfs(i, j);
                if(t!=-1) out = max(out, t+1);
                lastWord = tl, nxtidx = tn;
            }
        }
    }
    visited[r][c] = false;
    return out;
}

void solve()
{
    cin >> n >> m >> k;
    grid = vector<vector<char>>(n, vector<char>(m));
    visited = vector<vector<bool>>(n, vector<bool> (m, false));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    words = vector<string>(k);
    for(int i = 0; i<k; i++){
        cin >> words[i];
    }
    int o = 1e9;
    for(int i = 0; i<m; i++){
        for(int j = 0; j < k; j++){
            if(words[j][0]==grid[0][i]){
                lastWord = j, nxtidx = 1;
                int t = dfs(0, i);
                if(t!=-1) o = min(t, o);
            }
        }
    }
    if(o==1e9){
        cout << "impossible" << ln;
    }
    else{
        cout << o << ln;
    }
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