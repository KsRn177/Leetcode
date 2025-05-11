
class Solution {
public:
    
    vector<vector<int>> finalAns;
    
    
    void print(vector <int> & ans)
    {
        for ( int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    
    void backtrack(int i, int target, vector<int>& candidates, int sum,
                   vector < int> ans)
    {
        

        if ( sum > target)
            return;
        
        
        if ( sum == target)
        {
            //print (ans);
            //cout << endl;
            finalAns.push_back(ans);
            return;
        }
        
        
        for ( int j = i; j < candidates.size(); j++)
        {

            ans.push_back(candidates[j]);
            
            backtrack(j,target,candidates,sum+candidates[j], ans);

            ans.pop_back();
        }
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector <int>ans;
        backtrack(0,target,candidates,0,ans);
        return finalAns;
    }
};


