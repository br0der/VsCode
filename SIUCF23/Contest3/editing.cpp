#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvlong;
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
int costMat[NODE][NODE] = {
   {0, 3, 6, INF, INF, INF, INF},
   {3, 0, 2, 1, INF, INF, INF},
   {6, 2, 0, 1, 4, 2, INF},
   {INF, 1, 1, 0, 2, INF, 4},
   {INF, INF, 4, 2, 0, 2, 1},
   {INF, INF, 2, INF, 2, 0, 1},
   {INF, INF, INF, 4, 1, 1, 0}
};

vvint kthparent;
vint depth;
vint keyToPre, preToPost;

struct Node{
    Node* connect[26];
    int rank = 0;
    int pre = -1, post = -1;
    int k = -1;
    Node(Node* p){
        if(p!=nullptr) rank = p->rank+1;
        for(int i = 0; i < 26; i++) connect[i] = nullptr;
    }

    void insert(string &word, int key){
        Node* curr = this;
        for(int i = 0; i < sz(word); i++){
            // cout << word[i] << endl;
            if(curr->connect[word[i]-'a']==nullptr){
                curr->connect[word[i]-'a'] = new Node(curr);
            }
            curr = curr->connect[word[i]-'a'];
        }
        curr->k = key;
    }
    void flatten(){
        Node* curr = this;
        curr->pre = 0;
        stack<Node*> s;
        stack<int> nxtChr;
        s.push(curr);
        nxtChr.push(0);
        int nxtIdx = 1;
        while(!s.empty()){
            while(nxtChr.top()<26 and s.top()->connect[nxtChr.top()]==nullptr) nxtChr.top()++;
            if(nxtChr.top()>=26){
                s.top()->post = nxtIdx;
                nxtIdx++;
                nxtChr.pop();
                s.pop();
                continue;
            }
            s.push(s.top()->connect[nxtChr.top()]);
            s.top()->pre = nxtIdx;
            nxtIdx++;
            nxtChr.top()++;
            nxtChr.push(0);
        }
    }

    void setup(){
        queue<Node*> q;
        q.push(this);
        while(!q.empty()){
            
            depth[q.front()->pre] = q.front()->rank;
            if(q.front()->k!=-1) keyToPre[q.front()->k] = q.front()->pre;
            preToPost[q.front()->pre] = q.front()->post;
            int i = 1;
            while(i<18 and kthparent[q.front()->pre][i-1]!=-1 and kthparent[kthparent[q.front()->pre][i-1]][i-1]!=-1){
                kthparent[q.front()->pre][i] = kthparent[kthparent[q.front()->pre][i-1]][i-1];
                i++;
            }

            for(int i = 0; i < 26; i++){
                if(q.front()->connect[i]==nullptr) continue;
                kthparent[q.front()->connect[i]->pre][0] = q.front()->pre;
                q.push(q.front()->connect[i]);
            }
            q.pop();
        }
    }
};

struct segTreeNode{
    int lo, md, hi;
	int sum = 0;
	segTreeNode *left, *right;
	
	// Constructor
	segTreeNode(int L, int R) {
		lo = L, hi = R;
		md = (lo + hi) / 2;
		if(lo == hi) return;
		left = new segTreeNode(L, md);
		right = new segTreeNode(md+1, R);
	}
	
	// Merge function: updates current node's sum
	// Mainly helpful for segTrees with intrecate merging
	void merge() {
		sum = left->sum + right->sum;
	}
	
	// Point update
	void update(int idx, int val) {
		if(lo == hi) {
			sum += val;
			return;
		}

		if(idx <= md) left->update(idx, val);
		else right->update(idx, val);

		merge();

		return;
	}

	// Range Query
	int query(int L, int R) {
		// Full Cover
		if(L <= lo && R >= hi) return sum;
		
		// No cover
		if(L > hi || R < lo) return 0;

		// Partial cover
		return left->query(L, R) + right->query(L, R);
	}
};

int getLca(int n1, int n2){
    if(depth[n2]>depth[n1]) swap(n1, n2);
    if(depth[n1]>depth[n2]){
        int diff = depth[n1]-depth[n2];
        for(int i = 0; i < 18; i++){
            // cout << n1 << ' ' << n2 << ln;
            if(diff&(1<<i)){
                // cout << n1 << ' ' << i << endl;
                n1 = kthparent[n1][i];
            }
        }
    }
    if(n1==n2) return n1;
    // cout << n1 << ' ' << n2 << ln;
    for(int i = 17; i >= 0; i--){
        if(kthparent[n1][i]==-1) continue;
        if(kthparent[n1][i]!=kthparent[n2][i]){
            n1 = kthparent[n1][i];
            n2 = kthparent[n2][i];
        }
    }
    n1 = kthparent[n1][0];
    return n1;
}

void solve()
{
    int q;
    cin >> q;
    vector<vector<string>> queries;
    Node *root = new Node(nullptr);
    int words = 0;
    for(int i = 0; i < q; i++){
        string type;
        cin >> type;
        string id;
        cin >> id;
        string other;
        cin >> other;
        // cout << "man1" << endl;
        if(type == "T"){
            // other = "";
            // for(int j = 0; j < 5e4; j++){
            //     other+='a'+i;
            // }
            // id = to_string(i+1);
            root->insert(other, stoi(id));
            words++;
        }
        // cout << "man2" << endl;
        vector<string> t = {type, id, other};
        queries.push_back(t);
    }
    // cout << 'a' << endl;
    root->flatten();
    depth = vint(root->post+1, -1);
    kthparent = vvint(root->post+1, vint(20, -1));
    keyToPre = vint(100001, -1);
    preToPost = vint(root->post+1, -1);
    // cout << 'b' << endl;
    root->setup();
    
    // cout << endl;
    segTreeNode *stRoot = new segTreeNode(0, root->post);
    // cout << root->pre << ' ' << root->post << endl;
    for(int i = 0; i < q; i++){
        // cout << i << endl;
        vector<string> query = queries[i];
        if(query[0] == "T"){
            int node = keyToPre[stoi(query[1])];
            stRoot->update(node, 1);
            stRoot->update(preToPost[node], -1);
        }
        else if(query[0] == "E"){
            int n1 = keyToPre[stoi(query[1])];
            int n2 = keyToPre[stoi(query[2])];
            // cout << n1 << ' ' << n2 << endl; 
            int l = getLca(n1, n2);
            // cout << l << endl;
            cout << stRoot->query(0, n1) + stRoot->query(0, n2) - stRoot->query(0, l) - (kthparent[l][0]==-1 ? 0 : stRoot->query(0, kthparent[l][0])) << endl;
            // cout << endl;
        }
        else{
            while(true) continue;
        }
    }
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    // cout << 'd' << endl;
    return 0;
}