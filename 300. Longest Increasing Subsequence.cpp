class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {

        vector < int > ans;

        ans.push_back(1);

        int max_ans = 1;

        for ( int i = 1; i < nums.size(); i++)
        {
            int max = 1;
            for ( int j = i-1; j >= 0; j--)
            {
                if ( nums[i] > nums[j] && ans[j] + 1 > max)
                {
                    max = ans[j] + 1;
                }
            }
            ans.push_back(max);
            if ( ans[i] > max_ans)
                max_ans = ans[i];
        }

        
        return max_ans;
    }
};
