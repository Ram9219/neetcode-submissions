class Solution {
   public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> ans;
    void dfs(string src) {
        while (!adj[src].empty()) {
            string next = adj[src].top();
            adj[src].pop();
            dfs(next);
        }
        ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& e : tickets) {
            adj[e[0]].push(e[1]);
        }
        dfs("JFK");
        reverse(begin(ans), end(ans));
        return ans;
    }
};
