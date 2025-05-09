class Solution {
public:
    vector < string > Finalans;
    void back_track(int n, int open_p, int close_p,string ans)
    {
        if ( open_p > n || close_p > n)
            return; 
        if ( open_p == n && close_p == n)
            Finalans.push_back(ans);
        
        if ( close_p > open_p)
            return;

        else
        {
            back_track(n , open_p+1 , close_p , ans+ '(' );
            back_track(n, open_p, close_p+1 , ans + ')' );
        }


    }
    vector<string> generateParenthesis(int n) {
        
        back_track(n,0,0,"");
        return Finalans;
        
    }
};
