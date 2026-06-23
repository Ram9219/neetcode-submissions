class Node{
    public:
    Node*child[26];
    bool isend;
    Node(){
        isend=false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};
class Trie{
    public:
    Node*root;
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node*node=root;
        for(char ch:word){
            int i=ch-'a';
            if(node->child[i]==NULL){
                node->child[i]=new Node();
            }
            node=node->child[i];
        }
        node->isend=true;
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie t;
        int n=s.size();
        for(auto &word:wordDict){
            t.insert(word);
        }
        vector<bool>dp(n+1,false);
        dp[0] = true;

        for(int i=0;i<n;i++){
            if(!dp[i]) continue;
            Node*node=t.root;
            for(int j=i;j<n;j++){
                int index=s[j]-'a';
                if(node->child[index]==NULL) break;
                node=node->child[index];
                if(node->isend){
                    dp[j+1]=true;
                }
            }
        }
        return dp[n];
    }
};