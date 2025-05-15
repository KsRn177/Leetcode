class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_map<string,int> map;

        for ( int i = 0; i < wordDict.size(); i++)
        {
            if ( map.find(wordDict[i]) == map.end())
                map[wordDict[i]] = 1;
        }

        bool DP[1000] = {};
        DP[0] = true;
        s = " " + s;
        for ( int i = 1; i < s.size(); i++)
        {
            string temp ="";
            for ( int j = i; j >= 1; j--)
            {
                temp = s[j] + temp;
                if ( map[temp] == 1 && DP[j-1] )
                    DP[i] = true; 
            }
        }

        return DP[s.size()-1];
    }
    
};
