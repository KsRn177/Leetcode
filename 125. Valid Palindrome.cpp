class Solution {
public:
    bool isPalindrome(string s)
    {
        string temp;
        for ( int i = 0; i < s.size(); i++)
        {
            if ( s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <='9')
            {
                temp += s[i];
            }
            if ( s[i] >= 'A' && s[i] <= 'Z')
            {
                temp += ('a'+(s[i] - 'A'));
            }
        }  

        s = temp;
        if ( s.size() == 0)
        return true;


        reverse(temp.begin(), temp.end());
        if ( s == temp)
            return true;
        else
            return false;     
    }
};
