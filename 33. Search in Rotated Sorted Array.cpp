class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int start = 0;
        int end = nums.size()-1;

        while ( start < end)
        {
            int mid = (start+end)/2;
          cout << nums[mid] << endl;

            if( nums[mid] > nums[end])
                start = mid+1;
            else if ( nums[mid] < nums[end])
                end = mid;
            
        }
        cout << start << " -- " << endl;
        int start_l = 0, end_l = start-1;
        while ( start_l <= end_l)
        {
            int mid = (start_l+end_l)/2;
            cout << nums[mid] << endl;
            if( nums[mid] > target)
                end_l = mid -1;
            else if ( nums[mid] < target)
                start_l = mid+1;
            if( nums[mid] == target)
                return mid;
        }
        int start_r = start, end_r = nums.size()-1;
        while ( start_r <= end_r)
        {
            int mid = (start_r+end_r)/2;
            cout << nums[mid] << endl;

            if( nums[mid] > target)
                end_r = mid -1;
            else if ( nums[mid] < target)
                start_r = mid+1;
            if( nums[mid] == target)
                return mid;
        }
         
        return -1;


        
    }
};
