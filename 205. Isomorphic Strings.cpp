class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        
        char H_map[1000] = {};
        for ( int i = 0 ; i < 1000; i++)
        {
            H_map[i] = '~';
        }

        for ( int i = 0; i < s.size(); i++)
        {
            if ( H_map[ int(s[i]) ] == '~')
                H_map[ int(s[i]) ] = t[i];
            else if ( H_map[ int(s[i]) ] != t[i])
                return false;
        }
        for ( int i = 0 ; i < 1000; i++)
        {
            H_map[i] = '~';
        }

        for ( int i = 0; i < t.size(); i++)
        {
            if ( H_map[ int(t[i]) ] == '~')
                H_map[ int(t[i]) ] = s[i];
            else if ( H_map[ int(t[i]) ] != s[i])
                return false;
        }
        return true;
        
    }
};
