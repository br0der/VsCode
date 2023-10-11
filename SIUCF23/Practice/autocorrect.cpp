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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
struct Node{
    Node* connect[26];
    Node* jump = NULL;
    Node* parent = NULL;
    ll dist = -1;
    Node(Node* j, Node* p){
        for(int i = 0; i < 26; i++) connect[i] = NULL;
        jump = j;
        parent = p;
    }

    void insert(string &word){
        Node* curr = this;
        for(int i = 0; i < sz(word); i++){
            if(curr->connect[word[i]-'a']==NULL){
                curr->connect[word[i]-'a'] = new Node(NULL, curr);
            }
            curr = curr->connect[word[i]-'a'];
        }
        Node* dest = curr;
        for(int i = 0; i < sz(word); i++){
            if(curr->jump==NULL and curr->parent!=NULL) curr->jump = dest;
            else break;
            curr = curr->parent;
        }
    }
};



void solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    Node* root = new Node(NULL, NULL);
    root->dist = 0;
    for(int i = 0; i < n; i++){
        string w;
        cin >> w;
        root->insert(w);
    }
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));
    
    while(!q.empty()){
        // cout << "hello" << endl;

        pair<Node*, ll> curr = q.front();
        q.pop();
        if(curr.first==NULL) break;
        if(curr.first->parent!=NULL and curr.first->parent->dist==-1){
            q.push(make_pair(curr.first->parent, curr.second+1));
            q.back().first->dist = curr.second + 1;
        }
        if(curr.first->jump!=NULL and curr.first->jump->dist==-1){
            q.push(make_pair(curr.first->jump, curr.second+1));
            q.back().first->dist = curr.second + 1;
        }
        for(int i = 0; i < 26; i++){
            if(curr.first->connect[i]!=NULL and curr.first->connect[i]->dist==-1){
                q.push(make_pair(curr.first->connect[i], curr.second+1));
                q.back().first->dist = curr.second + 1;
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        string target;
        cin >> target;
        Node* curr = root;
        int s = sz(target);
        int j = 0;
        if(curr==NULL){
            cout << s << endl;
            break;
        }
        while(j<s and curr->connect[target[j]-'a']!=NULL){
            curr = curr->connect[target[j]-'a'];
            // cout << curr->dist << endl;
            j++;
        }
        cout << curr->dist + s - j << endl;
    }
}
int main()
{
    fast_cin();
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    solve();
    return 0;
}