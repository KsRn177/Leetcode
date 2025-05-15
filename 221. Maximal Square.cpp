class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int ANS = 0;

        int ans [301][301] = {};

        for ( int i = 0; i < matrix.size(); i++)
            if ( matrix[i][0] == '1')
            {
                ans[i][0] = 1;
                if ( ans[i][0] > ANS)
                    ANS = ans[i][0];
            }
        
        for ( int j = 0; j < matrix[0].size(); j++)
            if( matrix[0][j] == '1')
            {
                ans[0][j] = 1;
                if ( ans[0][j] > ANS)
                    ANS = ans[0][j];
            }
        
        for ( int i = 1; i < matrix.size(); i++)
        {
            for ( int j = 1; j < matrix[i].size(); j++)
            {
                if( matrix[i][j] == '1')
                {
                    int Q = ans[i-1][j-1];
                    int P = ans[i-1][j];
                    int Z = ans[i][j-1];

                    ans[i][j] = min (min(Q,P),Z)+1;
                }
                if ( ans[i][j] > ANS)
                    ANS = ans[i][j];
            }
        }

        return ANS*ANS;

        
    }
};
