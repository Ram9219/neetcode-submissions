class Disjoint {
   public:
    vector<int> rank, parent;
    Disjoint(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int ult_parent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = ult_parent(parent[node]);
    }
    void find_Rank_By_Union(int u, int v) {
        int pu = ult_parent(u);
        int pv = ult_parent(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        Disjoint ds(n);
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (auto& e : edges) {
                int u = e[0];
                int v = e[1];
                ds.find_Rank_By_Union(u, v);
            }
        }
        for (int i = 0; i < n; i++) {
            if (ds.ult_parent(i) == i) {
                count++;
            }
        }
        return count;
    }
};
