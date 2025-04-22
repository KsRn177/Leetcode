class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {

    unordered_map<int, int> seen; // Stores {value: index}
    
    for (int i = 0; i < nums.size(); ++i)
    {
        int complement = target - nums[i];
        
        if (seen.find(complement) != seen.end()) {
            return {seen[complement], i};
        }
        
        seen[nums[i]] = i; // Store current number and its index
    }
    
    return {};  
        
    }
};
