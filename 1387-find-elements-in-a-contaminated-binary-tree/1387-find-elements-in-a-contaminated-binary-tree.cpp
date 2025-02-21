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
    unordered_set<int>values;
    void preorder(TreeNode* root, int value){
            
        if(!root){
            return;
        }
        root->val = value;
        values.insert(value);
        if(root->left){
            
            preorder(root->left,2*value +1);
        }
        if(root->right){
            
            preorder(root->right, 2*value + 2);
        }
    }
public:
    FindElements(TreeNode* root) {
        
       
        preorder(root,0);
       
       


    }
    
    bool find(int target) {
    return values.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */