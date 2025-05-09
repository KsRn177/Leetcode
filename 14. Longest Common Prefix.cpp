class Solution {
public:

    bool _substring ( string a, string b)
    {
        for ( int i = 0; i<b.size(); i++)
        {
            if ( b[i] != a[i])
            return false;
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) 
    {
        string substring = "";
        for ( int i = 0; i < strs[0].size(); i++)
        {
            string temp = substring;
            temp += strs[0][i];
            bool A = true;

            for ( int j = 1; j < strs.size(); j++)
            {
                if ( !_substring(strs[j], temp) )
                {
                    A = false;
                    break;
                }
            }
            if (A)
                substring = temp;
            else
                return substring;
        }
        return substring;
        
    }
};
