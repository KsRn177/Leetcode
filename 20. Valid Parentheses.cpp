class Solution {
public:
    bool isValid(string s) 
    {
        stack <char> ans;
        ans.push('$');
       for ( int i = 0; i < s.size(); i++)
       {
            if( s[i] == '('||s[i] == '[' || s[i] == '{')
            ans.push(s[i]);

            if ( s[i] == ')')
            {
                if ( ans.top() == '(')
                {
                    ans.pop();
                }
                else
                return false;
            }
            if ( s[i] == ']')
            {
                if ( ans.top() == '[')
                {
                    ans.pop();
                }
                else
                return false;
            }
            if ( s[i] == '}')
            {
                if ( ans.top() == '{')
                {
                    ans.pop();
                }
                else
                return false;
            }
       } 
       if(ans.top() == '$')
            return true;
        return false;
    }
};
