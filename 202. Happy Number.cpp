class Solution {
public:
    bool isHappy(int n) 
    {
        unordered_map <int,int> mymap;

        while (true)
        {
            long long t = n;
            int d = 0;

            while ( n > 0)
            {
                d+= (n % 10)*(n % 10);
                n /= 10;
            }

            if ( d == 1)
                return true;
            if ( mymap.find(d) == mymap.end())
            {
                mymap[d] = t;
            }
            else if ( mymap.find(d) != mymap.end())
            {
                return false;
            }
            n = d;
        }
        return false;
        
    }
};
