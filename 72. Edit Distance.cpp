class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int ans [501][501] = {};



        for ( int i = 0; i <= word1.size(); i++)
        {
            ans[i][0] = i;
        }
        for ( int j = 0; j <= word2.size(); j++)
        {
            ans[0][j] = j;
        }

        for ( int i = 0; i < word1.size(); i++)
        {
            for ( int j = 0; j < word2.size(); j++)
            {
                if ( word1[i] == word2[j])
                    ans[i+1][j+1] = ans[i][j];
                else
                {
                    int R = ans[i][j] + 1;
                    int D = ans[i][j+1] + 1;
                    int I = ans[i+1][j] + 1;
                    ans[i+1][j+1] = min( min (R,D), I);
                }
            }
        }
        return ans[word1.size()][word2.size()];   
    }
    
};
