
//time :O(k*n) - space :O(1)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        for ( int i = 0; i < k; i++)
        {
            long long last_elemnt = nums[0];
            for ( int j = 1; j < nums.size(); j++)
            {
                int temp;
                temp = nums[j];
                nums[j] = last_elemnt;
                last_elemnt = temp;
            }
            nums[0] = last_elemnt;
        }
    }
};



// time: O(n)  - space O(n)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {


        vector < int > ans = nums;
        for ( int i = 0; i < nums.size(); i++ )
        {
            int index = i+(k % nums.size());
            
            
            if ( index > nums.size() - 1 )
            {
                
                index = index % nums.size();
                ans[index] = nums[i];
            }
            else
            {
                ans[index] = nums[i];
            }
        }
        nums = ans;
        for ( int i = 0; i < nums.size(); i++)
        {
            //cout << nums[i] << " ";
        }
    }
};



