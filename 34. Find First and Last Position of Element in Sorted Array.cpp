class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size() -1;
        vector <int> ans;

        int S = -1,E = -1;

        while ( start <= end)
        {
            int mid = (start + end)/2;
            if ( target == nums[mid])
            {
                S = mid;
                E = mid;

                
                while ( S > 0 && nums[S-1] == target)
                {
                    S--;
                }
                while (E <nums.size()-1&& nums[E+1] == target)
                {
                    E++;
                }
                break;
                
                
            }
            else if ( target < nums[mid])
            {
                end = mid -1;
            }
            else if ( target > nums[mid])
            {
                start = mid +1;
            }
        }
        ans.push_back(S);
        ans.push_back(E);
        return ans;
    }
};
