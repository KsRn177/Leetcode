class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int ans [201][201] = {};

        for ( int i = 0; i < triangle.size(); i++)
        {
            for ( int j = 0; j < i; j++)
            {
                ans[i][j] = INT_MAX;
            }
        }

        ans [0][0] = triangle[0][0];

        for ( int i = 1; i < triangle.size(); i++)
        {
            ans[i][0] = ans[i-1][0] + triangle[i][0];
        }

        for ( int i = 1; i < triangle.size(); i++)
        {
            ans[i][i] = ans[i-1][i-1] + triangle[i][i];
        }

        for (int i = 2; i < triangle.size(); i++)
        {
            for ( int j = 1; j <= i-1; j++)
            {
                ans[i][j] = min(ans[i-1][j-1],ans[i-1][j]) + 
                triangle[i][j];
            }
        }

        
        for ( int i = 0; i < triangle.size(); i++)
        {
            for ( int j = 0; j <= i; j++)
            {
                cout << ans[i][j] << " " ;
            }
            cout << endl;
        }

        int min = INT_MAX;

        for ( int i = 0; i < triangle.size(); i++)
        {
            if( ans[triangle.size()-1][i] < min)
                min = ans[triangle.size()-1][i];
            
        }

        return min;

        
    }
};
