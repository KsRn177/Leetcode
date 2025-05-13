/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector <TreeNode*> P;
    vector <TreeNode*> Q;

    void DFS(TreeNode* root, TreeNode* p, TreeNode* q,vector <TreeNode*> &move)
    {
        if ( root == nullptr)
            return;
        
        move.push_back(root);
        
        if ( root == p) P = move;
        if ( root == q) Q = move;

        DFS(root -> left, p,q,move);
        DFS(root -> right,p,q,move);
        move.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector <TreeNode*> move;

        DFS(root,p,q,move);

        TreeNode* temp;
        for ( int i = 0; i < min (Q.size(),P.size()); i++)
        {
            temp = P[i];
            if (P[i] -> val != Q[i] -> val)
            {
                return P[i-1];
            }
        }

        return temp;
    }
};
