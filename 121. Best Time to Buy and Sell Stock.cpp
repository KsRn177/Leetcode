class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {

        long long int min = prices[0];
        long long int ans = 0;
        for ( int i = 1 ;i < prices.size(); i++)
        {
            if ( prices[i] - min > ans)
            {
                ans = prices[i] - min;
            }
            if ( prices[i] < min )
            {
                min = prices[i];
            }
        }
        return ans;
        
    }
    
};
