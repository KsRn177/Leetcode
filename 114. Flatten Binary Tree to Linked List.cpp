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

    vector<TreeNode*>nodes;

    void PreOrder(TreeNode* root)
    {
        if ( root == nullptr )
            return;
        
        nodes.push_back(root);

        PreOrder(root -> left);
        PreOrder(root -> right);

        return;

    }

    void flatten(TreeNode* root)
    {

        PreOrder(root);

        
        
        for ( int i = 1; i < nodes.size(); i++)
        {
            nodes[i-1]->left = nullptr;
            nodes[i-1]->right = nodes[i];
        }
        
    }
};
