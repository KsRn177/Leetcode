class Solution {
public:

     bool DFS(TreeNode *root, int targetSum, int Sum) 
     {
        if (!root) return false; 

        Sum += root->val;
        
        if (!root->left && !root->right) {
            return Sum == targetSum;
        }

        return DFS(root->left, targetSum, Sum) || DFS(root->right, targetSum, Sum);
    }

    
    bool hasPathSum(TreeNode* root, int targetSum)
    {
       return  DFS(root, targetSum, 0);
    }
};

