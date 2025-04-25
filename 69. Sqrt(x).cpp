class Solution {
public:
    int mySqrt(int x) 
    {

        long long int Z = 1;
        while ( Z*Z <= x)
        {
            Z *= 2;
        }

        long long int START = Z/2;
        long long int END = Z;


        while ( START <= END)
        {
            long long int MID = (START+END)/2;
            if ( x == MID*MID )
            {
                return MID;
            }
            if ( x < MID*MID )
            {
                END = MID -1;
            }

            if ( x > MID*MID )
            {
                START = MID + 1;
            }
        }

        return END;

        
    }
};
