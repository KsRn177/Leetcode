class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        if ( nums.size() == 1)
            return nums[0];
        if ( nums.size() == 2)
            return min(nums[0],nums[1]);
        int start = 0;
        int end = nums.size() -1;
        while (start < end)
        {
            int mid = (start + end) /2;


             if(nums[mid] <= nums[end]) {
                end = mid;
            } else if (nums[mid] > nums[end]) {
                start = mid + 1;
            }
        }
        if ( nums[start] < nums[end])
            return nums[start];
        return nums[end];
    }
};
