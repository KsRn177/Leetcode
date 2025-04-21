class Solution {
public:
    int climbStairs(int n) 
    {
        int DP[100] = {};
        DP[1] = 1;
        DP[2] = 2;
        for ( int i = 3; i <= n; i++)
        {
            DP[i] = DP[i-1]+DP[i-2];
        }
        return DP[n];
    }
};
