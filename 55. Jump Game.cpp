class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        bool table [10000] = {};

        int n = nums.size();
        table[n-1] = true;
        for (  int i = n-2; i >= 0; i--)
        {
            for ( int j = 1; j <= nums[i]; j++)
            {
                if ( table[i+j] == true && (i+j) < n)
                {
                    table[i] = true;
                    break;
                }
            }
        }
        return table[0];
    }
};
