class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int max = nums[0];
        int s = 0;
        for ( int i = 0; i < nums.size(); i++)
        {
            if ( nums[i]+s > max)
                max = nums[i]+s;
            if ( nums[i] + s <= 0)
                s = 0;
            if (nums[i]+s > 0)
            s += nums[i];
        }
        return max;
        
    }
};
