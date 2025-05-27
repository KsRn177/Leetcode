class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int left = 0, right = 0;
        int temp_k = 0;
        int ans = 0;
        while ( right < nums.size())
        {
            if ( temp_k <= k)
            {
                ans = max(ans,right-left);
                if ( nums[right] == 0)
                    temp_k ++;
                right++;
            }
            if ( temp_k > k)
            {
                if ( nums[left] == 0)
                    temp_k --;
                left++;
            }
            
        }
        ans = max(ans,right-left);
        return ans;   
    }
};
