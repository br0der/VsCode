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

int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../data/output.txt","w", stdout);
    #endif
    string line;
    ifstream file("../data/input.txt");
    vector<string> inp;
    if (file.is_open()) {
        while (getline(file, line)) inp.pb(line);
        file.close();
    }
    int r = 12, g = 13, b = 14;
    ll sum = 0;
    for(int j = 0; j < sz(inp); j++){
        string s = inp[j];
        int i = 0;
        while(s[i]!=':') i++;
        i+=2;
        bool works = true;
        int cr = 0, cg = 0, cb = 0;
        int mxr = 0, mxg = 0, mxb = 0;
        while(i!=sz(s)){
            int cnt = 0;
            while(s[i]!=' ') cnt*=10, cnt+=s[i]-'0', i++;
            i++;
            if(s[i]=='r') cr = cnt, i+=3;
            if(s[i]=='g') cg = cnt, i+=5;
            if(s[i]=='b') cb = cnt, i+=4;
            if(s[i]==';' or i==sz(s)){
                mxr = max(cr, mxr);
                mxg = max(cg, mxg);
                mxb = max(cb, mxb);
                cr = 0, cg = 0, cb = 0;
            }
        }
        // cout << cr << ln;
        mxr = max(cr, mxr);
        mxg = max(cg, mxg);
        mxb = max(cb, mxb);
        sum+=mxr*mxg*mxb;
    }
    cout << sum << ln;
    return 0;
}