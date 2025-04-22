class Solution {
public:
    int check [300][300] = {};

    int dfs(vector<vector<char>>& grid, int i , int j, int ans)
    {
        check[i][j] = ans;
        if (j > 0 && grid[i][j-1] == '1' && check[i][j-1] == 0)
        {
            dfs(grid,i,j-1,ans);
        }
        if ( j < grid[i].size()-1 && grid[i][j+1] == '1' &&
         check[i][j+1] == 0)
        {
            dfs(grid,i,j+1,ans);
        }
        if ( i > 0 && grid[i-1][j] == '1' && check[i-1][j] == 0)
        {
            dfs(grid,i-1,j,ans);
        }
        if ( i < grid.size()-1 && grid[i+1][j] == '1' && 
        check[i+1][j] == 0)
        {
            dfs(grid,i+1,j,ans);
        }
        return 0;
    }

    int numIslands(vector<vector<char>>& grid) 
    {

        int ans = 0;
        for ( int i = 0; i < grid.size(); i++)
        {
            for ( int j = 0; j < grid[i].size(); j++)
            {
                if ( grid[i][j] == '1' && check[i][j] == 0)
                {
                    ans ++;
                    dfs(grid, i,j,ans);
                }
            }
        }
        return ans;
      
    }
};
