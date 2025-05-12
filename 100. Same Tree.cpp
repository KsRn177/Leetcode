class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if ( p == nullptr && q == nullptr) return true;
        if ( p == nullptr || q == nullptr) return false;

        return (p ->val == q -> val) && 
        isSameTree(p -> right, q -> right)&& 
        isSameTree(p -> left, q -> left);   
    }
};
