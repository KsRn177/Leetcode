
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
     unordered_map<int, int> T;

     for ( int i = 0; i < nums.size(); i++)
     {
        if (T.find(nums[i]) == T.end() )
            T.insert({nums[i] , i});

        else if (T.find(nums[i]) != T.end() )
        {
           // cout << T[nums[i]] << " - " << i  <<endl;
            if ( i - T[nums[i]] <= k)
                return true;
            T[nums[i]] = i;
             
        }
     }

     return false;
    }
};
