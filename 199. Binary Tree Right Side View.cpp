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
    vector<int> rightSideView(TreeNode* root) 
    {
        queue <TreeNode* > q;
        q.push(root);

        vector < int> ans;
        
        if (!root)  
        return ans;

        while ( !q.empty())
        {
            ans.push_back(q.back()->val);
            int levelSize = q.size();
            for ( int i = 0; i < levelSize; i++)
                {
                    if ( q.front() -> left)
                        q.push(q.front() -> left);
                    if ( q.front() -> right)
                        q.push(q.front() -> right);
                        q.pop();
                }
        } 
        return  ans; 
    }
};
