/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void PostOrder(unordered_set<int>&ans,TreeNode* root,int &count,int &size){
    if(root==NULL)return;
    if(ans.find(root->val)!=ans.end())count++;
    size++;
    PostOrder(ans,root->left,count,size);
    PostOrder(ans,root->right,count,size);
}
void GetRes(unordered_set<int>&ans,TreeNode* root,TreeNode* &result,int &curr){
    if(root==NULL)return;
    GetRes(ans,root->left,result,curr);
    GetRes(ans,root->right,result,curr);
    int count=0,value=0;
    PostOrder(ans,root,count,value);
    if(curr>=value&&count==ans.size()){
        result=root;
        curr=value;
    }
}
void Solve(TreeNode* root,unordered_set<int>&ans){
    queue<TreeNode*>Q;
    Q.push(root);
    Q.push(NULL);
    vector<int>res,temp;
    while(!Q.empty()){
        TreeNode* newnode=Q.front();
        Q.pop();
        if(newnode==NULL){
            res=temp;
            temp.clear();
            if(!Q.empty())Q.push(NULL);
        }
        else{
            temp.push_back(newnode->val);
            if(newnode->left)Q.push(newnode->left);
            if(newnode->right)Q.push(newnode->right);
        }
    }
    for(auto it:res)ans.insert(it);
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_set<int>ans;
        Solve(root,ans);
        int curr=INT_MAX;
        TreeNode *Final;
        GetRes(ans,root,Final,curr);
        return Final;
    }
};