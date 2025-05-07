class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> charSet;
        int left = 0;
        int maxLength = 0;
        
        for (int right = 0; right < s.size(); ++right) {
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                ++left;
            }
            charSet.insert(s[right]);
            maxLength = std::max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
