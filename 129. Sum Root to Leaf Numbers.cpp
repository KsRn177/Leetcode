class Solution {
public:

    int ans = 0;

    void DFS(TreeNode* root, string num)
    {
        cout << num << endl;
        if ( root ==nullptr )
            return;
        if ( root -> right == nullptr && root -> left == nullptr)
        {
            num += to_string(root -> val);
            ans += stoi(num);
            return;
        }
        
        DFS(root -> left, num + to_string(root -> val));
        DFS(root -> right, num + to_string(root -> val));
    }
    int sumNumbers(TreeNode* root) {

        DFS(root,"");
        return ans;
    }
};
