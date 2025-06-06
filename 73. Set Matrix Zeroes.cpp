class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        unordered_set<int> row;
        unordered_set<int> columns;

        for ( int i = 0; i<matrix.size(); i++)
        {
            for (int j = 0; j<matrix[i].size(); j++)
            {
                if ( matrix[i][j] == 0)
                {
                    row.insert(i);
                    columns.insert(j);
                }
            }
        }
        
         for ( int i = 0; i<matrix.size(); i++)
        {
            for (int j = 0; j<matrix[i].size(); j++)
            {
                if ( row.find(i) != row.end() || 
                columns.find(j) != columns.end())
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};
