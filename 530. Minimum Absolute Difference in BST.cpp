/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> T;
    int build_arry(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        build_arry(root->left);
        T.push_back(root->val);
        build_arry(root->right);
        return 0;
    }
    int getMinimumDifference(TreeNode* root) {
        T.clear(); // Clear the vector before building the array
        build_arry(root);
        int ans = INT_MAX;
        for (int i = 1; i < T.size(); i++) {
            //cout << T[i] << ". ";
            if ((T[i] - T[i-1]) < ans && T[i] != -1 && T[i-1] != -1) {
                ans = (T[i] - T[i-1]);
            }
        }
        return ans;
    }
};
