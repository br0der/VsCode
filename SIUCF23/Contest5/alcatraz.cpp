// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#include <algorithm>

#include <vector>

namespace atcoder {

namespace internal {

template <class T> struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <limits>
#include <queue>
#include <vector>

namespace atcoder {

template <class Cap> struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    mf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    Cap flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        std::vector<int> level(_n), iter(_n);
        internal::simple_queue<int> que;

        auto bfs = [&]() {
            std::fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que.clear();
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d =
                    self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) break;
            }
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            while (flow < flow_limit) {
                Cap f = dfs(dfs, t, flow_limit - flow);
                if (!f) break;
                flow += f;
            }
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        internal::simple_queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

}  // namespace atcoder

using namespace atcoder;
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vpi = vector<pi>;
using vb = vector<bool>;

const ll INF = 1e9;

void solve() {
    ll k, m;
    cin >> k >> m;

    vvc grid(k, vc(m));
    ll n = 1;
    vvi ptr(k, vi(m));
    vector<vb> nxt(k, vb(m));
    vector<array<ll, 3>> ev;

    function<bool(ll, ll)> oob = [&](ll x, ll y) {
        return (x < 0 || x >= k || y < 0 || y >= m);
    };

    for(ll i = 0; i < k; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'P' || grid[i][j] == 'X') {
                ptr[i][j] = n;
                n++;
            }
            if(grid[i][j] == 'T') {
                ptr[i][j] = n;
                ev.push_back({n, n + 1, 1});
                n += 2;
            }
        }
    }

    for (ll i = 0; i < k; i++) {
        for (ll j = 0; j < m; j++) {
            if(grid[i][j] == '#') continue;
            for (ll x = -1; x <= 1; x++) {
                for (ll y = -1; y <= 1; y++) {
                    if(abs(x + y) != 1)
                        continue;
                    if(oob(i + x, j + y))
                        continue;
                    if(grid[i + x][j + y] == 'T') {
                        if(!ptr[i][j]) {
                            ptr[i][j] = n;
                            n++;
                        }
                        nxt[i][j] = true;
                        ev.push_back({(ptr[i][j] + (grid[i][j] == 'T')), ptr[i + x][j + y], 1});
                        ev.push_back({ptr[i + x][j + y] + 1, ptr[i][j], 1});
                    }
                }
            }
        }
    }

    // vvi adj(n);
    // vvi capacity(n, vi(n));

    // for (ll i = 0; i < ev.size(); i++) {
    //     adj[ev[i] - 1].push_back(ev[i]);
    //     capacity[ev[i] - 1][ev[i]] = 1;
    // }

    // cout << "NOWAY" << endl;
    // return;

    

    // cout << "WHS" << endl;
    // return;

    

    // cout << "WHA" << endl;
    // return;

    // for (ll i = 0; i < k; i++) {
    //     for (ll j = 0; j < m; j++) {
    //         ll idx = i * m + j + 1;
    //         for (ll x = -1; x <= 1; x++) {
    //             for (ll y = -1; y <= 1; y++) {
    //                 // cout << "YEYS" << endl;
    //                 // if(idx == 3)
    //                 //     cout << x << " " << y << endl;
    //                 if (abs(x + y) != 1)
    //                     continue;

    //                 // if (idx == 3)
    //                 //     cout << x << " " << y << endl;
    //                 // cout << "YIKES" << endl;
    //                 if (i + x < 0 || i + x >= k || j + y < 0 || j + y >= m)
    //                     continue;

    //                 // if (idx == 3)
    //                 //     cout << x << " " << y << endl;
    //                 // cout << "YEET" << endl;
    //                 if(grid[i][j] == '#' || grid[i + x][j + y] == '#' || grid[i][j] == 'X') {
    //                     continue;
    //                 }
    //                 // cout << i << " " << j << " " << x << " " << y << endl;
    //                 ll idx2 = (i + x) * m + (j + y) + 1;
    //                 // if(idx == 1)
    //                 //     cout << "Y " << (i + x) << " " << (j + y) << endl;
    //                 adj[idx].push_back(idx2);
    //                 if(grid[i][j] == 'T' || grid[i + x][j + y] == 'T') {
    //                     capacity[idx][idx2] = 1;
    //                 } else {
    //                     capacity[idx][idx2] = INF;
    //                 }
    //             }
    //         }

    //         // process people and exits
    //         // cout << "TAKO " << i << " " << j  << endl;
            // if(grid[i][j] == 'P') {
            //     adj[0].push_back(idx);
            //     capacity[0][idx] = 1;
            // } else if(grid[i][j] == 'X') {
            //     adj[idx].push_back(n - 1);
            //     capacity[idx][n - 1] = INF;
            // }
    //         // cout << "EHS" << endl;
    //     }
    // }

    // cout << "HEH" << endl;
    // return;

    vector<vb> vis(k, vb(m));
    vi inp;
    vi out;
    ll comp = 0;
    function<void(ll, ll)> dfs = [&](ll x, ll y) {
        if(oob(x, y))
            return;
        if (vis[x][y])
            return;
        if(grid[x][y] == '#' || grid[x][y] == 'T')
            return;
        vis[x][y] = true;

        if(ptr[x][y]) {
            if (nxt[x][y]) {
                inp.push_back(ptr[x][y] + (grid[x][y] == 'T'));
                out.push_back(ptr[x][y]);
            } else {
                if(grid[x][y] == 'P') inp.push_back(ptr[x][y]);
                if (grid[x][y] == 'X') out.push_back(ptr[x][y]);
            }
        }

    //     ll truecur = cur + (grid[curi][curj] == 'T');
    //     ll trueptr = ptr[x][y] + (grid[x][y] == 'T');
    //     if((grid[x][y] == 'T' || grid[x][y] == 'X') && !(x == curi && y == curj)) {
    //         adj[truecur].push_back(trueptr);
    //         // adj[ptr[x][y]]
    //         // if (grid[curi][curj] == 'T' || grid[x][y] == 'T') {
    //         //     capacity[cur][ptr[x][y]] = 1;
    //         // } else {
    //             capacity[truecur][trueptr] = INF;
    //         // }
    //     }

    //     if((grid[curi][curj] == 'T' || grid[curi][curj] == 'X') && !(x == curi && y == curj)) {
    //         adj[trueptr].push_back(truecur);
    //         // adj[ptr[x][y]]
    //         // if (grid[curi][curj] == 'T' || grid[x][y] == 'T') {
    //         //     capacity[cur][ptr[x][y]] = 1;
    //         // } else {
    //         capacity[trueptr][truecur] = INF;
    //         // }
    //     } 

    //     if (grid[x][y] == 'T' && !(x == curi && y == curj)) {
    //         // cout << x << " " << y << " " << curi << " " << curj << endl;
    //         return;
    //     }

        for(ll i = -1; i <= 1; i++) {
            for(ll j = -1; j <= 1; j++) {
                if(abs(i + j) != 1)
                    continue;
                dfs(x + i, j + y);
            }
        }
    };

    for(ll i = 0; i < k; i++) {
        for(ll j = 0; j < m; j++) {
            if (vis[i][j] || grid[i][j] == '#' || grid[i][j] == 'T')
                continue;
            dfs(i, j);
            if(inp.size() == 0 && out.size() == 0) {
                continue;
            }
            for (ll q = 0; q < inp.size(); q++) {
                ev.push_back({inp[q], n, INF});
            }
            for (ll q = 0; q < out.size(); q++) {
                ev.push_back({n, out[q], INF});
            }
            inp.clear();
            out.clear();
            comp++;
            n++;
        }
    }
    n++;

    // cout << "FRIED " << comp << endl;

    // cout << "YIKES" << endl;
    // return;

    for(ll i = 0; i < k; i++) {
        for(ll j = 0; j < m; j++) {
            if(grid[i][j] == 'P') {
                ev.push_back({0, ptr[i][j], 1});
            }
            if(grid[i][j] == 'X') {
                ev.push_back({ptr[i][j], n - 1, INF});
            }
        }
   }

//    cout << "YIKERS" << endl;
//    return;

    vector<vector<ll>> adj(n);
    vector<vector<ll>> capacity(n, vector<ll>(n));

    // cout << "HEHE" << endl;
    // return;

    mf_graph<ll> gr(n);
    for(array<ll, 3> ed : ev) {
        gr.add_edge(ed[0], ed[1], ed[2]);
    }


    // cout << "HEH" << endl;
    // return;

    cout << gr.flow(0, n - 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../data/alcatraz_large.in","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif
    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}

