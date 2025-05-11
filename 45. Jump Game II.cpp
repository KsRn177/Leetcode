class Solution {
public:
    int jump(vector<int>& nums) 
    {

        int ans [100001] = {};
        for ( int i = 0; i < nums.size() ; i++)
        {
            ans[i] = INT_MAX;
        }

        ans [0] = 0;

        for ( int  i = 0; i < nums.size(); i++)
        {
            int temp = nums[i];
            while ( temp > 0)
            {
                if ( ans[i] + 1 < ans[ i + temp ])
                    ans[ i + temp ] = ans[i] + 1;
                temp --;
            }
        }

        return ans[ nums.size() - 1 ]; 
        
    }
};
