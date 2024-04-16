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
    TreeNode *getTaskDone(TreeNode *root, int val, int cur, int depth) {
        if(depth == 1) {
            // create new node, attach root node to its left, and return
            TreeNode *newNode = new TreeNode(val, root, nullptr);
            return newNode;
        }
        if(cur == depth - 1 && root) {
            // stopping at depth - 1 state
            // set the left node (with left subtree in left)
            TreeNode *left = new TreeNode(val, root->left, nullptr);
            // set the right node (with right subtree in right)
            TreeNode *right = new TreeNode(val, nullptr, root->right);
            
            // attach to current node's left and right 
            root->left = left;
            root->right = right;
            // return 
            return root;
        }
        if(root->left)
            getTaskDone(root->left, val, cur + 1, depth);
        if(root->right) 
            getTaskDone(root->right, val, cur + 1, depth);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return getTaskDone(root, val, 1, depth);
        
    }
};