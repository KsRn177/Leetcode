class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector < int > ans;
        int left = 0;
        int right = numbers.size()-1;

        while ( left < right)
        {
            if ( numbers[left] + numbers[right]  == target )
            {
                ans.push_back(left+1);
                ans.push_back(right+1);
                break;
            }
            if ( numbers[left] + numbers[right]  > target )
            {
                right --;
            }
            if ( numbers[left] + numbers[right]  < target )
            {
                left ++;
            }
        }
        return ans;
    }
};
