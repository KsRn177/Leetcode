class Solution {
public:
    string longestPalindrome(string s) 
    {
        int ans[1001][1001] = {};

        for ( int i = 0; i < s.size(); i++)
        {
            ans[i][i] = 1;


        }

        int MAX = 1;
        int MAX_start = 0;
        int MAX_end = 0;
        for ( int i = 1; i < s.size(); i++)
        {
            for ( int j = 0; j < s.size(); j++)
            {
                if ( i+j >= s.size())
                break;

                if (s[j] == s[j+i] && i == 1)
                    ans[j][j+1] = 2;

                else if ( s[j] == s[j+i] && ans[j+1][j+i-1] != 0 )
                    ans[j][j+i] = ans[j+1][j+i-1] + 2;

                if ( ans[j][j+i] > MAX)
                {
                    MAX = ans[j][j+i];
                    MAX_start = j;
                    MAX_end = j+i;
                }
            }
        }
        cout << MAX << endl;
        cout << MAX_start << endl;
        cout << MAX_end << endl;

        string ANS ="";
        for ( int i = MAX_start; i <= MAX_end; i++)
        {
            ANS +=s[i];
        }
        return ANS;

    }
};
