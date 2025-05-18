class Solution {
public:
    int five= 0;

    void X(int x)
    {
        if ( x%5 != 0) return;
     
        five ++;
        X(x/5);
    }
    int trailingZeroes(int n) 
    {
         for ( int i = 5; i <=n ; i+=5) {
            X(i);
        }

        return five;  
    }
};
