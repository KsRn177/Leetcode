class Solution 
{
public:
    TreeNode* Rec(int start, int end, vector<int>& nums)
    {
        if ( start > end)
            return nullptr;
        int mid = (end + start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = Rec(start, mid-1, nums);
        root -> right = Rec(mid+1, end, nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return Rec (0, nums.size()-1 , nums);
        
    }
};
