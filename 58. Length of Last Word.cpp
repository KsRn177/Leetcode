class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int ans = 0;
        bool space = false;
        for ( int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
                space = true;
            else if ( s[i] != ' ' && space)
            {
                ans = 1;
                space = false;
            }
            else if (s[i] != ' ' && !space)
            {
                ans ++;
            }
        }
        return ans;
    }
};
