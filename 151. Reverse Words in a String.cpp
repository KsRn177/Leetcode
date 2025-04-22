class Solution {
public:
    string reverseWords(string s)
    {   



        vector <string> ans;
        string temp = "";
        bool flag = false;
        for ( int i = 0; i < s.size(); i++)
        {
            if ( s[i] != ' ')
            {
                temp += s[i];
                flag = true;
            }
            
            else if ( flag )
            {
                ans.push_back(temp);
                temp = "";
                flag = false;
            }
        }
        if (flag)
            ans.push_back(temp);
        temp = "";
        for ( int i = ans.size()-1; i >= 1; i--)
        {
            temp += ans[i];
            temp += " ";
        }
        temp  += ans[0];
        return temp;    
    }
};
