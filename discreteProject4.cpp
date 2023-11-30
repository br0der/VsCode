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



struct Number{
    int key;
    string val;
    Number* nxt;
    Number* down;
    Number(int k){
        key = k;
        val = "";
        nxt = nullptr;
        down = nullptr;
    }
    Number(int k, Number* n){
        key = k;
        val = "";
        nxt = n;
        down = nullptr;
    }
    Number(int k, string v, Number* n){
        key = k;
        val = v;
        nxt = n;
        down = nullptr;
    }
};

Number* skipList;
ll depth;

void insert(int num){
    ll run = randRun();
    for(int i = 0; i <= run-depth; i++){
        Number* temp = new Number(0);
        temp->down = skipList;
        skipList = temp;
    }
    depth = max((ll)depth, run+1);

    ll currDepth = 0;
    Number* finder = skipList;
    Number* above = new Number(num);
    while (finder!=nullptr) {
        while(finder->nxt!=nullptr and finder->nxt->key<=num){
            finder = finder->nxt;
            // cout << "going right" << ln;
        }
        if(currDepth >= depth-run-1){
            // cout << "inserting!" << ln;
            if(finder->key==num){
                above->down = finder;
                break;
            }
            finder->nxt = new Number(num, finder->nxt);
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
}

int find(int num){
    Number* finder = skipList;
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
    Number* finder = skipList;
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
    Number* curr = skipList;
    int mx = 0;
    while(curr!=nullptr){
        Number* temp = curr;
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

int main()
{
    srand(time(NULL));
    // #ifndef ONLINE_JUDGE
    //     freopen("data/input.txt","r", stdin);
    //     freopen("data/output.txt","w", stdout);
    // #endif
    skipList = new Number(0);
    depth = 1;
    string type; cin >> type;
    while(type!="quit"){
        if(type=="insert"){
            int num; cin >> num;
            insert(num);
        }
        if(type=="find"){
            int num; cin >> num;
            cout << find(num) << ln;
        }
        if(type=="delete"){
            int num; cin >> num;
            del(num);
        }
        if(type=="print"){
            prnt();
        }
        cin >> type;
    }
    // insert(2, 2);
    // prnt();
    // insert(2,3);
    // prnt();
    // cout << depth << ln;
    // insert(3, 1);
    // prnt();
    // cout << depth << ln;
    return 0;
}