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
#include <cstring>
 
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
    ll count;
    Node(){
        for(int i = 0; i < 26; i++) connect[i] = NULL;
        count = 0;
    }

    void insert(string &word){
        Node* curr = this;
        for(int i = 0; i < sz(word); i++){
            curr->count++;
            if(curr->connect[tolower(word[i])-'a']==NULL){
                curr->connect[tolower(word[i])-'a'] = new Node();
            }
            curr = curr->connect[tolower(word[i])-'a'];
        }
        curr->count++;
    }
};

ll solve()
{
    int n;
    cin >> n;
    Node *root = new Node();
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        root->insert(s);
    }
    ll out = 0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        
        for(int i = 0; i < 26; i++){
            if(curr->connect[i]!=NULL){
                q.push(curr->connect[i]);
                out+=(curr->connect[i]->count*(curr->connect[i]->count-1))/2;
            }
        }
    }
    return out;
}
void solve_print()
{
    cout << solve() << endl;
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
        solve_print();
    }
    return 0;
}