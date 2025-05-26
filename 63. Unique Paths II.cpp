class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {


        int ans [101][101] = {};

        ans[0][0] = !obstacleGrid[0][0];

        for ( int i = 1; i < obstacleGrid[0].size(); i++)
        {
            if ( obstacleGrid[0][i] == 0)
                ans[0][i] = ans[0][i-1];
        }
        for ( int i = 1; i < obstacleGrid.size(); i++)
        {
            if ( obstacleGrid[i][0] == 0)
                ans[i][0] = ans[i-1][0];
        }

        for ( int i = 1; i < obstacleGrid.size(); i++)
        {
            for ( int j = 1; j < obstacleGrid[i].size(); j++)
            {
                if ( obstacleGrid[i][j] == 0)
                    ans [i][j] = ans[i-1][j]+ans[i][j-1];
                
            }
        }

        return ans[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
        
    }
};
