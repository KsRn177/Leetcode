class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int start_c = 0;
        int end_c = matrix.size()-1;

        while ( start_c <= end_c)
        {
            int mid = (start_c+end_c)/2;

            if ( matrix[mid][0] == target)
                return true;
            if ( matrix[mid][0] < target)
                start_c = mid+1;
            else
                end_c = mid-1;
        }
         if (end_c < 0) {
            return false;
        }

        int start_r = 0;
        int end_r = matrix[end_c].size()-1;

        while ( start_r <= end_r)
        {
            int mid = (start_r+end_r)/2;
            if ( matrix[end_c][mid] == target)
                return true;

            if ( matrix[end_c][mid] < target)
                start_r = mid+1;
            else
                end_r = mid-1;
        }

        return false;
        
    }
};
