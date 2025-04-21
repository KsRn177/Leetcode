
class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int END = nums.size()-1;
        int START = 0;

        int MID = (START + END)/2;

        while ( START <= END)
        {
           // cout << " mid :" << MID << " end : " << END << " start : " << START << endl;
            if ( target == nums[MID])
            {
                return MID;
            }
            if( target < nums[MID])
            {
                END = MID - 1;
            }
            if ( target > nums[MID])
            {
                START =  MID + 1;
            }
            MID = (START + END)/2;
        }
        return START;
    }
};
