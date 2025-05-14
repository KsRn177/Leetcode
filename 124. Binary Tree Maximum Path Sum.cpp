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
    int Max = -10000;
    int PathSum(TreeNode* root)
    {
        if ( root == nullptr)
                return 0;
        
        int L = max(PathSum(root -> left) ,0);
        int R = max(PathSum(root -> right),0);
        int V = root -> val;

        if( L + R + V > Max)
            Max = L + R + V;
        
        return max( (L+V),(R+V) );

    }
    int maxPathSum(TreeNode* root) 
    {
        PathSum(root);
       return Max;
    }
};
