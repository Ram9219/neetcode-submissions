class Solution {
   private:
vector<int> topo(int n, vector<vector<int>>& adj) {

        vector<int> indeg(n, 0), ans;

        queue<int> q;

        // indegree count
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

        while (!q.empty()) {

            int node = q.front();

            q.pop();

            ans.push_back(node);

            for (auto& it : adj[node]) {

                indeg[it]--;

                if (indeg[it] == 0) {

                    q.push(it);
                }
            }
        }

        return ans;
    }


   public:
    string foreignDictionary(vector<string>& words) {
        int n=words.size();
        vector<vector<int>>adj(26);
        vector<int>indeg(n,0),present(26,0);
        for(auto&word:words){
         for(auto&ch:word){
            present[ch-'a']=1;
         }
        }
        //now we will build the graph
        for(int i=0;i<n-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            bool find=false;
            int a=s1.size(),b=s2.size();
            int len=min(a,b);
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    find=true;
                    break;
                }
            }
            if(!find && a>b)return "";
        }
        vector<int>ans=topo(26,adj);
        if(ans.size()!=26)return "";
        string res="";
        for(auto&it:ans){
            if(present[it]){
                res=res+char(it+'a');
            }
        }
        return res;

    }
};
