class Solution {

void start(TreeNode* root,vector<int>&result) //CREATING FUNTION 
{
    if (root == nullptr) {
            return ;
        }
    
    start(root->left,result);
    result.push_back(root->val);
    start(root->right,result);
}
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        

        start(root,result);
        return result;
    }
};