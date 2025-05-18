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
    TreeNode* retroot(vector<int>preorder, vector<int>inorder) {
        if(preorder.empty() || inorder.empty())
            return nullptr;

        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);

        if(preorder.size() == 1)
            return root;

        vector<int> inorder_left, inorder_right;
        size_t i = 0;
        while(i < inorder.size() && inorder[i] != rootVal) {
            inorder_left.push_back(inorder[i]);
            i++;
        }
        i++; // skip the root
        while(i < inorder.size()) {
            inorder_right.push_back(inorder[i]);
            i++;
        }

     vector<int> preorder_left, preorder_right;
      int j = 1;
        while(j <= inorder_left.size())
        {
            preorder_left.push_back(preorder[j]);
            j++;
        }
        while(j < preorder.size())
        {
            preorder_right.push_back(preorder[j]);
            j++;
        }


        root->left = retroot(preorder_left, inorder_left);
        root->right = retroot(preorder_right, inorder_right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return retroot(preorder, inorder);
    }
};
-------------------------------------------------hash_map solution

class Solution {
private:
    unordered_map<int, int> inorder_map;
    int preorder_index =0;

    TreeNode* buildTreeHelper(vector<int>& preorder, int left, 
    int right) 
    {
        if (left > right) return nullptr;

        int root_val = preorder[preorder_index++];
        TreeNode* root = new TreeNode(root_val);

        int inorder_index = inorder_map[root_val];
        root->left = buildTreeHelper(preorder, left, inorder_index - 1);
        root->right = buildTreeHelper(preorder, inorder_index + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorder_index = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, inorder.size() - 1);
    }
};

