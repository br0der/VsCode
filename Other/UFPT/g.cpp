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

struct Node{
    Node* connect[26];
    int rank = 0;
    int passed = 0;
    int pre = -1, post = -1;
    int k = -1;
    Node(Node* p){
        if(p!=nullptr) rank = p->rank+1;
        for(int i = 0; i < 26; i++) connect[i] = nullptr;
    }

    void insert(string &word){
        Node* curr = this;
        curr->passed++;
        for(int i = 0; i < sz(word); i++){
            if(curr->connect[word[i]-'a']==nullptr){
                curr->connect[word[i]-'a'] = new Node(curr);
            }
            curr = curr->connect[word[i]-'a'];
            curr->passed++;
        }
    }
    // Other functions go here
    int query(string &word){
        Node* curr = this;
        int out = curr->passed;
        for(int i = 0; i < sz(word); i++){
            if(curr->connect[word[i]-'a']==nullptr){
                curr->connect[word[i]-'a'] = new Node(curr);
            }
            curr = curr->connect[word[i]-'a'];
            out += curr->passed;
        }
        return out;
    }
};

void solve()
{
    int n; cin >> n;
    vector<string> dict(n); for(int _ = 0; _ < n; _++) cin >> dict[_];
    
    int m; cin >> m;
    vint ans(m, -1);
    map<string, set<int>> mp;
    vector<string> queries(m); for(int _ = 0; _ < m; _++) cin >> queries[_], mp[queries[_]].insert(_);
    vector<bool> taken = vector<bool>(m, false);
    queue<int> q;
    Node *trie = new Node(nullptr);
    for(int i = 0; i < n; i++){
        trie->insert(dict[i]);
        if(mp.count(dict[i])){
            for(int qIdx : mp[dict[i]]){
                taken[qIdx] = true;
                ans[qIdx] = trie->query(queries[qIdx]);
            }
        }
    }
    for(int i = 0; i < m; i++){
        if(not taken[i]){
            ans[i] = trie->query(queries[i]);
        }
    }
    for(int i = 0; i < sz(ans); i++) cout << ans[i] << ln;
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}