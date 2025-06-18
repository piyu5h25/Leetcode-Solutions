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
    bool validBST(TreeNode* root, long long minVal, long long maxVal){
        if(root==nullptr)return true;
        if(root->val<=minVal || root->val>=maxVal)
            return false;

        return validBST(root->left, minVal, root->val) && validBST(root->right , root->val, maxVal);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validBST(root, LLONG_MIN, LLONG_MAX);
    }
};