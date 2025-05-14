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
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector < pair<TreeNode*,int> > q;
        q.push_back({root,0});

        int i = 0;
        while (i < q.size())
        {
            if ( q[i].first -> left != nullptr)
            {
                q.push_back({q[i].first ->left, q[i].second + 1});
            }
            if ( q[i].first -> right != nullptr)
            {
                q.push_back({q[i].first -> right, q[i].second + 1});
            }
            i++;
        }

        vector < double > ans;


        for ( int i = 0; i < q.size(); i++)
        {
            double sum = q[i].first-> val;
            int size = 1;
            while (i < q.size()-1 && q[i].second == q[i+1].second)
            {
                size ++;
                sum += q[i+1].first -> val;
                i++;
            }
            ans.push_back(sum/size);
        }

        return ans;
    }
};
