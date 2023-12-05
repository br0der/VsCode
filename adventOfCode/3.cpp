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

vector<string> grid;

bool isSymbol(int r, int c){
    if(r>=0 and c>=0 and r<sz(grid) and c<sz(grid[0])){
        return (not isdigit(grid[r][c])) and (grid[r][c]!='.');
    }
    return false;
}

bool isStar(int r, int c){
    if(r>=0 and c>=0 and r<sz(grid) and c<sz(grid[0])){
        return grid[r][c]=='*';
    }
    return false;
}

void solveone()
{
    int out = 0;
    for(int r = 0; r < sz(grid); r++){
        int begin = -1;
        for(int c = 0; c <= sz(grid[0]); c++){
            if(begin==-1){
                if(c==sz(grid[0])) continue;
                if(isdigit(grid[r][c])) begin = c;
            }
            else{
                if(c<sz(grid[0]) and isdigit(grid[r][c])){
                    continue;
                }
                else{
                    bool good = false;
                    for(int i = begin-1; i < c+1; i++){
                        good|=isSymbol(r-1, i);
                        good|=isSymbol(r+1, i);
                    }
                    good|=isSymbol(r, begin-1);
                    good|=isSymbol(r, c);
                    if(good){
                        int num = 0;
                        for(int i = begin; i < c; i++){
                            num*=10;
                            num+=grid[r][i]-'0';
                        }
                        cout << num << ln;
                        out+=num;
                    }
                    begin = -1;
                }
            }
        }
    }
    cout << out << ln;
}

void solvetwo()
{
    int out = 0;
    map<pii, vint> starNums;
    for(int r = 0; r < sz(grid); r++){
        int begin = -1;
        for(int c = 0; c <= sz(grid[0]); c++){
            if(begin==-1){
                if(c==sz(grid[0])) continue;
                if(isdigit(grid[r][c])) begin = c;
            }
            else{
                if(c<sz(grid[0]) and isdigit(grid[r][c])){
                    continue;
                }
                else{
                    int num = 0;
                    for(int i = begin; i < c; i++){
                        num*=10;
                        num+=grid[r][i]-'0';
                    }
                    for(int i = begin-1; i < c+1; i++){
                        if(isStar(r-1, i)) starNums[{r-1, i}].pb(num);
                        if(isStar(r+1, i)) starNums[{r+1, i}].pb(num);
                    }
                    if(isStar(r, begin-1)) starNums[{r, begin-1}].pb(num);
                    if(isStar(r, c)) starNums[{r, c}].pb(num);
                    begin = -1;
                }
            }
        }
    }
    for(auto it = starNums.begin(); it!=starNums.end(); it++){
        if(sz(it->second)==2){
            out+=it->second[0]*it->second[1];
            cout << it->second[0]*it->second[1] << ln;
        }
    }
    cout << out << ln;
}

int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../data/input.txt","r", stdin);
        freopen("../data/output.txt","w", stdout);
    #endif
    string inp; cin >> inp;
    while(inp!="."){
        grid.pb(inp);
        cin >> inp;
    }
    solvetwo();
    return 0;
}