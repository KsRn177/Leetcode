class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
       vector <int> temp;
       temp.push_back(nums[0]);

       for ( int i = 1; i < nums.size(); i++)
       {
            temp.push_back(temp[i-1]+nums[i]);
          // cout << temp[i] << " ,";
       }
       int ans = INT_MAX;

       for ( int i = 0; i < temp.size(); i++)
       {
            int start = i;
            int end = temp.size()-1;
           int mid = (start + end)/2;
            while ( start <= end)
            {
                mid = (start + end)/2;
              // cout << i << " --- " << mid  << " - "<<start << " - " <<  end <<endl;

                if ( target < (temp[mid] - temp[i] + nums[i]) )
                {
                    end = mid -1;
                }
                if ( target > (temp[mid] - temp[i] + nums[i]) )
                {
                    start = mid +1;
                }
                if ( target == (temp[mid] - temp[i] +nums[i]) )
                {
                    start = mid ;
                    break;
                }
            }
           
         //cout << i << " -,- " << mid <<endl;

            if ( (temp[mid] - temp[i] + nums[i] ) >= target && ((mid - i) < ans ))
            {
                ans = mid-i;
                //cout << ans << endl;
             // cout << i << " -- " << mid <<endl;
            }
                

       }
        if ( ans == INT_MAX)
            return 0;
        else
            return ans+1;
    }
};
