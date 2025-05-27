class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector < string > ans;
        if(nums.empty())
            return ans;
        int left = nums[0], right = nums[0];
       
        for ( int i = 1; i < nums.size(); i++)
        {
            if ( nums[i-1]+1 == nums[i])
                right = nums[i];
            else
            {
                if( left != right)
                    ans.push_back(to_string(left)+"->"+to_string(right));
                else 
                    ans.push_back(to_string(left));
                left = nums[i];
                right = nums[i];
            }
        }
        if( left != right)
                    ans.push_back(to_string(left)+"->"+
                    to_string(right));
                else 
                    ans.push_back(to_string(left));


        return ans; 
    }
};
