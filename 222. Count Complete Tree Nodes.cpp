class Solution {
public:
    int ans = 0;
    void counter(TreeNode* root)
    {
        if ( root == nullptr)
        {
            return;
        }
        ans ++;
        counter(root -> right);
        counter(root -> left);
    }
    int countNodes(TreeNode* root) {

        counter(root);
        return ans;
        
    }
};
