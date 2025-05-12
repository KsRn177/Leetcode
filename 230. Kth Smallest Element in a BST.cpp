class Solution {
public:
    vector < int > list;
    void DFS(TreeNode* root)
    {
        
        if ( root == nullptr)
            return;
        
        DFS(root -> left);
        list.push_back(root -> val);
        DFS(root -> right);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        DFS(root);
        return list[k-1];
    }
};
