class Solution {
public:
    int rob(vector<int>& nums)
    {
        int ans [101] = {};
        ans[0] = nums[0];

        if ( nums.size() == 1)
            return ans[0];
        if ( nums[1] > nums[0])
            ans [1] = nums[1];
        else 
        ans[1] = nums[0];

        for ( int i = 2 ; i<nums.size(); i++)
        {
            ans[i] = max(ans[i-1], ans[i-2]+nums[i]);
        }
        return ans[nums.size()-1];
        
    }
};
