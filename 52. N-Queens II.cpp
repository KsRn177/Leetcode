class Solution {
public:
    
    int ANS = 0;
    
    bool _isValid(int n, char table[10][10]) {
        // Check each queen's position for conflicts
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (table[i][j] == 'Q') {
                    // Check row
                    for (int k = 0; k < n; k++) {
                        if (k != j && table[i][k] == 'Q') return false;
                    }
                    
                    // Check column
                    for (int k = 0; k < n; k++) {
                        if (k != i && table[k][j] == 'Q') return false;
                    }
                    
                    // Check upper-left diagonal
                    for (int k = i-1, l = j-1; k >= 0 && l >= 0; k--, l--) {
                        if (table[k][l] == 'Q') return false;
                    }
                    
                    // Check upper-right diagonal
                    for (int k = i-1, l = j+1; k >= 0 && l < n; k--, l++) {
                        if (table[k][l] == 'Q') return false;
                    }
                    
                    // Check lower-left diagonal
                    for (int k = i+1, l = j-1; k < n && l >= 0; k++, l--) {
                        if (table[k][l] == 'Q') return false;
                    }
                    
                    // Check lower-right diagonal
                    for (int k = i+1, l = j+1; k < n && l < n; k++, l++) {
                        if (table[k][l] == 'Q') return false;
                    }
                }
            }
        }
        return true;
    }
    
    void print_table(int n,char table[10][10])
    {
        for ( int i = 0; i < n; i++)
        {
            for ( int j = 0; j < n; j++)
            {
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
    }
    void back_track(int i, int n, char table[10][10])
    {
        if (!_isValid(n,table))
        {
            return;
        }
        
        if ( i == n && _isValid(n, table))
        {
            ANS++;
            //print_table(n, table);
            //cout << " ---------- " <<endl;
        }
        
        
        if ( i < n )
        {
            for ( int j = 0; j < n; j++)
            {
                table[i][j] = 'Q';
                back_track(i+1,n,table);
                table[i][j] = '.';
            }
        }
        
    }
    int totalNQueens(int n)
    {
        
        char table[10][10];
        for ( int i = 0; i < 10; i++)
        {
            for ( int j = 0; j < 10; j++)
            {
                table[i][j] = '.';
            }
        }
        
        back_track(0,n,table);
        return ANS;
    }
};
