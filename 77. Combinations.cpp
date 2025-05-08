
class Solution
{
public:

    vector<vector<int>> ANS;
    
    void rec(int n,int k, int x,vector <int > ans)
    {
        ans.push_back(x);

        if (k == 0)
        {
            ANS.push_back(ans);
            return ;
        }
        for ( int i = x+1; i <=n ; i++)
        {
            rec ( n,k-1,i, ans);
        }
  
        return ;
    }

    vector<vector<int>> combine(int n, int k)
    {
        k--;
        for ( int i = 1; i <= n ; i++)
        {
            vector <int> temp;
            rec(n,k,i,temp);
        }
        return ANS;
    }
};

