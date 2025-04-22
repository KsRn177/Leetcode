class Solution {
public:
    bool isPalindrome(int x) 
    {
        long long int x_temp = x;

        if ( x < 0)
            return false;

        long long int ans = 0;
        while (x_temp > 0)
        {
            int t = x_temp % 10;
            ans += t;
            x_temp /= 10;
            ans *= 10;
        }
        ans /=10 ;
        if ( ans == x)
            return true;
        return false;
    }
};
