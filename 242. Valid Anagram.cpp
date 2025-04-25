class Solution {
public:
    bool isAnagram(string s, string t)
    {
        int s_t[1000] = {};
        int t_T[1000] = {};

        for ( int i = 0; i < s.size(); i++)
        {
            int temp = s[i]-'a';
            s_t[temp] ++;
        }  
        for ( int i = 0; i < t.size(); i++)
        {
            int temp = t[i]-'a';
            t_T[temp] ++;
        } 


        for ( int i = 0; i < 1000; i++)
        {
            if ( s_t[i] != t_T[i])
            return false;
        }  
        return true; 
    }
};
