class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int ans[201][201] = {};
        int  n = grid.size() - 1;
        int  m = grid[0].size() - 1;

        ans [0][0] = grid [0][0];

        for ( int i = 1; i <= m; i++)
            ans[0][i] = ans[0][i-1] + grid[0][i];
        
        for ( int i = 1; i <= n; i++)
            ans[i][0] = ans[i-1][0]+grid[i][0];

        
        for ( int i = 1; i <= n; i++)
        {
            for ( int j = 1; j <= m; j++)
            {
                ans[i][j] = min(ans[i-1][j], ans[i][j-1])+ grid[i][j];
            }
        }

        for ( int  i = 0; i <=n; i++)
        {
            for ( int j = 0; j <=m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }

        //cout << ans[0][m] << " - " << grid[0][m] <<endl;

        return ans[n][m];
        
    }
};
