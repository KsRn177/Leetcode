class Solution {
public:
    vector<int> ans;

    void helper(vector<vector<int>>& matrix, int start, int M, int N) {
        if (start > M || start > N) {
            return;
        }

        // Traverse from left to right
        for (int i = start; i <= N; i++) {
            ans.push_back(matrix[start][i]);
        }

        // Traverse from top to bottom
        for (int i = start + 1; i <= M; i++) {
            ans.push_back(matrix[i][N]);
        }

        // Traverse from right to left (if start != M to avoid duplicate row)
        if (start != M) {
            for (int i = N - 1; i >= start; i--) {
                ans.push_back(matrix[M][i]);
            }
        }

        // Traverse from bottom to top (if start != N to avoid duplicate column)
        if (start != N) {
            for (int i = M - 1; i > start; i--) {
                ans.push_back(matrix[i][start]);
            }
        }

        helper(matrix, start + 1, M - 1, N - 1);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return ans;
        }
        helper(matrix, 0, matrix.size() - 1, matrix[0].size() - 1);
        return ans;
    }
};
