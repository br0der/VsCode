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
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";



ll randRun(){
    ll c = 0;
    while(rand()%2==1){
        c++;
    }
    return c;
}

struct BST{
    int key;
    string val;
    BST* left;
    BST* right;
    BST* par = nullptr;
    BST(int k, BST* p){
        key = k;
        val = "";
        left = nullptr;
        right = nullptr;
        par = p;
    }
    BST(int k, string v){
        key = k;
        val = v;
        left = nullptr;
        right = nullptr;
    }

    void insert(int k){
        if(this->key==-1){
            this->key = k;
            this->val = "";
            return;
        }
        BST* last = this;
        BST* iter = this;
        while(iter!=nullptr){
            if(k<iter->key) iter = iter->left;
            else if(k>iter->key) iter = iter->right;
            else break;
        }
        if(last->key==k) return;
        (last->key>k) ? last->left : last->right = new BST(k, last);
    }

    BST* find(int k){
        BST* iter = this;
        while(iter!=nullptr){
            if(k<iter->key) iter = iter->left;
            else if(k>iter->key) iter = iter->right;
            else break;
        }
        if(iter->key==k) return iter;
        return nullptr;
    }

    void del(int k){

    }
};

struct SkipList{
    int key;
    string val;
    int depth = 1;
    SkipList* nxt;
    SkipList* down;
    SkipList(int k){
        key = k;
        val = "";
        nxt = nullptr;
        down = nullptr;
    }
    SkipList(int k, SkipList* n){
        key = k;
        val = "";
        nxt = n;
        down = nullptr;
    }
    SkipList(int k, string v, SkipList* n){
        key = k;
        val = v;
        nxt = n;
        down = nullptr;
    }

    SkipList* insert(int num){
        ll run = randRun();
        SkipList* out = this;
        for(int i = 0; i <= run-(this->depth); i++){
            SkipList* temp = new SkipList(0);
            temp->down = out;
            temp->nxt = nullptr;
            temp->depth = out->depth+1;
            out = temp;
        }
        ll currDepth = 0;
        SkipList* finder = out;
        SkipList* above = new SkipList(num);
        while (finder!=nullptr) {
            while(finder->nxt!=nullptr and finder->nxt->key<=num){
                finder = finder->nxt;
                // cout << "going right" << ln;
            }
            if(currDepth >= (out->depth)-run-1){
                // cout << "inserting!" << ln;
                if(finder->key==num){
                    above->down = finder;
                    break;
                }
                finder->nxt = new SkipList(num, finder->nxt);
                finder->nxt->depth = finder->depth;
                above->down = finder->nxt;
                above = above->down;
            }
            else{
                // cout << "not yet" << ln;
            }
            if(finder->down == nullptr) break;
            finder = finder->down;
            currDepth++;
        }
        return out;
    }

    int find(int num){
        SkipList* finder = this;
        while (finder!=nullptr) {
            while(finder->nxt!=nullptr and finder->nxt->key<=num){
                finder = finder->nxt;
                cout << "right" << ln;
            }
            if(finder->key==num) return finder->key;
            if(finder->down == nullptr) break;
            finder = finder->down;
            cout << "down" << ln;
        }
        return -1;
    }

    void del(int num){
        SkipList* finder = this;
        while (finder!=nullptr) {
            while(finder->nxt!=nullptr and finder->nxt->key<num){
                finder = finder->nxt;
            }
            if(finder->nxt!=nullptr and finder->nxt->key==num) 
            finder->nxt = finder->nxt->nxt;
            if(finder->down == nullptr) break;
            finder = finder->down;
        }
    }

    void prnt(){
        SkipList* curr = this;
        int mx = 0;
        while(curr!=nullptr){
            SkipList* temp = curr;
            int last = 0;
            cout << ".";
            while(temp->nxt!=nullptr){
                temp = temp->nxt;
                for(int i = last+1; i <= temp->key-1; i++){
                    cout << " ";
                }
                last = temp->key;
                cout << temp->key/10;
                mx = max(mx, temp->key);
            }
            cout << ln;
            curr = curr->down;
        }
        for(int i = 0; i < mx; i++){
            cout << '-';
        }
        cout << ln;
    }
};

void skipListTester(){
    srand(time(NULL));

    SkipList* sl = new SkipList(0);
    string type; cin >> type;
    while(type!="quit"){
        if(type=="insert"){
            int num; cin >> num;
            sl = sl->insert(num);
        }
        if(type=="find"){
            int num; cin >> num;
            cout << sl->find(num) << ln;
        }
        if(type=="delete"){
            int num; cin >> num;
            sl->del(num);
        }
        if(type=="print"){
            sl->prnt();
        }
        cin >> type;
    }
}

void bstTester(){
    BST* b = new BST(-1, nullptr);
    string type; cin >> type;
    while(type!="quit"){
        if(type=="insert"){
            int n; cin >> n;
            b->insert(n);
        }
        if(type=="find"){
            int n; cin >> n;
            cout << b->find(n)->key << ln;
        }
        if(type=="delete"){
            int n; cin >> n;
            b->del(n);
        }
    }
}

int main()
{
    cout << "skiplist or bst?" << ln;
    string s; cin >> s; 
    while(s!="skiplist" and s!="bst"){
        cin >> s;
    }
    if(s=="skiplist") skipListTester();
    else bstTester();
    return 0;
}