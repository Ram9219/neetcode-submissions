class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        /// simple dijikstra hai bs u,vwt ki jagah src ,target,aur time diya hai
        // k is src
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& e : times) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();
            if (dis > dist[node]) continue;
            for (auto& it : adj[node]) {
                auto adjnode = it.first;
                auto wt = it.second;
                if (dis + wt < dist[adjnode]) {
                    dist[adjnode] = dis + wt;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) {
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
