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

vector<vector<char>> grid;
vvint group;
vint groupSize = {0, 0};

char gridGet(vector<vector<char>> g, pii coord){
    return g[coord.first][coord.second];
}

int gridGet(vvint g, pii coord){
    return g[coord.first][coord.second];
}

bool inBounds(pii coord){
    if(coord.first<0 or coord.first>=sz(grid) or coord.second<0 or coord.second>=sz(grid[0])) return false;
    return true;
}

void floodFill(pii s, int num){
    
    queue<pii> q;
    q.push(s);
    while(sz(q)>0){
        pii start = q.front(); q.pop();
        // if(gridGet(grid, start)=='x') groupSize[num]++;
        vector<pii> adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(pii a : adj){
            pii nxt = {start.first+a.first, start.second+a.second};
            if(not inBounds(nxt)) continue;
            if(gridGet(group, nxt)!=0) continue;
            q.push(nxt);
            group[nxt.first][nxt.second] = num;
        }
    }
    
}

void solve()
{
    string s; cin >> s;
    pii start = {-1, -1};
    while(s!="."){
        grid.pb(vector<char>());
        grid.pb(vector<char>());
        int l = sz(grid)-2;
        for(int i = 0; i < sz(s); i++){
            if(s[i]=='.'){
                grid[l].pb('x');
                grid[l].pb('x');
                grid[l+1].pb('x');
                grid[l+1].pb('x');
            }
            if(s[i]=='|'){
                grid[l].pb('.');
                grid[l].pb('|');
                grid[l+1].pb('.');
                grid[l+1].pb('|');
            }
            if(s[i]=='-'){
                grid[l].pb('.');
                grid[l].pb('.');
                grid[l+1].pb('-');
                grid[l+1].pb('-');
            }
            if(s[i]=='J'){
                grid[l].pb('.');
                grid[l].pb('|');
                grid[l+1].pb('-');
                grid[l+1].pb('J');
            }
            if(s[i]=='L'){
                grid[l].pb('.');
                grid[l].pb('|');
                grid[l+1].pb('.');
                grid[l+1].pb('L');
            }
            if(s[i]=='F'){
                grid[l].pb('.');
                grid[l].pb('.');
                grid[l+1].pb('.');
                grid[l+1].pb('F');
            }
            if(s[i]=='7'){
                grid[l].pb('.');
                grid[l].pb('.');
                grid[l+1].pb('-');
                grid[l+1].pb('7');
            }
            if(s[i]=='S'){
                grid[l].pb('.');
                grid[l].pb('|');
                grid[l+1].pb('-');
                grid[l+1].pb('S');
            }
        }
        if(s.find("S")!=string::npos) start = {sz(grid)-1, s.find("S")*2+1};
        cin >> s;
    }
    group = vvint(sz(grid), vint(sz(grid[0]), 0));
    /*
    |
    -
    J
    L
    F
    7
    .
    */
    map<char, vector<pii>> mp;
    mp.insert({'|', {{1, 0}, {-1, 0}}});
    mp.insert({'-', {{0, 1}, {0, -1}}});
    mp.insert({'J', {{0, -1}, {-1, 0}}});
    mp.insert({'L', {{0, 1}, {-1, 0}}});
    mp.insert({'F', {{1, 0}, {0, 1}}});
    mp.insert({'7', {{1, 0}, {0, -1}}});
    mp.insert({'S', {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}});
    mp.insert({'.', {}});
    mp.insert({'x', {}});
    pii last = {start.first, start.second+1};
    pii curr = start;
    int dist = 0;
    
    while(dist==0 or curr!=start){
        group[curr.first][curr.second] = 1;
        groupSize[1]++;
        pii nxt;
        for(pii a : mp[gridGet(grid, curr)]){
            nxt = {curr.first+a.first, curr.second+a.second};
            if(nxt.first<0 or nxt.first>=sz(grid) or nxt.second<0 or nxt.second>=sz(grid[0])) continue;
            if(nxt==last) continue;
            last = curr;
            curr = nxt;
            break;
        }
        // cout << curr.first << ' ' << curr.second << ln;
        // cout << gridGet(grid, curr) << ln;
        dist++;
    }
    int nxtGroup = 2;
    
    for(int r = 0; r < sz(grid); r++){
        for(int c = 0; c < sz(grid[0]); c++){
            if(gridGet(group, {r, c})==0){
                groupSize.pb(0);
                floodFill({r, c}, nxtGroup);
                nxtGroup++;
            }
        }
    }
    for(int r = 0; r < sz(grid); r+=2){
        for(int c = 0; c < sz(grid[0]); c+=2){
            if(group[r][c]==group[r+1][c] and group[r][c]==group[r+1][c+1] and group[r][c]==group[r][c+1]){
                groupSize[group[r][c]]++;
            }
        }
    }
    for(int r = 0; r < sz(grid); r++){
        for(int c = 0; c < sz(grid[0]); c++){
            cout << group[r][c] << ' ';
        }
        cout << ln;
    }
    for(int r = 0; r < sz(grid); r++){
        groupSize[group[r][0]] = 0;
        groupSize[group[r][sz(grid[0])-1]] = 0;
    }
    for(int c = 0; c < sz(grid[0]); c++){
        groupSize[group[0][c]] = 0;
        groupSize[group[sz(grid)-1][c]] = 0;
    }
    int out = 0;
    for(int i = 2; i < sz(groupSize); i++){
        out+=groupSize[i];
    }
    for(int i = 0; i < sz(groupSize); i++) cout << groupSize[i] << ' ';
    cout << ln;
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