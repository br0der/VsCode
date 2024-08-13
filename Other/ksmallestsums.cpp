//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <iostream>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<double> vdouble;
typedef vector<vector<int> > vvint;
typedef vector<vector<ll> > vvlong;
typedef vector<vector<double> > vvdouble;
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
string ln = "\n";


void solve()
{
    int k;
    while (cin >> k) {
        vvint lis;
        for(int i = 0; i < k; i++){
            lis.pb(vint(k));
            for(int j = 0; j < k; j++){
                cin >> lis[i][j];
            }
            sort(all(lis[i]));
        }
        vint nums = lis[0];
        for(int i = 1; i < k; i++){
            vint nxt;

            priority_queue<pair<int, pair<int, int> > > pq;
            pq.push(make_pair(-nums[0]-lis[i][0], make_pair(0, 0)));
            set<pair<int,int> > visited;
            visited.insert(make_pair(0, 0));
            while (sz(pq)) {
                pair<int, pair<int, int> > curr = pq.top();
                
                pq.pop();
                nxt.pb(abs(curr.first));
                if (sz(nxt) == k) break;
                
                for (int j = 0; j < 2; j++) {
                    int newx = curr.second.first + 1-j;
                    int newy = curr.second.second + j;
                    if (!visited.count(make_pair(newx, newy))) {
                        pq.push(make_pair(-nums[newx]-lis[i][newy], make_pair(newx, newy)));
                        visited.insert(make_pair(newx, newy));
                    }
                }
            }
            for(int i = 0; i < k; i++){
                nums[i] = nxt[i];
            }
        }
        for(int i = 0; i < k; i++){
            cout << nums[i];
            if (i!=k-1) assert(nums[i] <= nums[i+1]), cout << ' ';
        }
        cout << ln;
    }
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