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

bool isDig(string s){
    for(int i = 0; i < sz(s); i++){
        if(not isdigit(s[i])) return false;
    }
    return true;
}

ll toLong(string s){
    ll out = 0;
    for(int i = 0; i < sz(s); i++){
        out*=10;
        out+=s[i]-'0';
    }
    return out;
}

void solve()
{
    
    vlong seeds;
    vlong lens;
    vector<vvlong> maps;
    
    string s; cin >> s; cin >> s;
    while(isDig(s)){
        ll a = toLong(s);
        cin >> s;
        ll b = toLong(s);
        cin >> s;
        seeds.pb(a);
        lens.pb(b);
    }

    cin >> s;
    cin >> s;
    for(int i = 0; i < 7; i++){
        maps.pb(vvlong());
        int num = 0;
        bool b = false;
        while(s!="." and isDig(s)){
            maps[i].pb(vlong());
            maps[i][num].pb(toLong(s));
            cin >> s;
            maps[i][num].pb(toLong(s));
            cin >> s;
            maps[i][num].pb(toLong(s));
            cin >> s;
            num++;
        }
        if(s!="."){
            cin >> s;
            cin >> s;
        }
    }
    ll sum = 0;
    for(int i = 0; i < sz(lens); i++){
        sum+=lens[i];
    }
    for(int i = 0; i < sz(maps); i++){
        vlong newSeeds;
        vlong newLens;
        copy(all(seeds), back_inserter(newSeeds));
        copy(all(lens), back_inserter(newLens));
        vlong addS;
        vlong addL;
        for(vlong currmap : maps[i]){
            ll leftMap = currmap[1];
            ll rightMap = currmap[1]+currmap[2]-1;
            
            for(int j = 0; j < sz(newSeeds); j++){
                ll leftSeed = newSeeds[j];
                ll rightSeed = newSeeds[j]+newLens[j]-1;
                if(leftSeed<=rightMap and rightSeed>=leftMap){
                    if(leftSeed>=leftMap){
                        if(rightSeed<=rightMap){
                            addS.pb(currmap[0]+leftSeed-leftMap);
                            addL.pb(newLens[j]);
                            newLens[j] = 0;
                        }
                        else{
                            addS.pb(currmap[0]+leftSeed-leftMap);
                            addL.pb(rightMap-leftSeed+1);
                            newSeeds.pb(rightMap+1);
                            newLens.pb(rightSeed-rightMap);
                            newLens[j] = 0;
                        }
                    }
                    else{
                        if(rightSeed<=rightMap){
                            addS.pb(currmap[0]);
                            addL.pb(rightSeed-leftMap+1);
                            newLens[j] = leftMap-leftSeed;
                        }
                        else{
                            addS.pb(currmap[0]);
                            addL.pb(rightMap-leftMap+1);
                            newSeeds.pb(rightMap+1);
                            newLens.pb(rightSeed-rightMap);
                            newLens[j] = leftMap-leftSeed;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < sz(addS); i++){
            newSeeds.pb(addS[i]);
            newLens.pb(addL[i]);
        }
        seeds = vlong();
        lens = vlong();
        for(int j = 0; j < sz(newSeeds); j++){
            if(newLens[j]!=0){
                seeds.pb(newSeeds[j]);
                lens.pb(newLens[j]);
            }
        }
        for(int j = 0; j < sz(seeds); j++) cout << seeds[j] << ' ';
        cout << ln;
        for(int j = 0; j < sz(lens); j++) cout << lens[j] << ' ';
        cout << ln;
    }
    for(int i = 0; i < sz(lens); i++){
        sum-=lens[i];
    }
    cout << *min_element(all(seeds)) << ' ' << sum << ln;
    
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