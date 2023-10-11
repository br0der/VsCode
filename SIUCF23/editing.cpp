#include <bits/stdc++.h>
using namespace std;

// Binary Index Tree for the Euler Tour
struct BIT {
    vector<int> bit;
    int n;
    BIT(int n): n(n), bit(n) {}
    void update(int idx, int dif) {
        for(; idx < n; idx |= idx + 1)
            bit[idx] += dif;
    }
    int query(int idx) {
        int sum = 0;
        for(; idx >= 0; idx &= (idx+1), idx--)
            sum += bit[idx];
        return sum;
    }
    int query(int l, int r) {
        return query(r) - query(l-1);
    }
};

int numNodes;
const int alphabetSize = 26;

// Building the Trie to get the Tree
struct TrieNode {
    int id;
    vector<TrieNode*> children;
    bool isWord = false;
    TrieNode(): id(numNodes++), children(alphabetSize) {}
    int insert(string &s, int i = 0) {
        if(i == (int) s.size()) {
            isWord = true;
            return id;
        }

        int idx = s[i] - 'a';
        if(children[idx] == nullptr)
            children[idx] = new TrieNode();

        return children[idx]->insert(s, i+1);
    }
};

const int maxId = 1e5;

// Getting the adjacency matrix from the trie
void buildAdjacency(vector<vector<int>> &adj, TrieNode *cur) {
    for(int idx = 0; idx < alphabetSize; idx++) {
        if(cur->children[idx] == nullptr) continue;
        adj[cur->id].push_back(cur->children[idx]->id);
        buildAdjacency(adj, cur->children[idx]);      
    }
}

void solve() {
    numNodes = 0;
    int q; cin >> q;
    vector<pair<int, int>> queries;
    vector<int> trieIds(maxId + 1, -1);
    TrieNode trie; 

    // Scan in input and store relevant info
    for(int i = 0; i < q; i++) {
        char type; cin >> type;
        if(type == 'E') {
            int id1, id2; cin >> id1 >> id2;
            queries.emplace_back(id1, id2);
        }
        else {
            int id; cin >> id;
            string s; cin >> s;
            int endId = trie.insert(s);
            queries.emplace_back(-1, id);
            trieIds[id] = endId;
        }
    }

    //Pre/Post order for euler tour
    vector<int> pre(numNodes), post(numNodes);

    // Get the adjacency list
    // Note: root is at 0
    vector<vector<int>> adj(numNodes);
    buildAdjacency(adj, &trie);

    // Get the binary lifting info
    vector<int> par(numNodes), depth(numNodes);
    
    // get the parent and depth arrays using a dfs
    // Also going to get the pre-order and post-order for the euler tour
    int counter = 0;
    auto init = [&](int cur, auto &init) -> void {
        pre[cur] = counter++;
        for(int nxt: adj[cur]) {
            depth[nxt] = depth[cur] + 1;
            par[nxt] = cur;
            init(nxt, init);
        }
        post[cur] = counter++;
    };

    par[0] = -1;
    init(0, init);

    // Build the jump table
    vector<vector<int>> jump(1, par);
    for(int i = 0; i < __lg(numNodes); i++) {
        vector<int> cur(numNodes, -1);
        for(int j = 0; j < numNodes; j++) {
            if(jump[i][j] != -1)
                cur[j] = jump[i][jump[i][j]];
        }
        jump.push_back(cur);
    }

    // Finds the LCA between nodes u and v using binary lifting
    auto findLCA = [&](int u, int v) -> int {
        if(depth[u] > depth[v]) swap(u, v);
        for(int i = __lg(numNodes); i >= 0; i--) {
            if(jump[i][v] != -1 && depth[jump[i][v]] >= depth[u])
                v = jump[i][v];
        }
        if(u == v) return u;

        for(int i = __lg(numNodes); i >= 0; i--) {
            if(jump[i][u] != jump[i][v])
                u = jump[i][u], v = jump[i][v];
        }

        return jump[0][u];
    };

    // Make the bit to store euler tour
    BIT eulerTour(2*numNodes);
    
    // Stores whether the node is on or off
    vector<int> nodeOn(numNodes);

    // Process queries
    for(auto [id1, id2]: queries) {
        // Process teach query
        if(id1 == -1) {
            int trieId = trieIds[id2];
            eulerTour.update(pre[trieId], 1);
            eulerTour.update(post[trieId], -1);
            nodeOn[trieId] = 1;
        }
        // Process edit query
        else {
            int trieId1 = trieIds[id1];
            int trieId2 = trieIds[id2];
            int lca = findLCA(trieId1, trieId2);
            int path1 = eulerTour.query(pre[lca], pre[trieId1]);
            int path2 = eulerTour.query(pre[lca], pre[trieId2]);
            cout << path1 + path2 - nodeOn[lca] << '\n';
        }
    }
}

int main() {
    int t; cin >> t;
    while(t--) solve();    
    return 0;
}