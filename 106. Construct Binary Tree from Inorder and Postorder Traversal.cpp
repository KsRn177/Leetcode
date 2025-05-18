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
    unordered_map<int, int> inorder_map;
    int postorder_index;

    TreeNode* buildTreeHelper(vector<int>& postorder, int left, 
    int right) 
    {
        if (left > right) return nullptr;

        int root_val = postorder[postorder_index--];
        TreeNode* root = new TreeNode(root_val);

        int inorder_index = inorder_map[root_val];
        root->right = buildTreeHelper(postorder, inorder_index +1,right);
        root->left = buildTreeHelper(postorder, left, inorder_index-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        postorder_index = postorder.size()-1;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }
        return buildTreeHelper(postorder, 0, inorder.size() - 1);
        
    }
};
