class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if(root==NULL)
            return "";

        string ans="";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            TreeNode* node=q.front();
            q.pop();

            if(node==NULL){
                ans+="N,";
                continue;
            }

            ans+=to_string(node->val)+",";

            q.push(node->left);
            q.push(node->right);
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data=="")
            return NULL;

        stringstream ss(data);

        string str;

        getline(ss,str,',');

        TreeNode* root=new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            TreeNode* node=q.front();
            q.pop();

            // Left Child
            getline(ss,str,',');

            if(str!="N"){
                node->left=new TreeNode(stoi(str));
                q.push(node->left);
            }

            // Right Child
            getline(ss,str,',');

            if(str!="N"){
                node->right=new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};