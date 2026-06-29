class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e9);
        // bellmon ford technique
        dist[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;
            for (auto& e : flights) {
                int u = e[0];
                int v = e[1];
                int wt = e[2];
                if (dist[u] == 1e9) {
                    continue;
                }
                temp[v] = min(temp[v], dist[u] + wt);
            }
            dist = temp;
        }
        if (dist[dst] == 1e9) {
            return -1;
        }
        return dist[dst];
    }
};
