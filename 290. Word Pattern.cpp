class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        unordered_map<char, string> word_counts1;
        unordered_map<string, char> word_counts2;
        int j = 0;
        s+=' ';
        for ( int i = 0; i < s.size(); i++)
        {
            string temp ="";
            while ( s[i] != ' ')
            {
                temp += s[i];
                i++;
            }

            if ( j >= pattern.size())
            return false;

            if (word_counts1.find(pattern[j]) == word_counts1.end())
                word_counts1[pattern[j]] = temp;

            if (word_counts2.find(temp) == word_counts2.end())
                word_counts2[temp] = pattern[j];
            
            if (word_counts1[pattern[j]] != temp || word_counts2[temp] != pattern[j] )
            return false;
            j++;
            
        }
        if ( j != pattern.size())
            return false;
        return true;
    }
};
