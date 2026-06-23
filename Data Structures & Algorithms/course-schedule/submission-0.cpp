class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // apply toposort and if yes then just return true else false
        vector<vector<int>> adj(numCourses);
        for (auto& e : prerequisites) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        // indegree
        int n = numCourses;
        queue<int> q;
        vector<int> indeg(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto& it : adj[i]) {
                indeg[it]++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (auto& it : adj[node]) {
                indeg[it]--;
                if (indeg[it] == 0) {
                    q.push(it);
                }
            }
        }
        return count == n;
    }
};
