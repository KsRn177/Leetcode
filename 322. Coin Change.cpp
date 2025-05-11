class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {

        int ans [10001] = {};
        for ( int i = 0; i < 10001; i++)
            ans[i] = 100000;

        for ( int i = 0 ; i < coins.size(); i++)
            if (coins[i] < 10001)
                ans[coins[i]] = 1;
                
        ans[0] = 0;
        
        for ( int i = 1; i <= amount; i++)
        {
            if ( ans[i] == 100000)
            {
                for ( int j = coins.size()-1; j >=0; j--)
                {
                    if ( i > coins[j] && ans[(i - coins[j])]!= -1 &&
                   ans[(i - coins[j])]+1 < ans[i] )

                        ans[i] = ans[(i - coins[j]) ]+ 1; 
                }
            }

        }
        for ( int i = 1; i<= amount; i++)
            cout << ans[i] << " ";

        return (ans[amount] == 100000)? -1:ans[amount];
    }
};
