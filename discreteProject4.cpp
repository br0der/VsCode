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
    int depth = 0;
    BST* left;
    BST* right;
    BST* par = nullptr;
    BST(){
        key = -1;
        val = "";
        depth = 0;
        left = nullptr;
        right = nullptr;
    }
    BST(int k, BST* p){
        key = k;
        val = "";
        left = new BST();
        right = new BST();
        par = p;
    }
    BST(int k, string v){
        key = k;
        val = v;
        left = nullptr;
        right = nullptr;
    }

    bool isLeaf(){
        return key==-1;
    }

    void insert(int k){
        if(key==-1){
            key = k;
            val = "";
            left = new BST();
            right = new BST();
            depth = 1;
            return;
        }
        if(key==k) return;
        BST* nxt = key>k ? left : right;
        cout << (key>k ? "left" : "right") << ln;
        nxt->insert(k);
        nxt->par = this;
        depth = max(left->depth, right->depth)+1;
    }

    BST* find(int k, bool print){
        if(key==-1 or key==k) return this;
        BST* nxt = key>k ? left : right;
        if(print) cout << (key>k ? "left" : "right") << ln;
        return nxt->find(k, print);
    }

    BST* findNxt(int k, bool print){
        BST* f = find(k, false);
        if(not f->right->isLeaf()){
            f = f->right;
            if(print) cout << "right" << ln;
            while(not f->left->isLeaf()){
                f = f->left;
                if(print) cout << "left" << ln;
            }
            return f;
        }
        else{
            while(f->par!=nullptr){
                if(f==f->par->left){
                    if(print) cout << "up right" << ln;
                    return f->par;
                }
                if(print) cout << "up left" << ln;
                f = f->par;
            }
            return new BST();
        }
    }

    void del(int k){
        BST* f = find(k, false);
        BST* nxt = findNxt(k, false);
        if(f->right->isLeaf()){ // nxt is higher than f, and f has no right pointer
            if(f->par->left==f){
                f->par->left = f->left;
            }
            else{
                f->par->right = f->left;
            }
        }
        else{ // nxt is lower than f, and does not have a left pointer
            f->key = nxt->key;
            f->val = nxt->val;
            if(nxt->par->left==nxt){
                nxt->par->left = nxt->right;
            }
            else{
                nxt->par->right = nxt->right;
            }
        }
    }

    void print(){

    }
};

void bstTester(){
    BST* b = new BST();
    string type; cin >> type;
    while(type!="quit"){
        if(type=="insert"){
            int n; cin >> n;
            b->insert(n);
        }
        if(type=="find"){
            int n; cin >> n;
            b->find(n, true);
        }
        if(type=="delete"){
            int n; cin >> n;
            b->del(n);
        }
        if(type=="next"){
            int n; cin >> n;
            b->findNxt(n, true);
        }
        cin >> type;
    }
}

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