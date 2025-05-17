class Solution {
public:

    bool mark[201][201];

    void dfs(int i, int j ,vector<vector<char>>& board)
    {
        if (board[i][j] == 'X')
            return;
        if (mark[i][j])
        return;
        
        mark[i][j] = true;

        if (i > 0 && board[i-1][j] == 'O' )
        {
            dfs(i-1,j,board);
        }
        if (i < board.size()-1 && board[i+1][j] == 'O' )
        {
            dfs(i+1,j,board);
        }
        if ( j > 0 && board[i][j-1] == 'O')
        {
            dfs(i,j-1,board);
        }
        if (j < board[i].size()-1 && board[i][j+1] == 'O')
        {
            dfs(i,j+1,board);
        }

        

    }
    void solve(vector<vector<char>>& board) 
    {
        for ( int i = 0; i< board.size(); i++) 
             dfs(i,0,board);

        for ( int j = 0; j< board[0].size(); j++)
             dfs(0,j,board);

        for ( int i = 0; i< board.size(); i++) 
            dfs(i,board[0].size()-1,board);

        for ( int j = 0; j< board[0].size(); j++) 
            dfs(board.size()-1,j,board);
        

        for ( int i =0; i<board.size(); i++)
        {
            for (int j=0; j<board[i].size(); j++)
            {
                if (board[i][j] == 'O' && !mark[i][j])
                    board[i][j] = 'X';
            }
        }

    }
};
