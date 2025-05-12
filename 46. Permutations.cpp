class Solution {
public:
vector < vector < int>> ans;
    void back_tracking(vector < int> &nums , int mark[10], int size
    ,vector <int> P)
    {
        if ( size == nums.size())
        {
            ans.push_back(P);
            return;
        }
        for ( int i = 0; i < nums.size(); i++)
        {
            if ( mark[i] == 0)
            {
                mark[i] = 1;
                P.push_back(nums[i]);
                back_tracking(nums,mark, size+1,P);
                P.pop_back();
                mark[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        int mark[10] = {};
        vector < int> p;
        back_tracking(nums,mark,0,p);
        return ans;
            
    }
};
