class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);
        for(auto &e:edges){
            int u=e[1];
            int v=e[0];
            adj[u].push_back(v);
        }
        vector<int>indeg(n,0),ans;
        queue<int>q;
        for(int i=0;i < n; i++){
            for(auto &it: adj[i]){
                indeg[it]++;
            }
        }
        for(int i=0;i< n; i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto &it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()!=n){
            return {};
        }
        return ans;
    }
};
