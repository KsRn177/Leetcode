class Solution {
public:


   int number_of_neighbors(int i, int j, vector<vector<int>>& board) {
        int ans = 0;
        int m = board.size();
        if (m == 0) return 0;
        int n = board[0].size();

        // Check all 8 possible neighbors with bounds checking
        if (i > 0 && j > 0 && board[i-1][j-1] == 1) ans++;
        if (i > 0 && board[i-1][j] == 1) ans++;
        if (i > 0 && j < n - 1 && board[i-1][j+1] == 1) ans++;
        
        if (j > 0 && board[i][j-1] == 1) ans++;
        if (j < n - 1 && board[i][j+1] == 1) ans++;
        
        if (i < m - 1 && j > 0 && board[i+1][j-1] == 1) ans++;
        if (i < m - 1 && board[i+1][j] == 1) ans++;
        if (i < m - 1 && j < n - 1 && board[i+1][j+1] == 1) ans++;

        return ans;
    }

    void gameOfLife(vector<vector<int>>& board)
    {
        vector<vector<int>> temp = board;

        for ( int i = 0; i < board.size(); i++)
        {
            for ( int j = 0; j < board[i].size(); j++)
            {
                int NofN = number_of_neighbors(i,j,board);

                if ( NofN < 2 )
                    temp[i][j] = 0;

                if ( board[i][j] == 1 && NofN > 3 )
                    temp[i][j] = 0;

                if ( board[i][j] == 0 && NofN == 3)
                    temp[i][j] = 1;
                
            }
        }
        board = temp;
    }

};
