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

map<char, int> val;
vector<char> temp;

bool valComp(char c1, char c2){
    return val[c1]>val[c2];
}

bool cntComp(char c1, char c2){
    if(count(all(temp), c1)==count(all(temp), c2)) return valComp(c1, c2);
    return count(all(temp), c1)>count(all(temp), c2);
}

struct hand{
    /*
    5
    4 1
    3 2
    3 1 1
    2 2 1
    2 1 1 1
    1 1 1 1 1
    
    */
    
    string cards;
    int rank = -1;
    vector<char> top;
    int val;
    hand(string h, int v){
        cards = h;
        val = v;
        vector<char> handChars;
        set<char> handSet;
        for(int i = 0; i < 5; i++){
            handChars.pb(h[i]);
            handSet.insert(h[i]);
        }
        vint cnt;
        int jokers = count(all(cards), 'J');
        for(char elem : handSet){
            if(elem!='J') cnt.pb(-count(all(handChars), elem));
            top.pb(elem);
        }
        sort(all(cnt));
        if(sz(cnt)==0) cnt.pb(0);
        cnt[0]-=jokers;
        if(cnt[0]==-5) rank = 6;
        else if(cnt[0]==-4) rank = 5;
        else if(cnt[0]==-3 and cnt[1]==-2) rank = 4;
        else if(cnt[0]==-3 and cnt[1]==-1) rank = 3;
        else if(cnt[0]==-2 and cnt[1]==-2) rank = 2;
        else if(cnt[0]==-2 and cnt[1]==-1) rank = 1;
        else if(cnt[0]==-1) rank = 0;
        temp = handChars;
        sort(all(top), cntComp);

        // reverse(all(top));
    }

    string toString(){
        return cards;
    }
};



bool handComp(hand h1, hand h2){
    if(h1.rank>h2.rank) return true;
    if(h1.rank<h2.rank) return false;
    for(int i = 0; i < sz(h1.cards); i++){
        if(h1.cards[i]==h2.cards[i]) continue;
        return valComp(h1.cards[i], h2.cards[i]);
    }
    // cout << 'a' << ln;
    return true;
}

void solve()
{
    for(int i = 2; i <= 9; i++){
        val.insert({i+'0', i});
    }
    val.insert({'T', 10});
    val.insert({'J', 1});
    val.insert({'Q', 12});
    val.insert({'K', 13});
    val.insert({'A', 14});
    string s; cin >> s;
    vector<hand> hands;
    while(s!="."){
        int v; cin >> v;
        hands.pb(hand(s, v));
        cin >> s;
    }
    sort(all(hands), handComp);
    ll out = 0;
    for(int i = 0; i < sz(hands); i++) cout << hands[i].cards << ' ';
    cout << ln;
    for(int i = 0; i < sz(hands); i++) out+=(sz(hands)-i)*hands[i].val;
    cout << out << ln;
    hand t = hand("JJJJJ", 1);
    cout << t.rank << ln;
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