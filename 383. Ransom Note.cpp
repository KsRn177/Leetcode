class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {

        int check[100] = {};

        for ( int i = 0; i < magazine.size(); i++)
        {
            check[ magazine[i]-'a' ] ++;
        }


        for ( int i = 0; i < ransomNote.size(); i++)
        {
            if (check[ransomNote[i] - 'a'] <= 0)
                return false;
            check[ransomNote[i] - 'a'] --;
        }

        return true;
    }
};
