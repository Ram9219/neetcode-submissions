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

class PrefixTree {
public:
Node*root;
int getindex(char ch){
    return ch-'a';
}
    PrefixTree() {
         root=new Node();
    }
    
    void insert(string word) {
        Node*node=root;
        for(char ch:word){
            int i=getindex(ch);
            if(node->child[i]==NULL){
                node->child[i]=new Node();
            }
            node=node->child[i];
        }
        node->isend=true;
    }
    
    bool search(string word) {
        Node*node=root;
        for(char ch:word){
            int i=getindex(ch);
            if(node->child[i]==NULL){
                return false;
            }
            node=node->child[i];
        }
        return node->isend;
    }
    
    bool startsWith(string word) {
        Node*node=root;
        for(char ch:word){
            int i=getindex(ch);
            if(node->child[i]==NULL){
                return false;
            }
            node=node->child[i];
        }
        return true;
    }
};
