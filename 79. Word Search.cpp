class Solution {
public:
bool ans = false;

bool is_substring(string a, string b)
{
    for ( int i = 0 ; i <a.size(); i++)
    {
        if( a[i] != b[i])
        return false;
    }
    return true;
}


bool back_tracking(vector<vector<char>>& board, int i,
 int j,string word , string T, int mark[10][10])
 {
    
     if ( i < 0 || j < 0 || i >= board.size() || j >=board[i].size() )
     {
         mark[i][j] = 0;
         return false;
     }
     
    mark[i][j] = 1;
    T += board[i][j];

    if ( !is_substring(T,word))
    {
        mark[i][j] = 0;
        return false;
    }
     
    if ( T == word)
    {
         mark[i][j] = 0;
         ans = true;
         return true;
    }
     
    if ( T.size () > word.size())
     {
         mark[i][j] = 0;
     
         return false;
     }
     
     
     
   
    
     if ( i > 0 && mark[i-1][j] == 0)
     {
         back_tracking(board, i-1,j,word,T,mark);
     }
     if ( i < board.size() && mark[i+1][j] == 0)
     {
         back_tracking(board, i+1,j,word,T,mark);
     }
     if ( j > 0 && mark[i][j-1] == 0)
     {
         back_tracking(board, i,j-1,word,T,mark);
     }
     if ( j < board[i].size() && mark[i][j+1] == 0)
     {
         back_tracking(board, i,j+1,word,T,mark);
     }
     mark[i][j] = 0;
     return false;


 }

    
    bool exist(vector<vector<char>>& board, string word) 
    {
        int mark[10][10] = {};
        for ( int i = 0; i < board.size(); i++)
        {
            for ( int j = 0; j < board[i].size(); j++)
            {
               
                back_tracking(board, i, j, word, "", mark);
                if(ans)
                return true;
            }
        }

        return ans;
    }
};
