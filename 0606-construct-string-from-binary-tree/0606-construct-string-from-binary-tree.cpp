class Solution {
public:
    void preOrderTraversal(TreeNode* root,string &str)
    {
        if(root==NULL)
            return;
        if(!str.empty())
            str.push_back('(');
        str+=to_string(root->val);
        
        if(root->left==NULL&&root->right!=NULL)
        {
            string temp="()";
            str=str+temp;
        }
        preOrderTraversal(root->left,str);
        preOrderTraversal(root->right,str);
        if(!str.empty())
            str.push_back(')');
    }
    string tree2str(TreeNode* root) {
        string str;
        preOrderTraversal(root,str);
        if(!str.empty())
            str.pop_back();
        return str;
    }
};