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
class FindElements {
private:
    unordered_map<int,int>mpp;
    void preorder(TreeNode* root){
            mpp[root->val]++;
        if(!root){
            return;
        }
        if(root->left){
            root->left->val = 2* root->val +1;
            preorder(root->left);
        }
        if(root->right){
            root->right->val = 2* root->val +2;
            preorder(root->right);
        }
    }
public:
    FindElements(TreeNode* root) {
        
       if(root){
        root->val = 0;
        preorder(root);
       }
       


    }
    
    bool find(int target) {
        for(auto it: mpp){
            if(mpp.find(target)!=mpp.end()){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */