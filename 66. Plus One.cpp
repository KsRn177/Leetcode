class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {

        int c = 1;
        vector < int > ans;
        for ( int i = digits.size()-1; i >= 0; i--)
        {
            int temp = digits[i] + c;
            if ( temp == 10)
            {
                c = 1;
                ans.push_back(0);
            }
            else
            {
                c = 0;
                ans.push_back(temp);
            }
        }
        if ( c == 1)
          ans.push_back(1);
        reverse(ans.begin(), ans.end());  
        return ans; 
    }
};
